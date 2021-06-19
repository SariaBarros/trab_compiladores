#include<iostream>
#include <string>

class First{

public:
static bool program(std::string nome){
    
}

static bool classList(std::string nome){
    if(nome == "class"){
        return true;
    }
    else
        return false;
}

static bool classList_Linha(std::string nome){
    if(nome == "class"){
        return true;
    }
    else
        return false;
}

static bool classDecl(std::string nome){
    if(nome == "class"){
        return true;
    }
    else
        return false;    
}

static bool classDecl_Linha(std::string nome){
    if(nome == "extends" or nome == "{"){
        return true;
    }
    else
        return false;
}

static bool classBody(std::string nome){
    if(nome == "{"){
        return true;
    }
    else
        return false;
}

static bool varDeclListOpt(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool varDeclList(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool varDeclList_Linha(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool varDecl(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool varDecl_Linha(std::string nome){
    if(nome == "[" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool varDeclOpt(std::string nome){
    if(nome == ","){
        return true;
    }
    else
        return false;
}

static bool type(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool constructDeclListOpt(std::string nome){
    if(nome == "constructor"){
        return true;
    }
    else
        return false;
}

static bool constructDeclList(std::string nome){
    if(nome == "constructor"){
        return true;
    }
    else
        return false;
}

static bool constructDeclList_Linha(std::string nome){
    if(nome == "constructor"){
        return true;
    }
    else
        return false;
}

static bool constructDecl(std::string nome){
    if(nome == "constructor"){
        return true;
    }
    else
        return false;
}

static bool methodDeclListOpt(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool methodDeclList(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool methodDeclList_Linha(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool methodDecl(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool methodDecl_Linha(std::string nome){
    if(nome == "[" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool methodBody(std::string nome){
    if(nome == "("){
        return true;
    }
    else
        return false;
}

static bool paramListOpt(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool paramList(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool paramList_Linha(std::string nome){
    if(nome == ","){
        return true;
    }
    else
        return false;
}

static bool param(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool param_Linha(std::string nome){
    if(nome == "[" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool statementsOpt(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"
    or nome == "break" or nome == ";" or nome == "print"
    or nome == "if" or nome == "super" or nome == "read" or 
    nome == "for" or nome == "return"){
        return true;
    }
    else
        return false;
}

static bool statements(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"
    or nome == "break" or nome == ";" or nome == "print"
    or nome == "if" or nome == "super" or nome == "read" or 
    nome == "for" or nome == "return"){
        return true;
    }
    else
        return false;
}

static bool statements_Linha(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"
    or nome == "break" or nome == ";" or nome == "print"
    or nome == "if" or nome == "super" or nome == "read" or 
    nome == "for" or nome == "return"){
        return true;
    }
    else
        return false;
}

static bool statement(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID"
    or nome == "break" or nome == ";" or nome == "print"
    or nome == "if" or nome == "super" or nome == "read" or 
    nome == "for" or nome == "return"){
        return true;
    }
    else
        return false;
}

static bool atribStat(std::string nome){
    if(nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool atribStat_Linha(std::string nome){
    if(nome == "new" or nome == "int" or nome == "string" or 
    nome == "ID" or nome == "+" or nome == "-"){
        return true;
    }
    else
        return false;
}

static bool printStat(std::string nome){
    if(nome == "print"){
        return true;
    }
    else
        return false;
}

static bool readStat(std::string nome){
    if(nome == "read"){
        return true;
    }
    else
        return false;
}

static bool returnStat(std::string nome){
    if(nome == "return"){
        return true;
    }
    else
        return false;
}

static bool superStat(std::string nome){
    if(nome == "super"){
        return true;
    }
    else
        return false;
}

static bool ifStat(std::string nome){
    if(nome == "if"){
        return true;
    }
    else
        return false;
}

static bool ifStat_Linha(std::string nome){
    if(nome == "else"){
        return true;
    }
    else
        return false;
}

static bool forStat(std::string nome){
    if(nome == "for"){
        return true;
    }
    else
        return false;
}

static bool atribStatOpt(std::string nome){
    if(nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool expressionOpt(std::string nome){
    if(nome == "+" or nome == "-"){
        return true;
    }
    else
        return false;
}

static bool lValue(std::string nome){
    if(nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool lValue_Linha(std::string nome){
    if(nome == "." or nome == "["){
        return true;
    }
    else
        return false;
}

static bool lValueComp(std::string nome){
    if(nome == "."){
        return true;
    }
    else
        return false;
}

static bool lValueComp_Linha(std::string nome){
    if(nome == "." or nome == "["){
        return true;
    }
    else
        return false;
}

static bool expression(std::string nome){
    if(nome == "+" or nome == "-"){
        return true;
    }
    else
        return false;
}

static bool expression_Linha(std::string nome){
    if(nome == "relop"){
        return true;
    }
    else
        return false;
}

static bool allocExpression(std::string nome){
    if(nome == "int" or nome == "string" or nome == "ID" or nome == "new"){
        return true;
    }
    else
        return false;
}

static bool numExpression(std::string nome){
    if(nome == "-" or nome == "+"){
        return true;
    }
    else
        return false;
}

static bool numExpression_Linha(std::string nome){
    if(nome == "-" or nome == "+"){
        return true;
    }
    else
        return false;
}

static bool term(std::string nome){
    if(nome == "-" or nome == "+"){
        return true;
    }
    else
        return false;
}

static bool term_Linha(std::string nome){
    if(nome == "*" or nome == "/"){
        return true;
    }
    else
        return false;
}

static bool unaryExpression(std::string nome){
    if(nome == "-" or nome == "+"){
        return true;
    }
    else
        return false;
}

static bool factor(std::string nome){
    if(nome == "INTEGER_LITERAL" or nome == "STRING_LITERAL" or nome == "(" or nome == "ID"){
        return true;
    }
    else
        return false;
}

static bool argList(std::string nome){
    if(nome == "-" or nome == "+"){
        return true;
    }
    else
        return false;
}

static bool argListOpt(std::string nome){
    if(nome == "-" or nome == "+"){
        return true;
    }
    else
        return false;
}

static bool argList_Linha(std::string nome){
    if(nome == ","){
        return true;
    }
    else
        return false;
}
};