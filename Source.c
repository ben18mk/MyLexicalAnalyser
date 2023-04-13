#pragma warning (disable : 4996) 
#pragma warning (disable : 6386)
#pragma warning (disable : 6387)

#include <stdio.h>
#include "DFA.h"

#define SRC_FILE "src.lang"
#define DST_FILE "src.lang.lexic"

int main()
{
	FILE* fpSrc = fopen(SRC_FILE, "r");
	int nFileSize;

	fseek(fpSrc, 0L, SEEK_END);
	nFileSize = (int)ftell(fpSrc);
	fseek(fpSrc, 0L, SEEK_SET);

	char* strRaw = (char*)malloc(sizeof(char) * (nFileSize));
	fread(strRaw, sizeof(strRaw), nFileSize, fpSrc);
	*(strRaw + nFileSize - 1) = '\0';

	FILE* fpDst = fopen(DST_FILE, "w");
	TOCKEN_OUT to;

	do
	{
		q0(strRaw, &to);
		
		switch (to.tock)
		{
		case TOCK_ERR:
			fprintf(fpDst, "TOCK_ERR (\"%s\")\n", to.value);
			break;
		case TOCK_IF:
			fprintf(fpDst, "TOCK_IF (\"%s\")\n", to.value);
			break;
		case TOCK_ID:
			fprintf(fpDst, "TOCK_ID (\"%s\")\n", to.value);
			break;
		case TOCK_INT:
			fprintf(fpDst, "TOCK_INT (\"%s\")\n", to.value);
			break;
		case TOCK_WS:
			switch (*to.value)
			{
			case ' ':
				fprintf(fpDst, "TOCK_WS (\" \")\n");
				break;
			case '\t':
				fprintf(fpDst, "TOCK_WS (\"\\t\")\n");
				break;
			case '\n':
				fprintf(fpDst, "TOCK_WS (\"\\n\")\n");
				break;
			}
			break;
		case TOCK_PAREN:
			fprintf(fpDst, "TOCK_PAREN (\"%s\")\n", to.value);
			break;
		case TOCK_ASSIGN:
			fprintf(fpDst, "TOCK_ASSIGN (\"%s\")\n", to.value);
			break;
		case TOCK_BOOLOP:
			fprintf(fpDst, "TOCK_BOOLOP (\"%s\")\n", to.value);
			break;
		case TOCK_SBRACK:
			fprintf(fpDst, "TOCK_SBRACK (\"%s\")\n", to.value);
			break;
		case TOCK_CBRACK:
			fprintf(fpDst, "TOCK_CBRACK (\"%s\")\n", to.value);
			break;
		case TOCK_REALOP:
			fprintf(fpDst, "TOCK_REALOP (\"%s\")\n", to.value);
			break;
		case TOCK_REALOPASSGN:
			fprintf(fpDst, "TOCK_REALOPASSGN (\"%s\")\n", to.value);
			break;
		}

		strRaw = to.next;
	} while (*strRaw);

	fclose(fpDst);
	fclose(fpSrc);
}