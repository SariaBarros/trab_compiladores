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
        void classList_Linha();
        void classDecl();
        void classDecl_Linha();
        void classBody();

        void varDecl();
        void varDecl_Linha();
        void varDeclOpt();
        void varDeclList();
        void varDeclList_Linha();
        void varDeclListOpt();        

        void constructDecl();
        void constructDeclListOpt();
        void constructDeclList();
        void constructDeclList_Linha();

        void term();
        void term_Linha();
        void type();
        void factor();

        void methodBody();
        void methodDecl();
        void methodDecl_Linha();
        void methodDeclList();
        void methodDeclList_Linha();
        void methodDeclListOpt();
        
        void param();
        void param_Linha();
        void paramList();
        void paramList_Linha();
        void paramListOpt();
        
        void statement();
        void statements();
        void statements_Linha();
        void statementsOpt();

        void atribStat();
        void atribStat_Linha();
        void atribStatOpt();
        
        void printStat();
        void readStat();
        void returnStat();
        void superStat();
        void ifStat();
        void ifStat_Linha();
        void forStat();

        void lValue();
        void lValue_Linha();
        void lValueComp();
        void lValueComp_Linha();

        void expression();
        void expression_Linha();
        void expressionOpt();
        void allocExpression();
        void numExpression();
        void numExpression_Linha();
        void unaryExpression();
        
        void argList();
        void argList_Linha();
        void argListOpt();


    public:
        Parser(string*);
        void run();
};