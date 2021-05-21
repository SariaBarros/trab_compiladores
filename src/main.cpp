#include "Scanner.h"

int main(int argc, char* argv[]){
    string* vetNomes;
    string input;

    vetNomes = new string[28];
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

    getline(cin, input);

    Scanner* scanner = new Scanner(input);

    Token* t;

    do{
        t = scanner->nextToken();
        cout << vetNomes[t->nome] << " ";
    }while(t->nome != END_OF_FILE);

    //Chamar o destrutor.

    return 0;
}