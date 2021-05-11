#pragma once
#include <iostream>
#include <ctype.h>
#include <string>

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
	END_OF_FILE //fim de arquivo 27
};

class Token
{
	public:
		int nome;
		int atributo;
		string* lexema;

		Token(int nome){
			this->nome = nome;
			atributo = UNDEF;
		}
		Token(int nome, int atrib){
			this->nome = nome;
			atributo = atrib;
		}
};