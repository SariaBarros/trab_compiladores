#include "Parser.h"

int main(int argc, char* argv[]){
  string input;
  string linha;
  ifstream in(argv[1]);

  // if (!in) {
  //   std::cerr << "Erro ao abrir arquivo, modo teste\n ";
  //   getline(cin, linha);
  //   //exit(EXIT_FAILURE);
  // }else{
  //   while(getline(in, linha)){
  //     input.append(linha).append("\n");
  //   }
  // }

  Parser* parser = new Parser(&in);

  parser->run();
  
  //Chama o destrutor
  delete parser;

  return 0;
}