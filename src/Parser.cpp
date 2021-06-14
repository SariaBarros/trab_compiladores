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

void Parser::program(){
    //não tenho certeza do que fazer com o epsilon
}

void Parser::classList(){
    classDecl();
        classList_Linha();
}

void Parser::classList_Linha(){
    //dont know
}

void Parser::classDecl(){
    
}

void Parser::classDecl_Linha(){

}

void Parser::classBody(){

}

void Parser::varDeclListOpt(){

}

void Parser::varDeclList(){

}

void Parser::varDeclList_Linha(){

}

void Parser::varDecl(){

}

void Parser::varDecl_Linha(){

}

void Parser::varDeclOpt(){

}

void Parser::type(){

}

void Parser::constructDeclListOpt(){

}

void Parser::constructDeclList(){

}

void Parser::constructDeclList_Linha(){

}

void Parser::constructDecl(){

}

void Parser::methodDeclListOpt(){

}

void Parser::methodDeclList(){

}

void Parser::methodDeclList_Linha(){

}

void Parser::methodDecl(){

}

void Parser::methodDecl_Linha(){

}

void Parser::methodBody(){

}

void Parser::paramListOpt(){

}

void Parser::paramList(){

}

void Parser::paramList_Linha(){

}

void Parser::param(){

}

void Parser::param_Linha(){

}

void Parser::statementsOpt(){

}

void Parser::statements(){

}

void Parser::statements_Linha(){

}

void Parser::statement(){

}

void Parser::atribStat(){

}

void Parser::atribStat_Linha(){

}

void Parser::printStat(){

}

void Parser::readStat(){

}

void Parser::returnStat(){

}

void Parser::superStat(){

}

void Parser::ifStat(){

}

void Parser::ifStat_Linha(){
    
}

void Parser::forStat(){

}

void Parser::atribStatOpt(){

}

void Parser::expressionOpt(){

}

void Parser::lValue(){

}

void Parser::lValue_Linha(){

}

void Parser::lValueComp(){

}

void Parser::lValueComp_Linha(){

}

void Parser::expression(){

}

void Parser::expression_Linha(){

}

void Parser::allocExpression(){

}

void Parser::numExpression(){

}

void Parser::numExpression_Linha(){

}

void Parser::term(){

}

void Parser::term_Linha(){

}

void Parser::unaryExpression(){

}

void Parser::factor(){

}

void Parser::argList(){

}

void Parser::argListOpt(){

}

void Parser::argList_Linha(){
    
}

