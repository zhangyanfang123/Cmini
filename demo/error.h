//中文乱码了，弃用
//#ifndef ERROR_H
//#define ERROR_H
//#include"global.h"

//#include<iostream>
//using namespace std;

//enum LexError
//{
//    STR_NO_R_QUTION,
//    NUM_BIN_TYPE,
//    NUM_HEX_TYPE,
//    CHAR_NO_R_QUTION,
//    CHAR_NO_DATA,
//    OR_NO_PAIR,
//    COMMMENT_NO_END,
//    TOKEN_NO_EXIST
//};
//enum SynError{
//    TYPE_LOST,    TYPE_WRONG,
//    ID_LOST, ID_WRONG,
//    NUM_LOST,NUM_WRONG,
//    LITERAL_LOST,LITERAL_WRONG,
//    COMMMA_LOST,COMMMA_WRONG,
//    SEMICON_LOST,SEMICON_WRONG,
//    ASSIGN_LOST,ASSIGN_WRONG,
//    COLON_LOST,COLON_WRONG,
//    WHILE_LOST,WHILE_WRONG,
//    LPAREN_LOST,LPAREN_WRONG,
//    RPAREN_LOST,RPAREN_WRONG,
//    LBRACK_LOST,LBRACK_WRONG,
//    RBRACK_LOST,RBRACK_WRONG,
//    LBRACE_LOST,LBRACE_WRONG,
//    RBRACE_LOST,RBRACE_WRONG
//};

//enum SemError{
//    VAR_RE_DEF,
//    FUN_RE_DEF,
//    VAR_UN_DEC,
//    FUN_UN_DEC,
//    FUN_DEC_ERR,
//    FUN_CALL_ERR,
//    DEC_INIT_DENY,
//    EXTERN_FUN_DEF,
//    ARRAY_LEN_INVALID,
//    VAR_INIT_ERR,
//    GLB_INIT_ERR,
//    VOID_VAR,
//    EXPR_NOT_LEFT_VAL,
//    ASSIGN_TYPE_ERR,
//    EXPR_IS_BASE,
//    EXPR_NOT_BASE,
//    ARR_TYPE_ERR,
//    EXPR_IS_VOID,
//    BREAK_ERR,
//    CONTINUE_ERR,
//    RETURN_ERR
//};

//enum SemWarn{
//    FUN_DEC_CONFLICT,
//    FUN_RET_CONFLICT,
//    PTR_SEG_FAULT
//};
//class Error
//{
//public:
//    static void LexError(int code)
//    {
//        static const char *lexErrorTable[]=
//        {
//            "字符串丢失右向导",
//            "二进制数没有实体数据",
//            "十六进制数据没有实体数据",
//            "字符丢失右单引号",
//            "不支持空字符",
//            "错误的'|'运算符",
//            "多行注释没有正常结束",
//            "词法记号不存在"
//        };
//        errorNum++;
//        highlight("",ERRORCOLOR);
//        errorjilu<<lex->getFileName(true)<<" <"<<lex->getLineNum()<<"行,"<<lex->getColNum()<<"列> 词法错误:"<<lexErrorTable[code]<<".\n";
//        highlight("",NORMAL);
//    }
//    static void SynError(int code,Token* t)
//    {
//        static const char *synErrorTable[] =
//        {
//            "类型",
//            "标识符",
//            "数组长度",
//            "常量",
//            "逗号",
//            "分号",
//            "=",
//            "冒号",
//            "while",
//            "(",
//            ")",
//            "[",
//            "]",
//            "{",
//            "}"
//        };
//        errorNum++;
//        highlight("",ERRORCOLOR);
//        if(code%2==0)  {errorjilu<<lex->getFileName(true)<<" <"<<lex->getLineNum()<<"行> 语法错误: 在 ";
//                        errorjilu<< t->toString()<<" 之前丢失"<<synErrorTable[code/2]<<endl;}

//        else errorjilu<<lex->getFileName(true)<<" <"<<lex->getLineNum()<<"行> 语法错误: 在 "<< t->toString()<<" 处没有正确匹配"<<synErrorTable[code/2]<<endl;
//        highlight("",NORMAL);
//    }
//    static void SemError(int code,string name)
//    {
//        static const char *SemErrorTable[]={
//            "变量重定义",
//            "函数重定义",
//            "变量未声明",
//            "函数未声明",
//            "函数声明与定义不匹配",
//            "函数形参与实参不匹配",
//            "变量声明时不允许初始化",
//            "函数定义不能使用保留字extern",
//            "数组长度应该是正整数",
//            "变量初始化类型错误",
//            "全局变量初始化不是常量",
//            "变量不能声明为void类型",
//            "无效的左值表达式",
//            "赋值表达式不兼容",
//            "表达式操作数不能是基本类型",
//            "表达式操作数不是基本类型",
//            "数组索引运算类型错误",
//            "void的函数返回值不能参与表达式运算",
//            "break语句不能出现在循环或switch语句之外",
//            "continue语句不能出现在循环之外",
//            "return语句和函数返回值类型不匹配"
//        };
//        errorNum++;
//        highlight("",ERRORCOLOR);
//        errorjilu<<lex->getFileName(true)<<" <"<<lex->getLineNum()<<"行> 语义错误: "<< name<<" "<<SemErrorTable[code]<<endl;
//        highlight("",NORMAL);
//    }
//    static void SemWarn(int code,string name)
//    {
//        static const char *SemWarnTable[]={
//            "函数参数列表类型冲突",
//            "函数返回值类型不精确匹配",
//            "极有可能发生Segmentation Fault"
//        };
//        warnNum++;
//        highlight("",WARNINGCOLOR);
//        errorjilu<<lex->getFileName(true)<<" <"<<lex->getLineNum()<<"行> 语义警告: "<< name<<" "<<SemWarnTable[code]<<endl;
//        highlight("",NORMAL);
//    }
//};
//#define LEXERROR Error::LexError
//#define SYNERROR Error::SynError
//#define SEMERROR Error::SemError
//#define SEMWARN Error::SemWarn
//#endif // ERROR_H
#ifndef ERROR_H
#define ERROR_H
#include"global.h"

#include<iostream>
using namespace std;

enum LexError
{
    STR_NO_R_QUTION,
    NUM_BIN_TYPE,
    NUM_HEX_TYPE,
    CHAR_NO_R_QUTION,
    CHAR_NO_DATA,
    OR_NO_PAIR,
    COMMMENT_NO_END,
    TOKEN_NO_EXIST
};
enum SynError{
    TYPE_LOST,    TYPE_WRONG,
    ID_LOST, ID_WRONG,
    NUM_LOST,NUM_WRONG,
    LITERAL_LOST,LITERAL_WRONG,
    COMMMA_LOST,COMMMA_WRONG,
    SEMICON_LOST,SEMICON_WRONG,
    ASSIGN_LOST,ASSIGN_WRONG,
    COLON_LOST,COLON_WRONG,
    WHILE_LOST,WHILE_WRONG,
    LPAREN_LOST,LPAREN_WRONG,
    RPAREN_LOST,RPAREN_WRONG,
    LBRACK_LOST,LBRACK_WRONG,
    RBRACK_LOST,RBRACK_WRONG,
    LBRACE_LOST,LBRACE_WRONG,
    RBRACE_LOST,RBRACE_WRONG
};

enum SemError{
    VAR_RE_DEF,
    FUN_RE_DEF,
    VAR_UN_DEC,
    FUN_UN_DEC,
    FUN_DEC_ERR,
    FUN_CALL_ERR,
    DEC_INIT_DENY,
    EXTERN_FUN_DEF,
    ARRAY_LEN_INVALID,
    VAR_INIT_ERR,
    GLB_INIT_ERR,
    VOID_VAR,
    EXPR_NOT_LEFT_VAL,
    ASSIGN_TYPE_ERR,
    EXPR_IS_BASE,
    EXPR_NOT_BASE,
    ARR_TYPE_ERR,
    EXPR_IS_VOID,
    BREAK_ERR,
    CONTINUE_ERR,
    RETURN_ERR
};

enum SemWarn{
    FUN_DEC_CONFLICT,
    FUN_RET_CONFLICT,
    PTR_SEG_FAULT
};
class Error
{
public:
    static void LexError(int code)
    {
        static const char *lexErrorTable[]=
        {
            "string missing right Wizard",
                       "binary numbers have no physical data",
                       "hexadecimal data has no entity data",
                       "character lost right single quote",
                       "does not support null characters",
                       "wrong '|' operator",
                       "multi-line comments do not end normally",
                       "the lexical notation does not exist"
        };
        errorNum++;
        highlight("",ERRORCOLOR);
         errorjilu<<lex->getFileName(true)<<" <"<<lex->getLineNum()<<"Line,"<<lex->getColNum()<<"Column> Lexical Error:"<<lexErrorTable[code]<<".\n";
        //errorjilu<<lex->getFileName(true)<<" <"<<lex->getLineNum()<<"行,"<<lex->getColNum()<<"列> 词法错误:"<<lexErrorTable[code]<<".\n";
        highlight("",NORMAL);
    }
    static void SynError(int code,Token* t)
    {
        static const char *synErrorTable[] =
        {
            "types ",
                    "identifier",
                    "array length",
                    "constant",
                    "comma",
                    "semicolon",
                    "=",
                    "colon",
                    "while",
                    "(",
                    ")",
                    "[",
                    "]",
                    "{",
                    "}"
        };
        errorNum++;
        highlight("",ERRORCOLOR);
        if(code%2==0)  {errorjilu<<lex->getFileName(true)<<" <"<<lex->getLineNum()<<"Line> Syntactic Error: Missed ";
            errorjilu<<synErrorTable[code/2]<<" before "<< t->toString()<<endl;}

        else errorjilu<<lex->getFileName(true)<<" <"<<lex->getLineNum()<<"Line> Syntactic Error: Mismatched "<<synErrorTable[code/2]<<" at "<< t->toString()<<endl;
        highlight("",NORMAL);
    }
    static void SemError(int code,string name)
    {
        static const char *SemErrorTable[]={
            "variable redefinition",
                                           "function redefinition",
                                           "the variable is not declared",
                                           "the function is not declared",
                                           "the function declaration does not match the definition",
                                           "functional form participates in actual parameter mismatch",
                                           "initialization is not allowed when the variable is declared",
                                           "the function definition cannot use the reserved word extern",
                                           "the length of the array should be a positive integer",
                                           "the variable initialization type is incorrect",
                                           "global variable initialization is not a constant",
                                           "the variable cannot be declared as a void type",
                                           "invalid lvalue expression",
                                           "the assignment expression is not compatible",
                                           "the expression operand cannot be a primitive type",
                                           "the expression operand is not a primitive type",
                                           "array index operation type is wrong",
                                           "the return value of a void function cannot participate in an expression operation",
                                           "the break statement cannot appear outside of a loop or switch statement."
                                           "the continue statement cannot appear outside the loop",
                                           "return statement and function return value type do not match"
        };
        errorNum++;
        highlight("",ERRORCOLOR);
        errorjilu<<lex->getFileName(true)<<" <"<<lex->getLineNum()<<"Line> Semantic Error: "<< name<<" "<<SemErrorTable[code]<<endl;
        highlight("",NORMAL);
    }
    static void SemWarn(int code,string name)
    {
        static const char *SemWarnTable[]={
            "function parameter list type conflict",
                     "function return value type does not match exactly",
                    "the Segmentation fault is very likely to occur"
        };
        warnNum++;
        highlight("",WARNINGCOLOR);
        errorjilu<<lex->getFileName(true)<<" <"<<lex->getLineNum()<<"Line> Semantic Warning: "<< name<<" "<<SemWarnTable[code]<<endl;
        highlight("",NORMAL);
    }
};
#define LEXERROR Error::LexError
#define SYNERROR Error::SynError
#define SEMERROR Error::SemError
#define SEMWARN Error::SemWarn
#endif // ERROR_H
