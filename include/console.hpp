// author github.com/MIrrox27/Virtual-Machine
// include/console.hpp

#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <string>
#include <map>

enum OpCodes {
  ERR = -1, // код ошибки
  HALT = 0, //  выход из программы
  PUSH = 1, // добавить эелемент в стек
  ADD = 2, // сложение 
  SUB = 3, // вычитание
  MUL = 4, // умножение
  DIV = 5, // деление 
  MOD = 6, // остаток от деления 
  POW = 7, // степень
  SQRT = 8, // корень 
  JUMP = 9, // безусловный переход на новый ip
  JIF = 10, // переход на переданный ip, если последний эл стека не 0
  PRINT = 11 // вывод последнего элемента в стеке в консоль
};






std::vector<int> cin_parser(std::string command);
bool is_number(const std::string& str);



#endif