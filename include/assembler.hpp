// author github.com/MIrrox27/Virtual-Machine
// include/assembler.hpp

#ifndef ASSEMBLER_HPP
#define ASSEMBLER_HPP

#include <vector>
#include <string>

std::vector<int> get(std::string path); // получение байт из файла 
void assembly(); // если расширение не .axn то пересобирает в новый исполняемый файл с числами
void execute(); // выполнить код (передаются байты)

#endif