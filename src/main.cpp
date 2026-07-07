// author github.com/MIrrox27/Virtual-Machine
// src/main.cpp

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "console.hpp"



int main(int argc, char* argv[]){
  int ip = 0;
  bool running = true;
  std::string str_command;

  /*
    Args 
     * index = 1:
        "-r" - run bytecode
      * index = 2:
        ```path``` - path to file with  bytecode
  */
  
  if (argc >= 3) str_command = get_bytecode(argv[2]);
  else str_command = "";

  while (running){
    if (argc == 1){
      str_command = "";
      std::cout << "> ";
      std::getline(std::cin, str_command);
    }
    std::vector<int> program = cin_parser(str_command);
    int stack[1024];
    stack[0] = START;
    int sp = 0;
    ip = 0;

    while (ip < program.size()){
      int opcode = program[ip]; // команда, которая выполняется сейчас

      switch (opcode){
        case ERR:{
          ip++;
          std::cerr << "Error: " << program[ip];
          break;
        }

        case HALT:
          running = false;
          break;

        case PUSH:
          ip++;
          stack[++sp] = program[ip]; 
          break;

        case ADD: {
          int arg1 = stack[sp--];
          int arg2 = stack[sp--];
          stack[++sp] = arg2 + arg1;
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

        case MOD: {
          int arg1 = stack[sp--];
          int arg2 = stack[sp--];
          stack[++sp] = arg2 % arg1;
          break;
        }

        case POW: {
          int arg1 = stack[sp--];
          int arg2 = stack[sp--];
          stack[++sp] = pow(arg2, arg1);
          break;
        }

        case SQRT: {
          int arg1 = stack[sp--];
          int arg2 = stack[sp--];
          stack[++sp] = pow(arg2, 1.0/(float)arg1);
          break;
        }

        case JUMP: {
          ip++;
          ip = program[ip];
          break;
        }
        
        case JIF: {
          ip++;
          if (program[ip] != 0)
            ip = program[ip];
          break;
        }
        
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