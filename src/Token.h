#pragma once
#include <iostream>
#include <ctype.h>
#include <string>
#include <fstream>
#include "tipos_de_token.h"

using namespace std;

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

			vetNomes = new string[44];
			vetNomes[0] = "UNDEF";
			vetNomes[1] = "ID";
			vetNomes[2] = "INTEGER_LITERAL"; 

			vetNomes[3] = "OP";
				vetNomes[4] = "SUM";
				vetNomes[5] = "DIF"; 
				vetNomes[6] = "MULT";
				vetNomes[7] = "DIV";
				vetNomes[8] = "MOD";
				vetNomes[9] = "REC";

			vetNomes[10] = "RELOP";
				vetNomes[11] = "MN";
				vetNomes[12] = "MA";
				vetNomes[13] = "MNE";
				vetNomes[14] = "MAE";
				vetNomes[15] = "EQ";
				vetNomes[16] = "NEQ";

			vetNomes[17] = "STR"; 

			vetNomes[18] = "SEP";
				vetNomes[19] = "EPAR";
				vetNomes[20] = "DPAR"; 
				vetNomes[21] = "ECOL";
				vetNomes[22] = "DCOL";
				vetNomes[23] = "ECHAV";
				vetNomes[24] = "DCHAV";
				vetNomes[25] = "PVIR";
				vetNomes[26] = "PNT";
				vetNomes[27] = "VIR"; 

			vetNomes[28] = "END_OF_FILE";

			vetNomes[29] = "RESERV";
				vetNomes[30] = "CLASS";
				vetNomes[31] =	"EXTND";
				vetNomes[32] =	"INT";
				vetNomes[33] =	"STRING";
				vetNomes[34] =	"BRK";
				vetNomes[35] =	"PRT";
				vetNomes[36] =	"READ";
				vetNomes[37] =	"RTN";
				vetNomes[38] =	"SPR";
				vetNomes[39] =	"IF";
				vetNomes[40] =  "ELSE";
				vetNomes[41] =	"FOR";
				vetNomes[42] =	"NEW";
				vetNomes[43] =	"CNST";

			if(nome == ID or nome == STR or nome == INTEGER_LITERAL){
				cout<<vetNomes[nome]<< "("<<lexema<<") ";
			}
			else{
				cout<<vetNomes[nome]<<"("<< vetNomes[atributo] << ") ";
			}
		}
};