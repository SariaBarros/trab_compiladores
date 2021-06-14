#include "Scanner.h"

//Construtor
Scanner::Scanner(string entrada){
	this->entrada = entrada;
	pos = 0;
}

Token* Scanner::nextToken(){
	Token* tok;
	string buffer;

	//consome espaços em branco
	while(isspace(entrada[pos]))
		pos++;

	//TODO:checar isso daqui depois.
	if(entrada[pos] == '/'){
		pos++;
		if(entrada[pos] == '/'){
			do{
				pos++;
			}while(entrada[pos] != '\n');
			pos++;
			tok = this->nextToken();
			//tok = new Token(COMENTARIO);
		}
		else if(entrada[pos] == '*'){
			do{
				pos++;
			}while(entrada[pos] != '*' and entrada[pos++] != '/');
			pos += 2;
			tok = this->nextToken();
			//tok = new Token(COMENTARIO);
		}
		else {
			tok = new Token(OP, DIV);
		}
		
	}

	//fim de arquivo
	else if(entrada[pos] == '\0'){
		tok = new Token(END_OF_FILE);
	}
	//identificadores
	else if(isalpha(entrada[pos]) or entrada[pos] == '_'){
		buffer = entrada[pos];
		pos++;
		while(isalnum(entrada[pos])){
			buffer.push_back(entrada[pos]);
			pos++;
		}
		//TODO:busca por palavras reservadas na symble table.
		//idea: hash???

		//TODO: armazenar o id.
		tok = new Token(ID, buffer);
		buffer.clear();
	}

	//numeros
	else if(isdigit(entrada[pos])){
		buffer = entrada[pos];
		pos++;
		while(isdigit(entrada[pos])) {
			buffer.push_back(entrada[pos]);
			pos++;
		}
		//TODO: armazenar o numero.
		tok = new Token(INTEGER_LITERAL, buffer);
	}
	//operadores
	else if(entrada[pos] == '<'){
		pos++;
		if(entrada[pos] = '='){ 
			pos++;
			tok = new Token(OP, MNE); //<=
		}
		else
			tok = new Token(OP, MN); //<
		
	}
	else if(entrada[pos] == '>'){
		pos++;
		if(entrada[pos] == '='){
			pos++;
			tok = new Token(OP, MAE);//>=
		}
		else
			tok = new Token(OP, MA); //>
	}
	else if(entrada[pos] == '+'){
		pos++;
		tok = new Token(OP, SUM);
	}
	else if(entrada[pos] == '-'){
		pos++;
		tok = new Token(OP, DIF);
	}
	else if(entrada[pos] == '*'){
		pos++;
		tok = new Token(OP, MULT);
	}
	else if(entrada[pos] == '%'){
		pos++;
		tok = new Token(OP, MOD);
	}
	else if(entrada[pos] == '='){
		pos++;
		if(entrada[pos] == '='){
			pos++;
			tok = new Token(OP, EQ);
		}
		else
			tok = new Token(OP, REC);
	}
	else if(entrada[pos] == '!'){
		pos++;
		if(entrada[pos] == '='){
			tok = new Token(OP, NEQ);
		}
		else
			ErroLexico(); //não sei se deixo isso aqui mesmo.
	}
	//SEPARADORES
	else if(entrada[pos] == '('){
		pos++;
		tok = new Token(SEP, EPAR);
	}
	else if(entrada[pos] == ')'){
		pos++;
		tok = new Token(SEP, DPAR);
	}
	else if(entrada[pos] == '['){
		pos++;
		tok = new Token(SEP, ECOL);
	}
	else if(entrada[pos] == ']'){
		pos++;
		tok = new Token(SEP, DCOL);
	}
	else if(entrada[pos] == '{'){
		pos++;
		tok = new Token(SEP, ECHAV);
	}
	else if(entrada[pos] == '}'){
		pos++;
		tok = new Token(SEP, DCHAV);
	}
	else if(entrada[pos] == ';'){
		pos++;
		tok = new Token(SEP, PVIR);
	}
	else if(entrada[pos] == '.'){
		pos++;
		tok = new Token(SEP, PNT);
	}
	else if(entrada[pos] == ','){
		pos++;
		tok = new Token(SEP, VIR);
	}
	else if(entrada[pos] == '"'){
		pos++;
		while(entrada[pos] != '"'){
			buffer.push_back(entrada[pos]);
			pos++;
		}
		pos++;
		tok = new Token(STR, buffer);
		buffer.clear();
	}



	else
		ErroLexico();
	
	return tok;
}

//Aviso de erro lexico
void Scanner::ErroLexico(){
	cout<<"Erro\n";
	//exit(EXIT_FAILURE);
}