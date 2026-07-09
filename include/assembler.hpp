// author github.com/MIrrox27/Virtual-Machine
// include/assembler.hpp

#ifndef ASSEMBLER_HPP
#define ASSEMBLER_HPP

#include <vector>
#include <string>

std::vector<int> get(std::string path); // получение байт из файла 
std::string assembly(std::string path); // если расширение не .axb то создает новый файл с числами в той же папке, вернет путь к файлу
void execute(std::vector<int> bytes); // выполнить код (передаются байты)

#endif