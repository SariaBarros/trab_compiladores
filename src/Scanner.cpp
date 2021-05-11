#include "Scanner.h"

//Construtor
Scanner::Scanner(string entrada){
	this->entrada = entrada;
	pos = 0;
}

Token* Scanner::nextToken(){
	Token* tok;
	int estado = 0;

	//consome espaços em branco
	while(isspace(entrada[pos]))
		pos++;
	//fim de arquivo
	if(entrada[pos] == '\0'){
		tok = new Token(END_OF_FILE);
	}
	//identificadore
	else if(isalpha(entrada[pos]) or entrada[pos] == '_'){
		pos++;
		while(isalnum(entrada[pos]))
			pos++;
		//TODO:busca por palavras reservadas na symble table.
		//idea: hash???

		tok = new Token(ID);
	}

	//numeros
	else if(isdigit(entrada[pos])){
		pos++;
		while(isdigit(entrada[pos]))
			pos++;
		
		tok = new Token(INTEGER_LITERAL);
	}
	//operadores
	else if(entrada[pos] == '<'){
		pos++;
		if(entrada[pos] = '='){ 
			pos++;
			tok = Token(OP, MNE); //<=
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
	else if(entrada[pos] == '/'){
		pos++;
		tok = new Token(OP, DIV);
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
	else if()



	else
		ErroLexico();
	
	return tok;
}

//Aviso de erro lexico
void Scanner::ErroLexico(){
	cout<<"Erro\n";
	exit(EXIT_FAILURE);
}