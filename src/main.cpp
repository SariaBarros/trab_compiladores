#include "Parser.h"

int main(int argc, char* argv[]){
  string input;
  string linha;
  ifstream in(argv[1]);



  Parser* parser = new Parser(&in);

  parser->run();
  
  //Chama o destrutor
  delete parser;

  return 0;
}