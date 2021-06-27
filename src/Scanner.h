#pragma once
#include "Token.h"
#include "symboltable.h"

class Scanner
{
	private:
		string entrada;
		int pos;
		SymbolTable *st;

	public:
		Scanner(ifstream* entrada, SymbolTable* table);
		Token* nextToken();
        void ErroLexico(int);
		int linha = 1;
};