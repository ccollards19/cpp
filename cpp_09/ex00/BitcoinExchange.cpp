#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cctype>
#include <ctime>
#include <iostream>
#include <sstream>

int get_data(std::map<std::tm, float, tm_comparer> &data)
{
  std::ifstream file;
  file.open("data.csv");
  if (!file.good())
    return (0);
  
  while(file.good())
  {
    std::tm key;
    float value;
    std::string buffer;
    if (!getline(file, buffer, '-'))
      break;
    key.tm_year = std::atoi(buffer.c_str()) - 1900;
    buffer.clear();
    if (!getline(file, buffer, '-'))
      break;
    key.tm_mon = std::atoi(buffer.c_str()) - 1;
    buffer.clear();
    if (!getline(file, buffer, ','))
      break;
    key.tm_mday = std::atoi(buffer.c_str()) - 1;
    buffer.clear();
    if (!getline(file, buffer))
      break;
    value = std::atof(buffer.c_str());
    data[key] = value;
  }
  if (file.eof())
  {
    file.close();
    return (1);
  }
  return (0);
}

short isValidDate(int dd, int mm, int yy)
{
    if (yy < 0)
        return 1;

    if (mm < 0 || mm > 12)
        return 1;

    if (mm == 2) {
        if (yy % 4 == 0) {
            if (dd > 29 || dd < 0)
                return 1;
        }
        else {
            if (dd > 28 || dd < 0)
                return 1;
        }
    }
    else if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
        if (dd > 31 || dd < 0)
            return 1;
    }
    else {
        if (dd > 30 || dd < 0)
            return 1;
    }

    return 0;
}

int get_year(std::stringstream &line)
{
  std::string buffer;
  if (!getline(line, buffer, '-'))
    return -1;
  int size = buffer.size();
  if (size != 4)
  {
    std::cout << "Error: bad input " << std::endl;
    return -1;
  }
  for (int i = 0; i < size; i++)
  {
    if (!std::isdigit(buffer[i]))
    {
      std::cout << "Error: bad input " << std::endl;
      return -1;
    }
  }
  return (std::atoi(buffer.c_str()) - 1900);
}

int get_mon(std::stringstream &line)
{
  std::string buffer;
  if (!getline(line, buffer, '-'))
    return -1;
  int size = buffer.size();
  if (size != 2)
  {
    std::cout << "Error: bad input " << std::endl;
    return -1;
  }
  for (int i = 0; i < size; i++)
  {
    if (!std::isdigit(buffer[i]))
    {
      std::cout << "Error: bad input " << std::endl;
      return -1;
    }
  }
  return (std::atoi(buffer.c_str()) - 1);
}

int get_day(std::stringstream &line)
{
  std::string buffer;
  if (!getline(line, buffer, '|'))
    return -1;
  int size = buffer.size();
  if (size != 3)
  {
    std::cout << "Error: bad input " << std::endl;
    return -1;
  }
  for (int i = 0; i < size - 1; i++)
  {
    if (!std::isdigit(buffer[i]))
    {
      std::cout << "Error: bad input " << std::endl;
      return -1;
    }
  }
  if (buffer[2] != ' ')
  {
    std::cout << "Error: bad input " << std::endl;
    return -1;
  }
  return (std::atoi(buffer.c_str()) - 1);
}

float get_value(std::stringstream &line)
{
  std::string buffer;
  int dotflag = 0;
  if (!getline(line, buffer))
    return -1;
  if (buffer[0] != ' ')
  {
    std::cout << "Error: bad input " << std::endl;
    return -1;
  }
  for (unsigned long i = 1; i < buffer.size(); i++)
  {
    if ((buffer[i] == '.' && !dotflag))
      dotflag = 1;
    else if (!std::isdigit(buffer[i]))
    {
      std::cout << "Error: bad input " << std::endl;
      return -1;
    }
  }
  float value = std::atof(buffer.c_str());
  if (value > 1000)
  {
    std::cout << "Error: too big a number." << std::endl;
    return -1;
  }
  if (value < 0)
  {
    std::cout << "Error: not a positive number." << std::endl;
    return -1;
  }
  return value;
}


int btc_x(std::map<std::tm, float, tm_comparer> &data, std::ifstream &input)
{
  std::string buffer;
  getline(input, buffer);
  buffer.clear();
  while(input.good())
  {
    std::stringstream line;
    if (!getline(input, buffer))
      break;
    line << buffer;
    buffer.clear();
    std::tm key;
    float value;

    if ((key.tm_year = get_year(line)) == -1)
      continue ;
    if ((key.tm_mon =  get_mon(line)) == -1)
      continue ;
    if ((key.tm_mday = get_day(line)) == -1)
      continue ;
    if (isValidDate(key.tm_mday ,key.tm_mon, key.tm_year))
    {
      std::cout << "Error: bad input " << std::endl;
      continue ;
    }
    if ((value = get_value(line)) == -1)
      continue ;
    if (data.find(key) == data.end())
    {
      std::map<std::tm, float, tm_comparer>::iterator it = data.lower_bound(key);
      if (it != data.begin())
        it--;
      key = it->first;
    }
    std::cout<<"["
      <<key.tm_year + 1900
      <<"-"
      <<key.tm_mon + 1
      <<"-"
      <<key.tm_mday + 1
      <<"]--"<<"--["
      <<(data[key] * value)
      <<"]"
      <<std::endl;
  }
  if (input.eof())
  {
    input.close();
    return (1);
  }
  return (0);
}
