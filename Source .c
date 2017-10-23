#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

#define PI 3.141592653589793
#define ARITHMETIC 0
#define FUNCTION 1

#define BIN 2
#define DEC 10
#define HEX 16

int InCheck(const char *, int *);
void OutChange(double *, int *);
void printhelp();

int main(void) {
	double n = 0, m, a;
	int calmode = ARITHMETIC;
	int inmode, outmode;
	inmode = outmode = DEC;//èâä˙ÇÕ10êiêî
	char sw[100];

	printf("Function Mode\n");
	printf(">>");
	scanf_s("%lf\n", &n);

	while (1) {
		strcpy_s(sw, "\0");
		scanf_s("%s", sw,100);
		if (!strcmp(sw, "\\q"))break; 
		else if (!strcmp(sw, "\\f"))		{ calmode = FUNCTION;	printf("Function Mode\n");		continue; }
		else if (!strcmp(sw, "\\a"))		{ calmode = ARITHMETIC;	printf("Arithemetic Mode\n");	continue; }
		//else if (!strcmp(sw, "\\in-2"))	{ inmode = BIN;		printf("In-Bin\n");		continue; }
		//else if (!strcmp(sw, "\\in-10"))	{ inmode = DEC;		printf("In-Dec\n");		continue; }
		//else if (!strcmp(sw, "\\in-16"))	{ inmode = HEX;		printf("In-Hex\n");		continue; }
		else if (!strcmp(sw, "\\out-2"))	{ outmode = BIN;	printf("Out-Bin\n");	continue; }
		else if (!strcmp(sw, "\\out-10"))	{ outmode = DEC;	printf("Out-Dec\n");	continue; }
		else if (!strcmp(sw, "\\out-16"))	{ outmode = HEX;	printf("Out-Hex\n");	continue; }
		else if (!strcmp(sw, "\\help"))		{ printhelp();	continue; }	//å©Ç‚Ç∑Ç≥ìIÇ…ä÷êîâª


		//if (InCheck(sw, &inmode) == -1) { printf("Re\n"); continue; }

		switch (calmode) {
		case ARITHMETIC:
			m = strtod(&sw[1], NULL);
			break;
		case FUNCTION:
			m = strtod(&sw[2], NULL);
			if (sw[1] == 's')		m = sin(m * PI / 180.0);
			else if(sw[1] == 'c')	m = cos(m * PI / 180.0);
			else if (sw[1] == 'p')	m = pow(n, m); 
			else if (sw[1] == 'l')	m = log(m);
			else if (sw[1] == 'r')	m = sqrt(m);

		default:
			break;
		}


		switch (sw[0]) {
		case '+':
			a = n + m;
			OutChange(&a, &outmode);
			n = a;
			break;
		case '-':
			a = n - m;
			OutChange(&a, &outmode);
			n = a;
			break;
		case '*':
			a = n * m;
			OutChange(&a, &outmode);
			n = a;
			break;
		case '/':
			a = n / m;
			OutChange(&a, &outmode);
			n = a;
			break;
		default:
			printf("Re\n");
		}

	}

	return 0;
}

int InCheck(const char *n, int *mode) {
	int i;
	int ret;
	switch (*mode) {
	case BIN:
		break;
	case DEC:
		break;
	case HEX:
		break;
	}
	return 0;
}

void OutChange(double *a, int *mode) {
	unsigned int bit = (1 << (sizeof(int) * 8 - 1));
	char s[100];
	switch (*mode) {
	case BIN:
		sprintf_s(s, "%lf", *a);
		printf("=");
		for (; bit != 0; bit >>= 1) {
			if ((int)*a & bit) {
				printf("1");
			} else {
				printf("0");
			}
		}
		printf("\n");
		break;
	case DEC:
		printf("=%lf\n", *a);
		break;
	case HEX:
		sprintf_s(s, "%x", (int)*a);
		printf("=%x\n", (int)strtol(s, NULL, *mode));
		break;
	}
}

void printhelp() {
	printf("Comand List\n\n");
	printf("OutMode\n");
	printf("\\out-2\n");
	printf("    -10\n");
	printf("    -16\n\n");
	printf("CalMode\n");
	printf("\\f Function Mode\n");
	printf("\\a Arithemetic Mode\n");
}