#include "Parser.h"

Parser::Parser(string* input){
    scanner = new Scanner((*input));
}

void Parser::advance(){
    lToken = scanner -> nextToken();
}

void Parser::match(int t){
    if(lToken->nome == t || lToken->atributo == t)
        advance();
    else
        erro();
}

void Parser::run(){
    advance();

    //primeiro não terminal

    cout << "Compilação encerrada com sucesso!\n";
}
