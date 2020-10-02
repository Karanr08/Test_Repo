/*

Karan Raj Kakwani
18CS10025
Assignment-3

*/

%{
	#define ESCAPE_SEQUENCE 101
	#define PUNCTUATOR 102
	#define KEYWORD 103
	#define COMMENT 104
	#define IDENTIFIER 105
	#define CHARACTER 106
	#define STRING 107
	#define INTEGER 108
	#define FLOAT_CONST 109
	#define COMMENT_END 110

%}


KEYWORD 	"break"|"case"|"char"|"continue"|"default"|"do"|"double"|"else"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"return"|"short"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"void"|"while"



ALPHABETS	[a-zA-Z_]
DIGITS		[0-9]




/*							CONSTANTS 				*/



DIGIT_SEQUENCE				{DIGITS}+

NON_ZERO_DIGITS 			[1-9]



SPACES 						[ \t\n\v\f]

SIGN 						[+-]

ESCAPE_SEQUENCES			\\['"?\\abfnrtv]										

IDENTIFIERS					{ALPHABETS}({ALPHABETS}|{DIGITS})*

INTEGER_CONSTANTS			{NON_ZERO_DIGITS}{DIGITS}*|0

FRACTION					(({DIGITS}+)?\.{DIGITS}+)|(({DIGITS}+)\.)		

EXPONENT 					([Ee][+-]?{DIGITS}+)

FLOATING_CONSTANTS			({FRACTION}{EXPONENT}?)|({DIGITS}+{EXPONENT})


C_CHAR 						[^'\\\n]|{ESCAPE_SEQUENCES}

C_CHAR_SEQUENCE 			{C_CHAR}*

CHARACTER_CONSTANT 			\'{C_CHAR_SEQUENCE}\'




/*					STRING LITERALS 			*/

S_CHAR 						[^"\\\n]|{ESCAPE_SEQUENCES}

S_CHAR_SEQUENCE 			{S_CHAR}+

STRING 						\"{S_CHAR_SEQUENCE}?\"



/*							5 PUNCTUATORS						*/

PUNCTUATOR					"["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#"




/* 							COMMENTS						*/


COMMENT 				\/\*([^*]|\*+[^*/])*\*\/|\/\/(.*)



%%
{COMMENT} 				{return COMMENT;}
{KEYWORD}					{ return KEYWORD;}
{STRING} 					{ return STRING; }
{IDENTIFIERS}				{ return IDENTIFIER; }
{INTEGER_CONSTANTS} 		{ return INTEGER; }

{CHARACTER_CONSTANT} 		{ return CHARACTER; }
{SPACES}					
{ESCAPE_SEQUENCES} 			{ return ESCAPE_SEQUENCE;}
{PUNCTUATOR}				{ return PUNCTUATOR;}
{FLOATING_CONSTANTS} 		{ return FLOAT_CONST; }

%%
