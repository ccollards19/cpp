#include "RPN.hpp"

void add(std::stack<int> &operand)
{
  int tmp = operand.top();
  operand.pop();
  tmp = operand.top() + tmp;
  operand.pop();
  operand.push(tmp);
}

void substract(std::stack<int> &operand)
{
  int tmp = operand.top();
  operand.pop();
  tmp = operand.top() - tmp;
  operand.pop();
  operand.push(tmp);
}

void multiply(std::stack<int> &operand)
{
  int tmp = operand.top();
  operand.pop();
  tmp = operand.top() * tmp;
  operand.pop();
  operand.push(tmp);
}

void divide(std::stack<int> &operand)
{
  int tmp = operand.top();
  operand.pop();
  tmp = operand.top() / tmp;
  operand.pop();
  operand.push(tmp);
}
