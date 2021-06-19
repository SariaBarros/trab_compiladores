#include "Scanner.h"
#include "First.h"

int main(int argc, char* argv[]){
  string input;
  string linha;
  ifstream in(argv[1]);

  if (!in) {
    std::cerr << "Erro ao abrir arquivo\n";
    Token* i = new Token(ID, "class");
    cout << First::classList(i) << endl;
    exit(EXIT_FAILURE);
  }
  while(getline(in, linha)){
    input.append(linha).append("\n");
  }
  Scanner* scanner = new Scanner(input);
  Token* t;

  do{
      t = scanner->nextToken();
      t->ToString();
  }while(t->nome != END_OF_FILE);

    //Chamar o destrutor.

    return 0;
}