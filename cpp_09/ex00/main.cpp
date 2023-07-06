#include "BitcoinExchange.hpp"

// inline void print_data(std::map<std::tm, float, tm_comparer> &data)
// {
//   std::tm key;
//   float value;
//   std::map<std::tm, float, tm_comparer>::iterator it;
//   for (it = data.begin(); it != data.end(); ++it)
//   {
//     key = it->first;
//     value = it->second;
//     std::cout
//       <<"["
//       <<key.tm_year + 1900
//       <<"-"
//       <<key.tm_mon + 1
//       <<"-"
//       <<key.tm_mday + 1
//       <<"]--"<<"--["
//       <<value //* value
//       <<"]"
//       <<std::endl;
//   }
// }

int main(int argc, char** argv)
{

  if (argc > 2)
  {
    std::cerr<<"wrong number of arguments"<<std::endl;
    return (1);
  }
  
  std::ifstream input;
  input.open(argv[1]);
  if (!input.good())
  {
    std::cerr<<"failed to open input"<<std::endl;
    return (1);
  }

  std::map<std::tm, float, tm_comparer> data;
  if (!get_data(data))
  {
    std::cerr<<"failed to retrieve database"<<std::endl;
    return (1);
  }
  // print_data(data); 
  if (!btc_x(data, input))
  { 
    std::cerr<<"an error occured during execution"<<std::endl;
    return (1);
  }
  return(0);
}
