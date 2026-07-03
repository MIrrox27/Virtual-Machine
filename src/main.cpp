// author github.com/MIrrox27/Virtual-Machine
// src/main.cpp

#include <iostream>
#include <vector>
#include <string>
#include "console.hpp"


int stack[256];
int sp = -1;



int main(){
  std::string str_command;
  std::cout << "> ";
  std::cin >> str_command;
  std::vector<int> program = cin_parser(str_command);

  int ip = 0;
  bool running = true;

  while (running){
    int opcode = program[ip]; // команда, которая выполняется сейчас

    switch (opcode){
      case PUSH:
        ip++;
        stack[++sp] = program[ip]; 
        break;

      case ADD:
        int arg1 = stack[--sp];
        int arg2 = stack[--sp];
        stack[++sp] = arg1 + arg2;
        break;

      case SUB:
        int arg1 = stack[--sp];
        int arg2 = stack[--sp];
        stack[++sp] = arg1 - arg2;
        break;
      
      case PRINT:
        int arg = stack[--sp];
        std::cout << arg << std::endl;
        break;
      
      case HALT:
        running = false;
        break;
      
      default:
        break;
    }
    ip++; 

  }
  



  return 0;
} 