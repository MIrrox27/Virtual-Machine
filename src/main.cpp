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
  
  std::cerr << "Virtual Machine. Author: github.com/MIrrox27/Virtual-Machine" <<std::endl;
  /*
    Args 
     * index = 1:
        "-r" - run bytecode
        "-c" - compile txt commands to bytecode
        "-cr" - compile txt commands to bytecode and run
      * index = 2:
        ```path``` - path to file with  bytecode
  */

  if (argc >= 3 && std::string(argv[1]) == "-r"){ // если тег "-r" то будут читаться и выполняться байты
    std::vector<int> bytes = get(argv[2]);
    execute(bytes);
  }

  else if (argc >= 3 && std::string(argv[1]) == "-cr"){ // если тег "-cr" то команда сначала переведется в байт код (в отдельный файл) и только потом запустится 
    std::string path = assembly(argv[2]);
    std::vector<int> bytes = get(path);
    execute(bytes);
  }

  else if (argc >= 3 && std::string(argv[1]) == "-c"){
    std::string path = assembly(argv[2]);
  }
  
  else {
    repl();
  }
  

  return 0;
} 