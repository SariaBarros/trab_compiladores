#pragma once
#include "Token.h"

class Scanner
{
	private:
		string entrada;
		int pos;

	public:
		Scanner(ifstream* entrada);
		Token* nextToken();
        void ErroLexico();
		int linha=1;
};