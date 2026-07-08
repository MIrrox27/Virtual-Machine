// author github.com/MIrrox27/Virtual-Machine
// src/main.cpp

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "console.hpp"
#include "repl.hpp"
#include "assembler.hpp"



int main(int argc, char* argv[]){
  
  
  /*
    Args 
     * index = 1:
        "-r" - run bytecode
        "-c" - compile txt commands to bytecode
      * index = 2:
        ```path``` - path to file with  bytecode
  */

  if (argc > 3 && argv[1] == "-r"){ // если тег "-r" то будут читаться и выполняться байты

  }
  else if (argc > 3 && argv[1] == "-c"){ // если тег "-c" то команда сначала переведется в байт код (в отдельный файл) и только потом запустится 

  }

  //else repl();
  

  return 0;
} 