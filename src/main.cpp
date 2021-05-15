#include "Scanner.h"

int main(int argc, char* argv[]){
    string* vetNomes;
    string input;

    vetNomes = new string[28];
    getline(cin, input);

    Scanner* scanner = new Scanner(input);

    Token* t;

    do{
        t = scanner->nextToken();
        cout << vetNomes[t->nome] << " ";
    }while(t->name != END_OF_FILE);

    return 0;
}