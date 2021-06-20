#include<iostream>
#include <string>
#include "tipos_de_token.h"

class First{

public:
    static bool program(Token* token){
        return true;
    }

    static bool classList(Token* token){
        if(token->lexema == "class"){
            return true;
        }
        else
            return false;
    }

    static bool classList_Linha(Token* token){
        if(token->lexema == "class"){
            return true;
        }
        else
            return false;
    }

    static bool classDecl(Token* token){
        if(token->lexema == "class"){
            return true;
        }
        else
            return false;    
    }

    static bool classDecl_Linha(Token* token){
        if(token->lexema == "class" or token->atributo == ECHAV )
        {
            return true;
        }
        else
            return false;
    }

    static bool classBody(Token* token){
        if(token->atributo == ECHAV){
            return true;
        }
        else
            return false;
    }

    static bool varDeclListOpt(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool varDeclList(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool varDeclList_Linha(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool varDecl(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool varDecl_Linha(Token* token){
        if(token->atributo == ECOL or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool varDeclOpt(Token* token){
        if(token->atributo == VIR){
            return true;
        }
        else
            return false;
    }

    static bool type(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool constructDeclListOpt(Token* token){
        if(token->lexema == "constructor"){
            return true;
        }
        else
            return false;
    }

    static bool constructDeclList(Token* token){
        if(token->lexema == "constructor"){
            return true;
        }
        else
            return false;
    }

    static bool constructDeclList_Linha(Token* token){
        if(token->lexema == "constructor"){
            return true;
        }
        else
            return false;
    }

    static bool constructDecl(Token* token){
        if(token->lexema == "constructor"){
            return true;
        }
        else
            return false;
    }

    static bool methodDeclListOpt(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool methodDeclList(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool methodDeclList_Linha(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool methodDecl(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool methodDecl_Linha(Token* token){
        if(token->atributo == ECOL or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool methodBody(Token* token){
        if(token->atributo == EPAR){
            return true;
        }
        else
            return false;
    }

    static bool paramListOpt(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool paramList(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool paramList_Linha(Token* token){
        if(token->atributo == VIR){
            return true;
        }
        else
            return false;
    }

    static bool param(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool param_Linha(Token* token){
        if(token->atributo == ECOL or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool statementsOpt(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID
        or token->lexema == "break" or token->atributo == PVIR or token->lexema == "print"
        or token->lexema == "if" or token->lexema == "super" or token->lexema == "read" or 
        token->lexema == "for" or token->lexema == "return"){
            return true;
        }
        else
            return false;
    }

    static bool statements(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID
        or token->lexema == "break" or token->atributo == PVIR or token->lexema == "print"
        or token->lexema == "if" or token->lexema == "super" or token->lexema == "read" or 
        token->lexema == "for" or token->lexema == "return"){
            return true;
        }
        else
            return false;
    }

    static bool statements_Linha(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID
        or token->lexema == "break" or token->atributo == PVIR or token->lexema == "print"
        or token->lexema == "if" or token->lexema == "super" or token->lexema == "read" or 
        token->lexema == "for" or token->lexema == "return"){
            return true;
        }
        else
            return false;
    }

    static bool statement(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID
        or token->lexema == "break" or token->atributo == PVIR or token->lexema == "print"
        or token->lexema == "if" or token->lexema == "super" or token->lexema == "read" or 
        token->lexema == "for" or token->lexema == "return"){
            return true;
        }
        else
            return false;
    }

    static bool atribStat(Token* token){
        if(token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool atribStat_Linha(Token* token){
        if(token->lexema == "new" or token->lexema == "int" or token->lexema == "string" or 
        token->name == ID or token->atributo == SUM or token->atributo == MIN){
            return true;
        }
        else
            return false;
    }

    static bool printStat(Token* token){
        if(token->lexema == "print"){
            return true;
        }
        else
            return false;
    }

    static bool readStat(Token* token){
        if(token->lexema == "read"){
            return true;
        }
        else
            return false;
    }

    static bool returnStat(Token* token){
        if(token->lexema == "return"){
            return true;
        }
        else
            return false;
    }

    static bool superStat(Token* token){
        if(token->lexema == "super"){
            return true;
        }
        else
            return false;
    }

    static bool ifStat(Token* token){
        if(token->lexema == "if"){
            return true;
        }
        else
            return false;
    }

    static bool ifStat_Linha(Token* token){
        if(token->lexema == "else"){
            return true;
        }
        else
            return false;
    }

    static bool forStat(Token* token){
        if(token->lexema == "for"){
            return true;
        }
        else
            return false;
    }

    static bool atribStatOpt(Token* token){
        if(token->atributo == ID){
            return true;
        }
        else
            return false;
    }

    static bool expressionOpt(Token* token){
        if(token->atributo == SUM or token->atributo == DIF){
            return true;
        }
        else
            return false;
    }

    static bool lValue(Token* token){
        if(token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool lValue_Linha(Token* token){
        if(token->atributo == PNT or token->atributo == ECOL){
            return true;
        }
        else
            return false;
    }

    static bool lValueComp(Token* token){
        if(token->atributo == PNT){
            return true;
        }
        else
            return false;
    }

    static bool lValueComp_Linha(Token* token){
        if(token->atributo == PNT or token->atributo == ECOL){
            return true;
        }
        else
            return false;
    }

    static bool expression(Token* token){
        if(token->atributo == SUM or token->atributo == DIF){
            return true;
        }
        else
            return false;
    }

    static bool expression_Linha(Token* token){
        if(token->name == OP){
            return true;
        }
        else
            return false;
    }

    static bool allocExpression(Token* token){
        if(token->lexema == "int" or token->lexema == "string" or token->name == ID or token->lexema == "new"){
            return true;
        }
        else
            return false;
    }

    static bool numExpression(Token* token){
        if(token->atributo == DIF or token->atributo == SUM){
            return true;
        }
        else
            return false;
    }

    static bool numExpression_Linha(Token* token){
        if(token->atributo == DIF or token->atributo == SUM){
            return true;
        }
        else
            return false;
    }

    static bool term(Token* token){
        if(token->atributo == DIF or token->atributo == SUM){
            return true;
        }
        else
            return false;
    }

    static bool term_Linha(Token* token){
        if(token->atributo == MULT or token->atributo == DIV){
            return true;
        }
        else
            return false;
    }

    static bool unaryExpression(Token* token){
        if(token->atributo == DIF or token->atributo == SUM){
            return true;
        }
        else
            return false;
    }

    static bool factor(Token* token){
        if(token->name == INTEGER_LITERAL or token->name == STR or token->atributo == EPAR or token->name == ID){
            return true;
        }
        else
            return false;
    }

    static bool argList(Token* token){
        if(token->atributo == DIF or token->atributo == SUM){
            return true;
        }
        else
            return false;
    }

    static bool argListOpt(Token* token){
        if(token->atributo == DIF or token->atributo == SUM){
            return true;
        }
        else
            return false;
    }

    static bool argList_Linha(Token* token){
        if(token->atributo == VIR){
            return true;
        }
        else
            return false;
    }
};