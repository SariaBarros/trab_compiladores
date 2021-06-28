#pragma once
#include <iostream>
#include <string>
#include "tipos_de_token.h"
#include "Token.h"

class First{

public:
    static bool program(Token* token){
        return true;
    }

    static bool classList(Token* token){
        if(token->atributo == CLASS){
            return true;
        }
        else
            return false;
    }

    static bool classList_Linha(Token* token){
        if(token->atributo == CLASS){
            return true;
        }
        else
            return false;
    }

    static bool classDecl(Token* token){
        if(token->atributo == CLASS){
            return true;
        }
        else
            return false;    
    }

    static bool classDecl_Linha(Token* token){
        if(token->atributo == CLASS or token->atributo == ECHAV )
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
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool varDeclList(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool varDeclList_Linha(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool varDecl(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool varDecl_Linha(Token* token){
        if(token->atributo == ECOL or token->nome == ID){
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
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool constructDeclListOpt(Token* token){
        if(token->atributo == CNST){
            return true;
        }
        else
            return false;
    }

    static bool constructDeclList(Token* token){
        if(token->atributo == CNST){
            return true;
        }
        else
            return false;
    }

    static bool constructDeclList_Linha(Token* token){
        if(token->atributo == CNST){
            return true;
        }
        else
            return false;
    }

    static bool constructDecl(Token* token){
        if(token->atributo == CNST){
            return true;
        }
        else
            return false;
    }

    static bool methodDeclListOpt(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool methodDeclList(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool methodDeclList_Linha(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool methodDecl(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool methodDecl_Linha(Token* token){
        if(token->atributo == ECOL or token->nome == ID){
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
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool paramList(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID){
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
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool param_Linha(Token* token){
        if(token->atributo == ECOL or token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool statementsOpt(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID
        or token->atributo == BRK or token->atributo == PVIR or token->atributo == PRT
        or token->atributo == IF or token->atributo == SPR or token->atributo == READ or 
        token->atributo == FOR or token->atributo == RTN){
            return true;
        }
        else
            return false;
    }

    static bool statements(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID
        or token->atributo == BRK or token->atributo == PVIR or token->atributo == PRT
        or token->atributo == IF or token->atributo == SPR or token->atributo == READ or 
        token->atributo == FOR or token->atributo == RTN){
            return true;
        }
        else
            return false;
    }

    static bool statements_Linha(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID
        or token->atributo == BRK or token->atributo == PVIR or token->atributo == PRT
        or token->atributo == IF or token->atributo == SPR or token->atributo == READ or 
        token->atributo == FOR or token->atributo == RTN){
            return true;
        }
        else
            return false;
    }

    static bool statement(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID
        or token->atributo == BRK or token->atributo == PVIR or token->atributo == PRT
        or token->atributo == IF or token->atributo == SPR or token->atributo == READ or 
        token->atributo == FOR or token->atributo == RTN){
            return true;
        }
        else
            return false;
    }

    static bool atribStat(Token* token){
        if(token->nome == ID){
            return true;
        }
        else
            return false;
    }

    static bool atribStat_Linha(Token* token){
        if(token->atributo == NEW or token->atributo == INT or token->atributo == STRING or 
        token->nome == ID or token->atributo == SUM or token->atributo == DIF){
            return true;
        }
        else
            return false;
    }

    static bool printStat(Token* token){
        if(token->atributo == PRT)
            return true;
        else
            return false;
    }

    static bool readStat(Token* token){
        if(token->atributo == READ){
            return true;
        }
        else
            return false;
    }

    static bool returnStat(Token* token){
        if(token->atributo == RTN){
            return true;
        }
        else
            return false;
    }

    static bool superStat(Token* token){
        if(token->atributo == SPR){
            return true;
        }
        else
            return false;
    }

    static bool ifStat(Token* token){
        if(token->atributo == IF){
            return true;
        }
        else
            return false;
    }

    static bool ifStat_Linha(Token* token){
        if(token->atributo == ELSE){
            return true;
        }
        else
            return false;
    }

    static bool forStat(Token* token){
        if(token->atributo == FOR){
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
        if(token->nome == ID){
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
        if(token->nome == OP){
            return true;
        }
        else
            return false;
    }

    static bool allocExpression(Token* token){
        if(token->atributo == INT or token->atributo == STRING or token->nome == ID or token->atributo == NEW){
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
        if(token->nome == INTEGER_LITERAL or token->nome == STR or token->atributo == EPAR or token->nome == ID){
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