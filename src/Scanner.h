#pragma once
#include "Token.h"

class Scanner
{
	private:
		string entrada;
		int pos;

	public:
		Scanner(string entrada);
		Token* nextToken()
        void ErroLexico();
}