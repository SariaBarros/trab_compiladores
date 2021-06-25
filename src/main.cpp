#include "First.h"
#include "Parser.h"

int main(int argc, char* argv[]){
  // string input;
  // string linha;
  // 
  // if (!in) {
  //   std::cerr << "Erro ao abrir arquivo, modo teste\n ";
  //   getline(cin, linha);
  //   //exit(EXIT_FAILURE);
  // }else{
  //   while(getline(in, input)){
  //     linha.append(input).append("\n");
  //   }
  // }
  // 
  // Parser* parser = new Parser(&linha);
  Parser* parser = new Parser(argv[1]);
  parser->run();
  //Chama o destrutor
  delete parser;

  return 0;
}