#pragma once

#include <string.h>
#include <stdlib.h>

typedef enum TOCKEN
{
	TOCK_ERR,
	TOCK_IF,
	TOCK_ID,
	TOCK_INT,
	TOCK_WS,
	TOCK_PAREN,
	TOCK_ASSIGN,
	TOCK_BOOLOP,
	TOCK_SBRACK,
	TOCK_CBRACK,
	TOCK_REALOP,
	TOCK_REALOPASSGN
} TOCKEN;

typedef struct TOCKEN_OUT
{
	TOCKEN tock;
	char* next;
	char* value;
	int nHops;
} TOCKEN_OUT;

void q0(char* strRaw, TOCKEN_OUT* to);
void q1(char* strRaw, TOCKEN_OUT* to);
void q2(char* strRaw, TOCKEN_OUT* to);
void q3(char* strRaw, TOCKEN_OUT* to);
void q4(char* strRaw, TOCKEN_OUT* to);
void q5(char* strRaw, TOCKEN_OUT* to);
void q6(char* strRaw, TOCKEN_OUT* to);
void q7(char* strRaw, TOCKEN_OUT* to);
void q8(char* strRaw, TOCKEN_OUT* to);
void q9(char* strRaw, TOCKEN_OUT* to);
void q10(char* strRaw, TOCKEN_OUT* to);
void q11(char* strRaw, TOCKEN_OUT* to);
void q12(char* strRaw, TOCKEN_OUT* to);
void q13(char* strRaw, TOCKEN_OUT* to);
void q14(char* strRaw, TOCKEN_OUT* to);
void q15(char* strRaw, TOCKEN_OUT* to);
void q_err(char* strRaw, TOCKEN_OUT* to);