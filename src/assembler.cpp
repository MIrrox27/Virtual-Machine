// author github.com/MIrrox27/Virtual-Machine
// src/assembler.cpp


#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

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
