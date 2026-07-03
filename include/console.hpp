// author github.com/MIrrox27/Virtual-Machine
// include/console.hpp

#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <string>

enum OpCodes {
  HALT = 0,
  PUSH = 1,
  ADD = 2,
  SUB = 3,
  PRINT = 4
};

OpCodes cin_parser(std::string command);




#endif