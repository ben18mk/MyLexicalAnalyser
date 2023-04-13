#include "DFA.h"

#pragma warning (disable : 4996)
#pragma warning (disable : 6386)
#pragma warning (disable : 6387)

void q0(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops = 0;

	if (*strRaw == 'i')
		q1(strRaw + 1, to);
	else if (*strRaw >= 'a' && *strRaw <= 'h' ||
		*strRaw >= 'j' && *strRaw <= 'z' ||
		*strRaw >= 'A' && *strRaw <= 'Z' ||
		*strRaw == '_')
		q3(strRaw + 1, to);
	else if (*strRaw >= '0' && *strRaw <= '9')
		q4(strRaw + 1, to);
	else if (*strRaw == ' ' || *strRaw == '\t' || *strRaw == '\n')
		q5(strRaw + 1, to);
	else if (*strRaw == '(' || *strRaw == ')')
		q6(strRaw + 1, to);
	else if (*strRaw == '=')
		q7(strRaw + 1, to);
	else if (*strRaw == '>' || *strRaw == '<' || *strRaw == '!')
		q8(strRaw + 1, to);
	else if (*strRaw == '[' || *strRaw == ']')
		q10(strRaw + 1, to);
	else if (*strRaw == '{' || *strRaw == '}')
		q11(strRaw + 1, to);
	else if (*strRaw == '+' || *strRaw == '-' ||
		*strRaw == '/' || *strRaw == '%')
		q12(strRaw + 1, to);
	else if(*strRaw == '*')
		q13(strRaw + 1, to);
	else
		q_err(strRaw + 1, to);

	to->next = strRaw + to->nHops;
	
	to->value = (char*)malloc(sizeof(char) * (to->nHops + 1));
	strncpy_s(to->value, to->nHops + 1, strRaw, to->nHops);
}

void q1(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;

	if (*strRaw == 'f')
		q2(strRaw + 1, to);
	else if (*strRaw >= 'a' && *strRaw <= 'e' ||
		*strRaw >= 'g' && *strRaw <= 'z' ||
		*strRaw >= 'A' && *strRaw <= 'Z' ||
		*strRaw >= '0' && *strRaw <= '9' ||
		*strRaw == '_')
		q3(strRaw + 1, to);
	else
		to->tock = TOCK_ID;
}

void q2(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;

	if (*strRaw >= 'a' && *strRaw <= 'z' ||
		*strRaw >= 'A' && *strRaw <= 'Z' ||
		*strRaw >= '0' && *strRaw <= '9' ||
		*strRaw == '_')
		q3(strRaw + 1, to);
	else
		to->tock = TOCK_IF;
}

void q3(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;

	if (*strRaw >= 'a' && *strRaw <= 'z' ||
		*strRaw >= 'A' && *strRaw <= 'Z' ||
		*strRaw >= '0' && *strRaw <= '9' ||
		*strRaw == '_')
		q3(strRaw + 1, to);
	else
		to->tock = TOCK_ID;
}

void q4(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;

	if (*strRaw >= '0' && *strRaw <= '9')
		q4(strRaw + 1, to);
	else
		to->tock = TOCK_INT;
}

void q5(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;

	if (*strRaw == ' ' || *strRaw == '\t' || *strRaw == '\n')
		q5(strRaw + 1, to);
	else
		to->tock = TOCK_WS;
}

void q6(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;
	to->tock = TOCK_PAREN;
}

void q7(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;

	if (*strRaw == '=')
		q9(strRaw + 1, to);
	else
		to->tock = TOCK_ASSIGN;
}

void q8(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;

	if (*strRaw == '=')
		q9(strRaw + 1, to);
	else
		to->tock = TOCK_BOOLOP;
}

void q9(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;
	to->tock = TOCK_BOOLOP;
}

void q10(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;
	to->tock = TOCK_SBRACK;
}

void q11(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;
	to->tock = TOCK_CBRACK;
}

void q12(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;

	if (*strRaw == '=')
		q15(strRaw + 1, to);
	else
		to->tock = TOCK_REALOP;
}

void q13(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;

	switch (*strRaw)
	{
	case '*':
		q14(strRaw + 1, to);
		break;
	case '=':
		q15(strRaw + 1, to);
		break;
	default:
		to->tock = TOCK_REALOP;
		break;
	}
}

void q14(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;
	to->tock = TOCK_REALOP;
}

void q15(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;
	to->tock = TOCK_REALOPASSGN;
}

void q_err(char* strRaw, TOCKEN_OUT* to)
{
	to->nHops++;

	if (!(*strRaw >= 'a' && *strRaw <= 'z' ||
		*strRaw >= 'A' && *strRaw <= 'Z' ||
		*strRaw >= '0' && *strRaw <= '9' ||
		*strRaw == '_' || *strRaw == ' ' ||
		*strRaw == '\t' || *strRaw == '\n' ||
		*strRaw == '\0' || *strRaw == '(' || *strRaw == ')' ||
		*strRaw == '=' || *strRaw == '>' || *strRaw == '<' ||
		*strRaw == '!' || *strRaw == '[' || *strRaw == ']' ||
		*strRaw == '{' || *strRaw == '}' || *strRaw == '+' ||
		*strRaw == '-' || *strRaw == '/' || *strRaw == '%' ||
		*strRaw == '*'))
		q_err(strRaw + 1, to);
	else
		to->tock = TOCK_ERR;
}