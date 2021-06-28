#pragma once
enum TiposDeToken
{	
	UNDEF,	//INDEFINIDO 0
	ID,		//IDENTIFICADOR 1
	INTEGER_LITERAL,//INTEIRO 2

	OP,		//OPERADORES 3
		SUM,	//SOMA 4
		DIF,	//SUBTRAÇÃO 5
		MULT,	//MULTIPLICAÇÃO 6
		DIV,	//DIVISÃO 7
		MOD,	//RESTO 8
		REC,	//ATRIBUIÇÃO 9

	RELOP, //OPERADOR RELACIONAL 10
		MN,		//MENOR 11
		MA,		//MAIOR 12
		MNE,	//MENOR IGUAL 13
		MAE,	//MAIOR IGUAL 14
		EQ,		//IGUALDADE 15
		NEQ,	//!IGUALDADE 16
	
	STR,	//STRING 17
	
	SEP,	//SEPARADORES 18
		EPAR,	//PARENTESE ESQUERDO 19
		DPAR,	//PARENTESE DIREITO 20
		ECOL,	//COLCHETE ESQUERDO 21
		DCOL,	//COLCHETE DIREITO 22
		ECHAV,	//CHAVE ESQUERDA 23
		DCHAV,	//CHAVE DIREITA 24
		PVIR, 	//PONTO E VIRGULA 25
		PNT, 	//PONTO 26
		VIR,	//VIRGULA 27

	END_OF_FILE, //FIM DE ARQUIVO 28
	

	RESERV,//PALAVRAS RESERVADAS 29
		CLASS, 	//CLASS 30
		EXTND, 	//EXTENDS 31
		INT, 	//INT 32
		STRING, //STRING 33
		BRK, 	//BREAK 34
		PRT,	//PRINT 35
		READ,	//READ 36
		RTN,	//RETURN 37
		SPR,	//SUPER 38
		IF,		//IF 39
		ELSE,	//ELSE 40
		FOR,	//FOR 41
		NEW,	//NEW 42
		CNST,	//CONSTRUTOR 43
};
