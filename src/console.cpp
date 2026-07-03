// author github.com/MIrrox27/Virtual-Machine
// src/console.cpp

#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>

#include "console.hpp"

bool is_number(const std::string& str){
  if (str.empty()) return false;
  return std::all_of(str.begin(), str.end(), [](unsigned char c){
    return std::isdigit(c);
  });

}


// функция для обработки полной команды, пример: PUSH 10 PUSH 20 ADD PUSH 5 SUB PRINT HALT
std::vector<int> cin_parser(std::string full_command){ 
  std::stringstream ss(full_command);
  std::string command;
  std::vector<int> full_command_vec;

  while (ss >> command) {
    if (is_number(command)) full_command_vec.push_back(std::stoi(command));
    else if (StringCommands.count(command) > 0) 
      full_command_vec.push_back(StringCommands[command]);

    else {
      std::vector<int> err;
      err.push_back(ERR);
      return err;
    }
    
  }

  return full_command_vec;
}