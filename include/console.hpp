// author github.com/MIrrox27/Virtual-Machine
// include/console.hpp

#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <string>
#include <map>

enum OpCodes {
  ERR = -1,
  HALT = 0,
  PUSH = 1,
  ADD = 2,
  SUB = 3,
  MUL = 4,
  DIV = 5,
  MOD = 6,
  POW = 7,
  SQRT = 8,
  JUMP = 9,
  JIF = 10,
  PRINT = 11
};






std::vector<int> cin_parser(std::string command);
bool is_number(const std::string& str);



#endif