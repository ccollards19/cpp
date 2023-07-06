#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <ctime>

struct tm_comparer
{
  bool operator () (const std::tm & t1, const std::tm & t2) const
  {         
      return (t1.tm_year <  t2.tm_year ||
             (t1.tm_year == t2.tm_year && t1.tm_mon <  t2.tm_mon) || 
             (t1.tm_year == t2.tm_year && t1.tm_mon == t2.tm_mon && t1.tm_mday < t2.tm_mday));
  }
};


int get_data(std::map<std::tm, float, tm_comparer> &data);
int btc_x(std::map<std::tm, float, tm_comparer> &data, std::ifstream &input);
