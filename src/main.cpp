// author github.com/MIrrox27/Virtual-Machine
// src/main.cpp

#include <iostream>
#include <vector>
#include <string>
#include "console.hpp"




int main(){
  int ip = 0;
  bool running = true;

  while (running){
    std::string str_command;
    std::cout << "> ";
    std::getline(std::cin, str_command);
    std::vector<int> program = cin_parser(str_command);

    int stack[1024];
    stack[0] = NULL;
    int sp = 0;
    ip = 0;

    while (ip < program.size()){
      int opcode = program[ip]; // команда, которая выполняется сейчас

      switch (opcode){
        case HALT:
          running = false;
          break;

        case PUSH:
          ip++;
          stack[++sp] = program[ip]; 
          break;

        case ADD: {
          int a = stack[sp--];
          int b = stack[sp--];
          stack[++sp] = a + b;
          break;}

        case SUB:{
          int arg1 = stack[sp--];
          int arg2 = stack[sp--];
          stack[++sp] = arg2 - arg1;
          break;
        }

        case MUL: {
          int arg1 = stack[sp--];
          int arg2 = stack[sp--];
          stack[++sp] = arg1 * arg2;
          break;
        }

        case DIV: {
          int arg1 = stack[sp--];
          int arg2 = stack[sp--];
          stack[++sp] = arg2 / arg1;
          break;
        }

        //case MOD: {}
        
        case PRINT: {
          std::cout << stack[sp] << std::endl;
          break;
        }
          
        
        default:{
          std::cout << "Unexpected argument" << std::endl;
          break;}
      }
      ip++; 
    }


  }
  



  return 0;
} 