// author github.com/MIrrox27/Virtual-Machine
// src/console.cpp

#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <cctype>
#include <charconv>
#include <iostream>
#include <fstream>

#include "console.hpp"

bool is_number(const std::string& str) {
    double val;
    auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), val);
    // true, если парсинг прошел успешно и вся строка была прочитана
    return ec == std::errc() && ptr == str.data() + str.size();
}

std::map<std::string, OpCodes> StringCommands = {
  {"HALT", HALT},
  {"PUSH", PUSH},
  {"ADD", ADD},
  {"SUB", SUB},
  {"MUL", MUL},
  {"DIV", DIV},
  {"MOD", MOD},
  {"POW", POW},
  {"SQRT", SQRT},
  {"JUMP", JUMP},
  {"JIF", JIF},
  {"PRINT", PRINT}
};

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

std::string get_code(std::string path){
  std::ifstream file(path);

  if (!file.is_open()){
    std::cerr << "Invalid path: " << path << std::endl;
    return {};
  }

  std::string line;
  std::string buffer;

  while (std::getline(file, line))
    buffer += (" " + line); // перевожу весь файл в одну строку для выполнения 
  
  file.close();
  return buffer;
}
