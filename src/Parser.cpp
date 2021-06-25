#include "Parser.h"
#include "First.h"
#include "Scanner.h"

Parser::Parser(string input){
	scanner = new Scanner(input);
}

void Parser::advance(){
	lToken = scanner->nextToken();
}

void Parser::matchN(int t){
	if (lToken->nome == t) {
		advance();
	}
	else
		erro();
}

void Parser::matchA(int t){
	if (lToken->atributo == t){
		advance();
	}
	else
		erro();
}

void Parser::run(){
	advance();

	program();

	cout << "Compilação encerrado com sucesso!\n";
}

void Parser::program(){
	if(First::classList(lToken)){
		classList();
	}
}

void Parser::classList(){
	classDecl();
	classListLinha();
}

void Parser::classListLinha(){
	if(First::classList(lToken))
		classList();
}

void Parser::classDecl(){
	if(lToken->lexema == "class"){
		advance();
		matchN(ID);
		classDeclLinha();
		classBody();
	}
	else
		erro();
}

void Parser::classDeclLinha(){
	if(lToken->lexema == "extends"){
		advance();
		matchN(ID);
	}
}

void Parser::classBody(){
	if(lToken->atributo == ECHAV ){
		advance();
		varDeclListOpt();
		constructDeclListOpt();
		methodDeclListOpt();
		matchA(DCHAV);
	}
	else
		erro();
}

void Parser::varDeclListOpt(){
	if(First::varDeclListOpt(lToken)){
		varDeclList();
	}
}

void Parser::varDeclList(){
	varDecl();
	varDeclListLinha();
}

void Parser::varDeclListLinha(){
	if(First::varDecl(lToken)){
		varDecl();
		varDeclLinha();
	}
}

void Parser::varDecl(){
	type();
	varDeclLinha();
}

void Parser::varDeclLinha(){
	if(lToken->nome == ID){
		advance();
		varDeclOpt();
		matchA(PVIR);
	}
	else if(lToken->atributo == ECOL){
		advance();
		matchA(DCOL);
		matchN(ID);
		varDeclOpt();
	}
	else
		erro();
}

void Parser::varDeclOpt(){
	if(lToken->atributo == VIR) {
		advance();
		matchN(ID);
		varDeclOpt();
	}
}

void Parser::type(){
	if(lToken->lexema == "int")
		advance();

	else if(lToken->lexema == "string")
		advance();

	else if(lToken->nome == ID)
		advance();
	
	else
		erro();
}

void Parser::constructDeclListOpt(){
	if(First::constructDeclListOpt(lToken)){
		constructDeclList();
	}
}

void Parser::constructDeclList(){
	constructDecl();
	constructDeclListLinha();
}

void Parser::constructDeclListLinha(){
	if(First::constructDecl(lToken)){
		constructDecl();
		constructDeclListLinha();
	}
}

void Parser::constructDecl(){
	if(lToken->lexema == "constructor"){
		advance();
		methodBody();
	}
	else
		erro();
}

void Parser::methodDeclListOpt(){
	if(First::methodDeclList(lToken)){
		methodDeclList();
	}
}

void Parser::methodDeclList(){
	methodDecl();
	methodDeclListLinha();
}

void Parser::methodDeclListLinha(){
	if(First::methodDecl(lToken)){
		methodDecl();
		methodDeclListLinha();
	}
}

void Parser::methodDecl(){
	type();
	methodDeclLinha();
}

void Parser::methodDeclLinha(){
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
	else
		erro();
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
	else
		erro();
}

void Parser::paramListOpt(){
	if(First::paramList(lToken)){
		paramList();
	}
}

void Parser::paramList(){
	param();
	paramListLinha();
}

void Parser::paramListLinha(){
	if(lToken->atributo == VIR){
		advance();
		param();
		paramListLinha();
	}
}

void Parser::param(){
	type();
	paramLinha();
}

void Parser::paramLinha(){
	if (lToken->nome == ID){
		advance();
	}
	else if(lToken->atributo == ECOL){
		matchA(DCOL);
		matchN(ID);
	}
	else
		erro();
}

void Parser::statementsOpt(){
	if(First::statements(lToken)){
		statements();
	}
}

void Parser::statements(){
	statement();
	statementsLinha();
}

void Parser::statementsLinha(){
	if(First::statement(lToken)){
		statement();
		statementsLinha();
	}
}

void Parser::statement(){
	if(First::varDeclList(lToken)){
		varDeclList();
	}
	else if(First::atribStat(lToken)){
		atribStat();
		matchA(PVIR);
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
	else if(First::forStat(lToken)){
		forStat();
	}
	else if(lToken->lexema == "break"){
		advance();
		matchA(PVIR);
	}
	else if(lToken->atributo == PVIR)
		advance();
	else
		erro();
}

void Parser::atribStat(){
	if(First::lValue(lToken)){
		lValue();
		matchA(REC);
		atribStatLinha();
	}
	else
		erro();
}

void Parser::atribStatLinha(){
	if(First::expression(lToken)){
		expression();
	}
	else if(First::allocExpression(lToken)){
		allocExpression();
	}
	else
		erro();
}

void Parser::printStat(){
	if(lToken->lexema == "print"){
		advance();
		expression();
	}
	else
		erro();
}

void Parser::readStat(){
	if(lToken->lexema == "read"){
		advance();
		lValue();
	}
	else
		erro();
}

void Parser::returnStat(){
	if(lToken->lexema == "return"){
		advance();
		expression();
	}
	else
		erro();
}

void Parser::superStat(){
	if(lToken->lexema == "super"){
		advance();
		matchA(EPAR);
		argListOpt();
		matchA(DPAR);
	}
	else
		erro();
}

void Parser::ifStat(){
	if(lToken->lexema == "if"){
		advance();
		matchA(EPAR);
		expression();
		matchA(DPAR);
		matchA(ECHAV);
		statements();
		matchA(DCHAV);
		ifStatLinha();
	}
	else
		erro();
}

void Parser::ifStatLinha(){
	if(lToken->lexema == "else"){
		advance();
		matchA(ECHAV);
		statements();
		matchA(DCHAV);
	}
}

void Parser::forStat(){
	if(lToken->lexema == "for"){
		advance();
		matchA(EPAR);
		atribStatOpt();
		matchA(PVIR);
		expressionOpt();
		matchA(PVIR);
		atribStatOpt();
		matchA(DPAR);
		matchA(ECHAV);
		statements();
		matchA(DCHAV);
	}
	else
		erro();
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
		lValueLinha();
	}
}

void Parser::lValueLinha(){
	if(First::lValueComp(lToken)){
		lValueComp();
	}
	else if(lToken->atributo == ECOL){
		advance();
		expression();
		matchA(DCOL);
		lValueComp();
	}
	else
		erro();
}

void Parser::lValueComp(){
	if(lToken->atributo == PNT){
		advance();
		matchN(ID);
		lValueCompLinha();
	}
}

void Parser::lValueCompLinha(){
	if(First::lValueComp(lToken)){
		lValueComp();
	}
	else if(lToken->atributo == ECOL){
		advance();
		expression();
		matchA(DCOL);
		lValueComp();
	}
}

void Parser::expression(){
	numExpression();
	expressionLinha();
}

void Parser::expressionLinha(){
	if(lToken->nome == RELOP){
		numExpression();
	}
}

void Parser::allocExpression(){
	if(lToken->lexema == "new"){
		advance();
		matchN(ID);
		matchN(EPAR);
		argListOpt();
		matchN(DPAR);
	}
	else if(First::type(lToken)){
		type();
		matchA(ECOL);
		expression();
		matchA(DCOL);
	}
	else
		erro();
}

void Parser::numExpression(){
	term();
	numExpressionLinha();
}

void Parser::numExpressionLinha(){
	if(lToken->atributo == SUM or lToken->atributo == DIF){
		advance();
		term();
	}
}

void Parser::term(){
	unaryExpression();
	termLinha();
}

void Parser::termLinha(){
	if(lToken->atributo == DIV or lToken->atributo == MULT or lToken->atributo == MOD){
		advance();
		unaryExpression();
	}
}

void Parser::unaryExpression(){
	if(lToken->atributo == SUM or lToken->atributo == DIF){
		advance();
		factor();
	}
	else
		erro();
}

void Parser::factor(){
	if(First::lValue(lToken)){
		lValue();
	}
	else if (lToken->atributo == EPAR){
		advance();
		expression();
		matchA(DPAR);
	}
	else if(
		lToken->nome == INTEGER_LITERAL or
		lToken->nome == STR 
	) {
		advance();
	}
	else
		erro();
}

void Parser::argListOpt(){
	if(First::argListOpt(lToken)){
		argList();
	}
}

void Parser::argList(){
	expression();
	argListLinha();
}

void Parser::argListLinha() {
	if (lToken->atributo == VIR){
		advance();
		expression();
		argListLinha();
	}
}

void Parser::erro(){
    cout << "Erro Sintatico:(" << endl;
    exit(EXIT_FAILURE);
}