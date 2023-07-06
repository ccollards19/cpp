#include "RPN.hpp"

int main(int ac, char ** av)
{
  if (ac != 2)
  {
    std::cout<<"Error : wrong number of arguments"<<std::endl;
    return (1);
  }
  int size = std::strlen(av[1]);
  if (size == 0)
  {
      std::cout<<"Error"<<std::endl;
      return (1);
  }

  int i = 0;
  std::stack<int> operand;
  while (av[1][i] && av[1][i] == ' ')
    i++;
  while(av[1][i])
  {
    //std::cout<<"["<<av[1][i]<<"]-->"<<operand.size()<<std::endl;
    if (std::isdigit(av[1][i]))
      operand.push((int)(av[1][i] - '0'));
    else if (av[1][i] == ' ')
        ;
    else if (av[1][i] == '-' && operand.size() > 1)
      substract(operand);
    else if (av[1][i] == '+' && operand.size() > 1)
      add(operand);
    else if (av[1][i] == '*' && operand.size() > 1)
      multiply(operand);
    else if (av[1][i] == '/' && operand.size() > 1)
      divide(operand);
    else 
    {
      std::cout<<"Error"<<std::endl;
      return (1);
    }
    i++;
  }
  if (operand.size() != 1)
  {
      std::cout<<"Error"<<std::endl;
      return (1);
  }
  std::cout<<operand.top()<<std::endl;
  return (0);
}
