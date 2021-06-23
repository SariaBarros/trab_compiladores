#include "Parser.h"
#include "First.h"

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
    program();

    cout << "Compilação encerrada com sucesso!\n";
}

void Parser::program(){
    //todo: testar a First.cpp
    //checa se o lookahead tá no fist de classList
    if(First::classList(lToken)){
        classList();
    }

}

void Parser::classList(){
    classDecl();
        classList_Linha();
}

void Parser::classList_Linha(){
    if(First::classList(lToken)){
        classList();
    }
}

void Parser::classDecl(){
    if(lToken->lexema == "class"){
        advance();
        match(ID);
        classDecl_Linha();
    }
}

void Parser::classDecl_Linha(){
    if(lToken->lexema == "extends"){
        advance();
        match(ID);
    }
    classBody();
}

void Parser::classBody(){
    if(lToken->nome == ECOL){
        advance();
        varDeclListOpt();
            constructDeclListOpt();
                methodDeclListOpt();
        match(DCOL);
    }
}

void Parser::varDeclListOpt(){
    if (First::varDeclList(lToken))
        varDeclList();
}

void Parser::varDeclList(){
    varDecl();
        varDeclList_Linha();
}

void Parser::varDeclList_Linha(){
    if(First::varDecl(lToken)){
        varDecl();
            varDecl_Linha();
    }
}

void Parser::varDecl(){
    type();
        varDecl_Linha();
}

void Parser::varDecl_Linha(){
    if(lToken->nome == ID){
        advance();
        varDeclOpt();
        match(PVIR);
    }
    else if(lToken->nome == ECOL){
        advance();
        match(DCOL);
        match(ID);
        varDeclOpt();
        match(PVIR);
    }
}

void Parser::varDeclOpt(){
    if(lToken->atributo == VIR){
        advance();
        match(ID);
        varDeclOpt();
    }
}

void Parser::type(){
    if(lToken->lexema == "int"){
        advance();
    }
    else if(lToken->lexema == "string"){
        advance();
    }
    else if(lToken->nome == ID){
        // ToDo: tratar o id
        advance();
    }
}

void Parser::constructDeclListOpt(){
    if(First::constructDeclList(lToken)){
        constructDeclList();
    }
}

void Parser::constructDeclList(){
    constructDecl();
        constructDeclList_Linha();
}

void Parser::constructDeclList_Linha(){
    if(First::constructDecl(lToken)){
        constructDecl();
            constructDeclList_Linha();
    }
}

void Parser::constructDecl(){
    if(lToken->lexema == "constructor"){
        methodBody();
    }
}

void Parser::methodDeclListOpt(){
    if(First::methodDeclList(lToken)){
        methodDeclList();
    }
}

void Parser::methodDeclList(){
    methodDecl();
        methodDeclList_Linha();
}

void Parser::methodDeclList_Linha(){
    if(First::methodDeclList_Linha(lToken)){
        methodDecl();
            methodDeclList_Linha();
    }
}

void Parser::methodDecl(){
    type();
        methodDecl_Linha();
}

void Parser::methodDecl_Linha(){
    if(lToken->nome == ID){
        advance();
        methodBody();
    }
    else if(lToken->nome == ECOL){
        advance();
        match(DCOL);
        match(ID);
        methodBody();
    }
}

void Parser::methodBody(){
    if(lToken->nome == EPAR){
        paramListOpt();
        match(DPAR);
        match(ECHAV);
        statementsOpt();
        match(DCHAV);
    }
}

void Parser::paramListOpt(){
    if(First::paramList(lToken)){
        paramList();
    }
}

void Parser::paramList(){
    param();
        paramList_Linha();
}

void Parser::paramList_Linha(){
    if( lToken->nome == VIR){
        param();
            paramList_Linha();
    }
}

void Parser::param(){
    type();
        param_Linha();
}

void Parser::param_Linha(){
    if(lToken->nome == ID){
        //ToDo: tratar id
        advance();
    }
    else if(lToken->nome == ECOL){
        advance();
        match(DCOL);
        match(ID);
        //OBS: não sei se dá pra tratar o id se usar a match
    }
}

void Parser::statementsOpt(){
    if(First::statements(lToken)){
        statements();
    }
}

void Parser::statements(){
    statement();
        statements_Linha();
}

void Parser::statements_Linha(){
    if(First::statement(lToken)){
        statement();
            statements_Linha();
    }
}

void Parser::statement(){
    if(First::varDeclList(lToken)){
        varDeclList();
    }
    else if(First::atribStat(lToken)){
        atribStat();
        match(PVIR);
    }
    else if(First::printStat(lToken)){
        printStat();
        match(PVIR);
    }
    else if(First::readStat(lToken)){
        readStat();
        match(PVIR);
    }
    else if(First::returnStat(lToken)){
        returnStat();
        match(PVIR);
    }
    else if(First::superStat(lToken)){
        superStat();
        match(PVIR);
    }
    else if(First::ifStat(lToken)){
        ifStat();
    }
    else if(First::forStat(lToken)){
        forStat();
    }
    else if(lToken->lexema == "break"){
        advance();
        match(PVIR);
    }  
    else if(lToken->nome == PVIR){
        advance();
    }
}

void Parser::atribStat(){
    lValue();
    match(EQ);
    atribStat_Linha();
}

void Parser::atribStat_Linha(){
    if(First::expression(lToken))
        expression();
    else if(First::allocExpression(lToken))
        allocExpression();
}

void Parser::printStat(){
    if(lToken->lexema == "print"){
        advance();
        expression();
    }
}

void Parser::readStat(){
    if(lToken->lexema == "read"){
        advance();
        lValue();
    }
}

void Parser::returnStat(){
    if(lToken->lexema == "return"){
        advance();
        expression();
    }
}

void Parser::superStat(){
    if (lToken->lexema == "super"){
        advance();
        match(EPAR);
        argListOpt();
        match(DPAR);
    }
}

void Parser::ifStat(){
    if(lToken->lexema == "if"){
        advance();
        match(EPAR);
            expression();
        match(DPAR);
        match(ECHAV);
            statements();
        match(DCHAV);
        ifStat_Linha();
    }
}

void Parser::ifStat_Linha(){
    if(lToken->lexema == "else"){
        advance();
        match(ECHAV);
            statements();
        match(DCHAV);        
    }
}

void Parser::forStat(){
    if(lToken->lexema == "for"){
        advance();
        match(EPAR);
            atribStatOpt();
            match(VIR);
            expressionOpt();
            match(VIR);
            atribStatOpt();
        match(DPAR);
        match(ECHAV);
            statements();
        match(DCHAV);        
    }
}

void Parser::atribStatOpt(){
    if(First::atribStat(lToken)){
        atribStat();
    }
}

void Parser::expressionOpt(){
    if(First::expression(lToken)){
        expression();
    }
}

void Parser::lValue(){
    if(lToken->nome == ID){
        advance();
        lValue_Linha();
    }
}

void Parser::lValue_Linha(){
    if(lToken->nome == ECOL){
        advance();
        expression();
        match(DCOL);
    }
    lValueComp();
}

void Parser::lValueComp(){
    if(lToken->lexema == "."){
        advance();
        match(ID);
        lValueComp_Linha();
    }
}

void Parser::lValueComp_Linha(){
    if(lToken->nome == ECOL){
        advance();
        expression();
        match(DCOL);
    }
    lValueComp();
}

void Parser::expression(){
    numExpression();
        expression_Linha();
}

void Parser::expression_Linha(){
//oq é relop?
    if(lToken->nome == OP){
        numExpression();
    }
}

void Parser::allocExpression(){
    if(lToken->lexema == "new"){
        advance();
        match(ID);
        match(EPAR);
            argListOpt();
        match(DPAR);
    }
    else{
        type();
        match(ECOL);
            expression();
        match(DCOL);
    }
}

void Parser::numExpression(){
    term();
        numExpression_Linha();
}

void Parser::numExpression_Linha(){
    if (lToken->nome == SUM || lToken->nome == DIF){
        advance();
        term();
    }
}

void Parser::term(){
    unaryExpression();
        term_Linha();
}

void Parser::term_Linha(){
    if(lToken->nome == MULT || lToken->nome == DIV || lToken->nome == MOD){
        advance();
        unaryExpression();
    }
}

void Parser::unaryExpression(){
    if (lToken->nome == SUM || lToken->nome == DIF){
        advance();
        factor();
    }   
}

void Parser::factor(){
    if(lToken->nome == INTEGER_LITERAL){
        //tratar o numero.
        advance();
    }
    else if(lToken->nome == STR){
        advance();
    }
    else if(lToken->nome == EPAR){
        advance();
        expression();
        match(DPAR);
    }
    lValue();
}

void Parser::argList(){
    expression();
        argList_Linha();
}

void Parser::argListOpt(){
    if(First::argList(lToken))
        argList();
}

void Parser::argList_Linha(){
    if(lToken->nome == VIR){
        expression();
        argList_Linha();
    }
}

void Parser::erro(){
    cout << "Erro Sintatico:(" << endl;
}
