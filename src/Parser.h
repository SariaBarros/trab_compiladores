#include "Scanner.h"

class Parser{
    private:
        Scanner* scanner;
        Token* lToken;

        void advance();
        void matchN(int);
        void matchA(int);
        void erro();

        void program();

        void classList();
        void classListLinha();
        void classDecl();
        void classDeclLinha();
        void classBody();

        void varDecl();
        void varDeclLinha();
        void varDeclOpt();
        void varDeclList();
        void varDeclListLinha();
        void varDeclListOpt();        

        void constructDecl();
        void constructDeclListOpt();
        void constructDeclList();
        void constructDeclListLinha();

        void term();
        void termLinha();
        void type();
        void factor();

        void methodBody();
        void methodDecl();
        void methodDeclLinha();
        void methodDeclList();
        void methodDeclListLinha();
        void methodDeclListOpt();
        
        void param();
        void paramLinha();
        void paramList();
        void paramListLinha();
        void paramListOpt();
        
        void statement();
        void statements();
        void statementsLinha();
        void statementsOpt();

        void atribStat();
        void atribStatLinha();
        void atribStatOpt();
        
        void printStat();
        void readStat();
        void returnStat();
        void superStat();
        void ifStat();
        void ifStatLinha();
        void forStat();

        void lValue();
        void lValueLinha();
        void lValueComp();
        void lValueCompLinha();

        void expression();
        void expressionLinha();
        void expressionOpt();
        void allocExpression();
        void numExpression();
        void numExpressionLinha();
        void unaryExpression();
        
        void argList();
        void argListLinha();
        void argListOpt();


    public:
        Parser(string);
        void run();
};