#include "Scanner.h"

class Parser{
    private:
        Scanner* scanner;
        Token* lToken;

        void advance();
        void match(int);
        void erro();

        void program();

        void classList();
        void classDecl();
        void classBody();

        void varDecl();
        void varDeclOpt();
        void varDeclList();
        void varDeclListOpt();        

        void constructDecl();
        void constructDeclListOpt();
        void constructDeclList();

        void term();
        void type();
        void factor();

        void methodBody();
        void methodDecl();
        void methodDeclList();
        void methodDeclListOpt();
        
        void param();
        void paramList();
        void paramListOpt();
        
        void statement();
        void statements();
        void statementsOpt();

        void atribStat();
        void atribStatOpt();
        
        void printStat();
        void readStat();
        void returnStat();
        void superStat();
        void ifStat();
        void forStat();

        void lValue();
        void lValueComp();

        void expression();
        void expressionOpt();
        void allocExpression();
        void numExpression();
        void unaryExpression();
        
        void argList();
        void argListOpt();


    public:
        Parser(string*);
        void run();
};