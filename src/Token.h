#pragma once
#include <iostream>
#include <ctype.h>
#include <string>
#include <fstream>

using namespace std;

enum TiposDeToken
{	
	UNDEF,	//INDEFINIDO 0

	ID,		//IDENTIFICADOR 1
	INTEGER_LITERAL,//INTEIRO 2

	OP,		//OPERADORES 3
	MN,		//MENOR 4
	MA,		//MAIOR 5
	MNE,	//MENOR IGUAL 6
	MAE,	//MAIOR IGUAL 7
	EQ,		//IGUALDADE 8
	NEQ,	// !IGUALDADE 9
	SUM,	//SOMA 10
	DIF,	//SUBTRAÇÃO 11
	MULT,	//MULTIPLICAÇÃO 12
	DIV,	//DIVISÃO 13
	MOD,	//RESTO 14
	REC,	//ATRIBUIÇÃO 15

	STR,	//STRING 16

	SEP,	//SEPARADORES 17
	EPAR,	//PARENTESE ESQUERDO 18
	DPAR,	//PARENTESE DIREITO 19
	ECOL,	//COLCHETE ESQUERDO 20
	DCOL,	//COLCHETE DIREITO 21
	ECHAV,	//CHAVE ESQUERDA 22
	DCHAV,	//CHAVE DIREITA 23
	PVIR, 	//PONTO E VIRGULA 24
	PNT, 	//PONTO 25
	VIR,	//VIRGULA 26
	END_OF_FILE, //fim de arquivo 27
	COMENTARIO

};

class Token
{
	public:
		int nome;
		int atributo;
		string lexema;

		Token(int nome){
			this->nome = nome;
			atributo = UNDEF;
		}
		Token(int nome, int atrib){
			this->nome = nome;
			atributo = atrib;
		}
		Token(int nome, string lexema){
			this->nome = nome;
			this->lexema = lexema;

		}
		Token(int nome, int atrib, string lexema){
			this->nome = nome;
			this->atributo = atrib;
			this->lexema = lexema;
		}
		void ToString(){
			string* vetNomes;

			vetNomes = new string[29];
			vetNomes[0] = "UNDEF";
			vetNomes[1] = "ID";
			vetNomes[2] = "INTEGER_LITERAL"; 
			vetNomes[3] = "OP";
			vetNomes[4] = "MN";
			vetNomes[5] = "MA"; 
			vetNomes[6] = "MNE";
			vetNomes[7] = "MAE";
			vetNomes[8] = "EQ";
			vetNomes[9] = "NEQ";
			vetNomes[10] = "SUM";
			vetNomes[11] = "DIF";
			vetNomes[12] = "MULT";
			vetNomes[13] = "DIV";
			vetNomes[14] = "MOD";
			vetNomes[15] = "REC";
			vetNomes[16] = "STR";
			vetNomes[17] = "SEP"; 
			vetNomes[18] = "EPAR";
			vetNomes[19] = "DPAR";
			vetNomes[20] = "ECOL"; 
			vetNomes[21] = "DCOL";
			vetNomes[22] = "ECHAV";
			vetNomes[23] = "DCHAV";
			vetNomes[24] = "PVIR";
			vetNomes[25] = "PNT";
			vetNomes[26] = "VIR"; 
			vetNomes[27] = "END_OF_FILE";
			vetNomes[28] = "COMENTARIO";
			
			if(nome == 1){
			cout<<vetNomes[nome]<< "("<<lexema<<") ";
			}
			else if(nome == 16){
			cout<<vetNomes[nome]<< "("<<lexema<<") ";
			}
			else if(nome == 2){
			cout<<vetNomes[nome]<< "("<<lexema<<") ";
			}
			else
				cout<<vetNomes[nome]<< " ";
		}
};