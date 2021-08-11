#include "Formule.h"
#include "stdlib.h"


#define SET 4
#define EX 3

#define MAT == 1

#define LINII 4
#define COLOANE 4

#define TRUE 1
#define FALSE 0

#define MAX_BITS 8
#define MAX_INT_BITS MAX_BITS*sizeof(int)
#define MAX_CHAR_BITS MAX_BITS*sizeof(char)
#define MAX_LONG_BITS MAX_BITS*sizeof(long)
#define MAX_SHORT_BITS MAX_BITS*sizeof(short)


#define LUNGIME_N 19
#define LUNGIME_PP 3
#define LUNGIME_NPP 7
#define LUNGIME_NN 11
#define LUNGIME_TABLOU	7

typedef void (*handler_type)(unsigned int *functie, unsigned int tablou);

unsigned long tablouIntervale[LUNGIME_TABLOU] = {5,20,50,90,100,130,139};

int tab_numere[LUNGIME_N] = {-10, -5, -4, -2, -1, 10, 15, 22, 11, 5, 2, 1, -17, 17, 29, 43, 53, 67, 0};
unsigned long tab_nrPrimePozitive[LUNGIME_PP];
unsigned long tab_nrNonPrimePozitive[LUNGIME_NPP];
unsigned long tab_nrNegative[LUNGIME_NN];


typedef enum Stare
{
	normal,
	SCM,
	SCB

}stare_e;

typedef enum tip
{
	uint8,
	uint16,
	uint32,
	boolean_,
	uint32f
}tip_e;

//struct
//vector de char de 32biti
//o unuiune cu toate tipurile pe care le solicita
typedef struct parDC_
{
	tip_e tipul;
	char vec[32];
	union _tipSolicitat_u
	{
		int uint32;
		float uint32f;
		short uint16;
		char uint8;
		char BOOL;

	}tipSolicitat_u;

}parDC;


typedef struct Port
{
    stare_e starePort;
    struct _Pins_s
    {
        unsigned char in : 1;
        unsigned char out : 1;
        unsigned char res : 6;
    }Pins_s;

}port;


typedef enum Fields
{
	WPS, 
	WPE, 
	res = 3, 
	HYS, 
	ODE, 
	DSC
}fields;

static unsigned int arrLength(const char *s)
{
	unsigned int i = 0;
	if((s != NULL))
	{
		for(; *s != '\0';)
		{
			printf("*s++:  %c\n", *s++);
			i++;
		}
	}
	return i;
}

static unsigned int arrLengthChar(unsigned char *s)
{
	unsigned int i = 0;
	if((s != NULL))
	{
		printf("*s++: ");
		for(; *s != '\0';)
		{
			printf("%c", *s++);
			i++;
		}
		printf("\n", *s++);
	}
	return i;
}

void strncopy (char *destinatie, char *sursa, unsigned int n, char destinatieSize)
{
	if((destinatie != NULL) && (sursa != NULL))
	{
		char i = 0;
		for(; i < n; i++)
		{
			*(destinatie+i) = *(sursa+i);
		}
		*(destinatie+i) = '\0';
	}
}

void swapBD(parDC *vecBD1, parDC *vecBD2)
{
	if ((vecBD1 != NULL) && (vecBD2 != NULL))
	{
		parDC temp;
		memcpy(&temp, vecBD1, sizeof(temp));
		memcpy(vecBD1, vecBD2, sizeof(temp));
		memcpy(vecBD2, &temp, sizeof(temp));
	}
	
}

void bubbleSortBDTip(parDC *vec)
{
	int i = 0;
	//char tempVec1 = 0;
	//char tempVec2 = 0;
	unsigned char sortat = 0;
	if(vec != NULL)
	{
		while(sortat == 0)
		{
			sortat = 1;
			for(i = 0; i < 5; i++)
			{
				//tempVec1 = getType(&vec[i]);
				//tempVec2 = getType(&vec[i+1]);
				printf("Tipul vec1 %d Tipul vec2 %d\n", vec[i].tipul, vec[i+1].tipul);
				if (vec[i].tipul > vec[i+1].tipul)
				{
						swapBD(&vec[i], &vec[i+1]);
						sortat = 0;
				}
			}
		}
	}
}

char getType(parDC *vec)
{
	char temp;
	if(vec != NULL)
	{
		temp = vec->tipul;
	}
	return temp;
}



int getVal(parDC *vec)
{
	int tempValoare = 0;

	if(vec != NULL)
	{
		switch(vec->tipul)
			{
				case uint8:
					tempValoare = vec->tipSolicitat_u.uint8;
					break;
				case uint16:
					tempValoare = vec->tipSolicitat_u.uint16;
					break;
				case uint32:
					tempValoare = vec->tipSolicitat_u.uint32;
					break;
				case boolean_:
					tempValoare = vec->tipSolicitat_u.BOOL;
					break;
				case uint32f:
					tempValoare = vec->tipSolicitat_u.uint32f;
					break;
				default:
					printf("ErrorPrint");
					break;
			}
	}
	return tempValoare;
}




void bubbleSortBDVal(parDC *vec)
{
	int i, j;
	int tempVal1 = 0;
	int tempVal2 = 0;
	unsigned char sortat = 0;
	if(vec != NULL)
	{
		for(i = 0; i < 5; i++)
		{
			sortat = 1;
			for(j = 0; j < 5-i; j++)
			{
				tempVal1 = getVal(&vec[j]);
				tempVal2 = getVal(&vec[j+1]);
				printf("Val vec1 %d Val vec2 %d\n", tempVal1, tempVal2);
				if (tempVal1 > tempVal2)
				{
						swapBD(&vec[j], &vec[j+1]);
						sortat = 0;
				}
			}
		}
	}
}
