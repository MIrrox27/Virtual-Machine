// author github.com/MIrrox27/Virtual-Machine
// src/assembler.cpp


#include <iostream>
#include <fstream>
#include <filesystem> 
#include <vector>
#include <iterator>
#include <sstream>

#include "console.hpp"

namespace fs = std::filesystem;

  // Получение бинарной информации из файла
std::vector<int> get(std::string path) {
  //std::cout << "Open " << path << std::endl;

  std::ifstream file(path, std::ios::binary);
  if (!file.is_open()) {
    file.close();
    std::cerr << "Invalid path: " << path << std::endl;
    return {};
  }
  
  std::vector<int> binary_buffer {std::istream_iterator<int>(file),
  std::istream_iterator<int>()};
  file.close();
    
    return binary_buffer;
  
}


std::string assembly(std::string path){

  fs::path pathF = path;
  pathF.replace_extension(".axb");

  std::vector<int> command_opcodes = parse_code(get_code(path));
  std::ofstream file(pathF, std::ios::binary);

  for (int value : command_opcodes){
    file.write(reinterpret_cast<char*>(&value), sizeof(value));
  }
  return pathF.string();
}
void execute(std::vector<int> bytes){};