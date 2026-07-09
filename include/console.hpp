// author github.com/MIrrox27/Virtual-Machine
// include/console.hpp

#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <string>
#include <map>

enum OpCodes {
  ERR = -1, // код ошибки
  HALT = 0, //  выход из программы
  START = 1, 

  ADD = 2, // сложение 
  SUB = 3, // вычитание

  MUL = 4, // умножение
  DIV = 5, // деление 
  MOD = 6, // остаток от деления 

  POW = 7, // степень
  SQRT = 8, // корень 

  JUMP = 9, // безусловный переход на новый ip
  JIF = 10, // переход на переданный ip, если последний эл стека не 0

  PRINT = 11, // вывод последнего элемента в стеке в консоль
  PUSH = 12, // добавить эелемент в стек

  CMP_EQ = 13, // переход на новый ip ессли 2 верхних эл равны
  CMP_LT = 14, // переход на новый ip ессли старший эл меньше сл эл
  CMP_GT = 15  // переход на новый ip ессли старший эл больше сл эл

};


/*
std::string args[] = {
    "-r", // запуск, с первой командой из файла
    "-e", // запуск, после завершения выполнения, программа 
  };
*/

std::vector<int> parse_code(std::string command);
bool is_number(const std::string& str);
std::string get_code(std::string path);



#endif