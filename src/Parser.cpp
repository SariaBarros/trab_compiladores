#include "Parser.h"

Parser::Parser(ifstream* input){
    currentST = globalST = new SymbolTable();
    initSymbolTable();

    scanner = new Scanner(input, globalST);
}

void Parser::advance(){
    lToken = scanner -> nextToken();
    // lToken->ToString();
}

void Parser::matchN(int t){
    if(lToken->nome == t)
        advance();
    else
        erro(this->scanner->linha);
}

void Parser::matchA(int t){
    if (lToken->atributo == t)
        advance();
    else
        erro(this->scanner->linha);
}

void Parser::run(){
    
    advance();

    currentST = new SymbolTable(currentST);

    program();
    //teste ts
    // if(currentST->add(new STEntry(new Token(ID), "oie")))
    //     cout<<"foi"<<endl;
    // else
    //     cout<<"nao foi\n";
    
    // STEntry* obj = currentST->get("oie");

    // if(obj)
    //     cout<<"foi"<<endl;
    // else
    //     cout<<"nao foi\n";

    // cout << "Compilação encerrada com sucesso!\n";
}

void Parser::program(){
    //todo: testar a First.cpp
    //checa se o lookahead tá no fist de classList
    if(lToken && lToken->nome == END_OF_FILE)
        return;
    else if(First::classList(lToken)){
        classList();
    }
    else{
        erro(this->scanner->linha);
    }
}

void Parser::classList(){
    classDecl();
    if(First::classList(lToken)){
        classList();
    }else if(lToken && lToken->nome != END_OF_FILE){
        lToken->ToString();
        erro(this->scanner->linha);
    }
}


void Parser::classDecl(){
    if(lToken->atributo == CLASS){
        advance();
        matchN(ID);
        classDecl_Linha();
    }
    else {
        erro(this->scanner->linha);
    }
}

void Parser::classDecl_Linha(){
    if(lToken->atributo == EXTND){
        advance();
        matchN(ID);
        classBody();
    }
    else if(First::classBody(lToken)){
        classBody();
    }
    else {
        erro(this->scanner->linha);
    }
}

void Parser::classBody(){
    if(lToken->atributo == ECHAV){
        advance();
        varDeclListOpt();
            constructDeclListOpt();
                methodDeclListOpt();
        matchA(DCHAV);
    }
    else{
        erro(this->scanner->linha);
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
            varDeclList_Linha();
    }
}

void Parser::varDecl(){
    type();
    if(lToken->nome == ID){
        advance();
        if(First::methodBody(lToken)){
            methodBody();
        }
        else{
            if(First::varDeclOpt(lToken)){
                varDeclOpt();
            }
            matchA(PVIR);
        }
    }
    else if(lToken->atributo == ECOL){
        advance();
        matchA(DCOL);
        matchN(ID);
        if(First::methodBody(lToken)){
            methodBody();
        }
        else{
            if(First::varDeclOpt(lToken)){
                varDeclOpt();
            }
            matchA(PVIR);
        }        
    }
}


void Parser::varDeclOpt(){
    if(lToken->atributo == VIR){
        advance();
        matchN(ID);
        varDeclOpt();
    }
}

void Parser::type(){
    if(lToken->atributo == INT){
        advance();
    }
    else if(lToken->atributo == STRING){
        advance();
    }
    else if(lToken->nome == ID){
        // ToDo: tratar o id
        advance();
    }
    else {
        erro(this->scanner->linha);
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
    if(lToken->atributo == CNST){
        advance();
        methodBody();
    }
    else {
        erro(this->scanner->linha);
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
    else if(lToken->atributo == ECOL){
        advance();
        matchA(DCOL);
        matchN(ID);
        methodBody();
    }
}

void Parser::methodBody(){
    if(lToken->atributo == EPAR){
        advance();
        paramListOpt();
        matchA(DPAR);
        matchA(ECHAV);
        statementsOpt();
        matchA(DCHAV);
    }
    else {
        erro(this->scanner->linha);
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
    if( lToken->atributo == VIR){
        advance();
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
    else if(lToken->atributo == ECOL){
        advance();
        matchA(DCOL);
        matchN(ID);
        //OBS: não sei se dá pra tratar o id se usar a match
    }
    else {
        erro(this->scanner->linha);
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
    if(First::forStat(lToken)){
        forStat();
    }
    // if(First::atribStat(lToken)){
    //     atribStat();
    //     matchA(PVIR);
    // }
    else if(First::varDeclList(lToken)){
        varDeclList();
    }
    else if(First::printStat(lToken)){
        printStat();
        matchA(PVIR);
    }
    else if(First::readStat(lToken)){
        readStat();
        matchA(PVIR);
    }
    else if(First::returnStat(lToken)){
        returnStat();
        matchA(PVIR);
    }
    else if(First::superStat(lToken)){
        superStat();
        matchA(PVIR);
    }
    else if(First::ifStat(lToken)){
        ifStat();
    }
    // else if(First::forStat(lToken)){
    //     forStat();
    // }
    else if(lToken->atributo == BRK){
        advance();
        matchA(PVIR);
    }  
    else if(lToken->atributo == PVIR){
        advance();
    }
}

void Parser::atribStat(){
    lValue();
    matchA(REC);
    atribStat_Linha();
}

void Parser::atribStat_Linha(){
    if(First::expression(lToken)){
        expression();
    }
    else if(First::allocExpression(lToken))
        allocExpression();
}

void Parser::printStat(){
    if(lToken->atributo == PRT){
        advance();
        expression();
    }
}

void Parser::readStat(){
    if(lToken->atributo == READ){
        advance();
        lValue();
    }
}

void Parser::returnStat(){
    if(lToken->atributo == RTN){
        advance();
        expression();
    }
}

void Parser::superStat(){
    if (lToken->atributo == super){
        advance();
        matchA(EPAR);
        argListOpt();
        matchA(DPAR);
    }
}

void Parser::ifStat(){
    if(lToken->atributo == IF){
        advance();
        matchA(EPAR);
            expression();
        matchA(DPAR);
        matchA(ECHAV);
            statements();
        matchA(DCHAV);
        ifStat_Linha();
    }
}

void Parser::ifStat_Linha(){
    if(lToken->atributo == ELSE){
        advance();
        matchA(ECHAV);
            statements();
        matchA(DCHAV);        
    }
}

void Parser::forStat(){
    if(lToken->atributo == FOR){
        advance();
        matchA(EPAR);
            atribStatOpt();
            advance();
            matchA(PVIR);
            expressionOpt();
            matchA(PVIR);
            atribStatOpt();
        matchA(DPAR);
        matchA(ECHAV);
            statements();
        matchA(DCHAV);        
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
    if(lToken->atributo == ECOL){
        advance();
        expression();
        matchA(DCOL);
    }
    lValueComp();
}

void Parser::lValueComp(){
    if(lToken->lexema == "."){
        advance();
        matchN(ID);
        lValueComp_Linha();
    }
}

void Parser::lValueComp_Linha(){
    if(lToken->atributo == ECOL){
        advance();
        expression();
        matchA(DCOL);
    }
    lValueComp();
}

void Parser::expression(){
    numExpression();
    if(isRelOp()){
        advance();
        numExpression();
    }
}

void Parser::allocExpression(){
    if(lToken->atributo == NEW){
        advance();
        matchN(ID);
        matchA(EPAR);
            argListOpt();
        matchA(DPAR);
    }
    else{
        type();
        matchA(ECOL);
            expression();
        matchA(DCOL);
    }
}

void Parser::numExpression(){
    term();
    if(lToken->atributo == SUM || lToken->atributo == DIF){
        advance();
        term();
    }
}

void Parser::term(){
    unaryExpression();

    if(lToken->atributo == MULT || lToken->atributo == DIV || lToken->atributo == MOD){
        advance();
        unaryExpression();
    }
}

void Parser::unaryExpression(){
    if (lToken->atributo == SUM || lToken->atributo == DIF){
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
    else if(lToken->atributo  == EPAR){
        advance();
        expression();
        matchA(DPAR);
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

void Parser::erro(int linha){
    cout << "Erro Sintatico na linha "<< linha << endl;
    exit(EXIT_FAILURE);
}

bool Parser::isRelOp(){
    if(lToken->atributo == MN || lToken->atributo == MA ||
    lToken->atributo == MNE || lToken->atributo == MAE ||
    lToken->atributo == EQ){
        return true;
    }
    else
        return false;
}

void Parser::initSymbolTable(){
    Token* t;

    t = new Token(RESERV, CLASS);
    globalST->add(new STEntry(t, "class", true));

    t = new Token(RESERV, EXTND);
    globalST->add(new STEntry(t, "extends", true));

    t = new Token(RESERV, INT);
    globalST->add(new STEntry(t, "int", true));

    t = new Token(RESERV, STRING);
    globalST->add(new STEntry(t, "string", true));

    t = new Token(RESERV, BRK);
    globalST->add(new STEntry(t, "break", true));

    t = new Token(RESERV, PRT);
    globalST->add(new STEntry(t, "print", true));

    t = new Token(RESERV, READ);
    globalST->add(new STEntry(t, "read", true));

    t = new Token(RESERV, RTN);
    globalST->add(new STEntry(t, "return", true));

    t = new Token(RESERV, SPR);
    globalST->add(new STEntry(t, "super", true));

    t = new Token(RESERV, IF);
    globalST->add(new STEntry(t, "if", true));

    t = new Token(RESERV, ELSE);
    globalST->add(new STEntry(t, "else", true));

    t = new Token(RESERV, FOR);
    globalST->add(new STEntry(t, "for", true));

    t = new Token(RESERV, NEW);
    globalST->add(new STEntry(t, "new", true));

    t = new Token(RESERV, CNST);
    globalST->add(new STEntry(t, "constructor", true));
}