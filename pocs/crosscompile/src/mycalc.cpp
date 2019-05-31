#include "mycalc.hpp"

namespace myapp
{
  MyCalc::MyCalc(){
  }

  int MyCalc::plus(int a, int b)
  {
    return a + b;
  }

  int MyCalc::minus(int a, int b)
  {
    return a - b;
  }

  int MyCalc::div(int a, int b)
  {
    return a / b;
  }

  int MyCalc::mult(int a, int b)
  {
    return a * b;
  }
}
