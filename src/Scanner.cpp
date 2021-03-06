#include "Scanner.h"

//Construtor
Scanner::Scanner(ifstream* input, SymbolTable* table)
{

    pos = 0;
	st = table;

    string line;
	
    if ((*input).is_open()){
        while (getline((*input),line)){
            this->entrada.append(line + '\n');
        }
        (*input).close();
    }

    else {
        cout << "Unable to open file\n"; 
		exit(EXIT_FAILURE);
	}

}

Token* Scanner::nextToken(){
	Token* tok;
	string buffer;
	//consome espaços em branco
	while(isspace(entrada[pos])){
		entrada[pos] == '\n'? this->linha++:this->linha=this->linha;
		pos++;
	}

	if(entrada[pos] == '/'){
		pos++;
		if(entrada[pos] == '/'){
			do{
				pos++;
			}while(entrada[pos] != '\n');
			this->linha++;
			pos++;
			tok = this->nextToken();
			//tok = new Token(COMENTARIO);
		}
		else if(entrada[pos] == '*'){
			do{
				entrada[pos] == '\n'? this->linha++:this->linha=this->linha;
				pos++;
			}while(entrada[pos] != '*' and entrada[pos + 1] != '/');

			for(int i = 0; i < 4; i++) {
				entrada[pos] == '\n'? this->linha++:this->linha=this->linha;			
				pos++;
			}

			tok =  this->nextToken();

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
		STEntry* obj = st ->get(buffer);
		if(!obj){
			tok = new Token(ID, buffer);
		}
		else{
			tok = obj->token;
		}
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
			tok = new Token(RELOP, MNE); //<=
		}
		else
			tok = new Token(RELOP, MN); //<
		
	}
	else if(entrada[pos] == '>'){
		pos++;
		if(entrada[pos] == '='){
			pos++;
			tok = new Token(RELOP, MAE);//>=
		}
		else
			tok = new Token(RELOP, MA); //>
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
			tok = new Token(RELOP, EQ);
		}
		else
			tok = new Token(OP, REC);
	}
	else if(entrada[pos] == '!'){
		pos++;
		if(entrada[pos] == '='){
			tok = new Token(RELOP, NEQ);
		}
		else
			ErroLexico(this->linha); //não sei se deixo isso aqui mesmo.
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
		ErroLexico(this->linha);
	
	return tok;
}

//Aviso de erro lexico
void Scanner::ErroLexico(int linha){
	cout<<"Erro Léxico na linha " << linha << endl ;
	//exit(EXIT_FAILURE);
}