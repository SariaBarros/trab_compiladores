#include "token.h"

class Scanner
{
	private:
		string entrada;
		int pos;

	public:
		Scanner(string entrada){
			this.entrada = entrada;
		}

		Token* nextToken()
}