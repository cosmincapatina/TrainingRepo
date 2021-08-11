#include <stdio.h>
#include "string.h"
#include "Header.h"
#include "MyError.h"


static int variabila = 2;
int variabila2 = 1;
int variabila1 = 10;
static int variabila4 = 11;

static char searchWord (const char *row, const char *cuvant);
static unsigned int alternative(const char *c, const char *s);
static unsigned int arrLength(const char *s);
static char isBlank (const char *myChar);
void (*handler)(unsigned int *tablou, unsigned int size);

void printArray(unsigned int *mat)
{
    int i, counter = 0;
	if (mat != NULL)
	{
		for (i=0; i < LINII*COLOANE; i++)
		{
			printf("%d ", mat[i]);
			counter++;
			if(counter == COLOANE)
			{
				counter = 0;
				printf("\n");
			}

		}
		printf("\n");
	}
}

void printArrayChar(unsigned char *mat)
{
    int i, counter = 0;
	if (mat != NULL)
	{
		for (i=0; i < LINII*COLOANE; i++)
		{
			printf("%d ", mat[i]);
			counter++;
			if(counter == COLOANE)
			{
				counter = 0;
				printf("\n");
			}

		}
		printf("\n");
	}
}


void swap(unsigned int *nr1, unsigned int *nr2)
{
	if ((nr1 != NULL) && (nr2 != NULL))
	{
		unsigned int temp = *nr1;
		*nr1 = *nr2;
		*nr2 = temp;
	}
}

void decimalToBinar(unsigned long *numar,unsigned int tablou[])
{
	unsigned long temp = *numar;
	int i = 0, counter0 = 0, counter1 = 0;
	
	for(; temp > 0; i++)
	{
		tablou[i] = temp % 2;
		if(tablou[i] == 1)
		{
			counter1++;
		}
		temp /= 2;
	}

	//printf("Biti de 0 = %d \nBiti de 1 = %d", (MAX_LONG_BITS-counter1), counter1);

}

void get(unsigned char pPos,unsigned long num,unsigned char str[7])
{
	//if ((NULL != pPos))
	//{
		unsigned char n = pPos;
		printf("Valoarea lui %s este %d\n", str, (num >> pPos) & 1 );
	//}
}

char getBit(unsigned char pPos,unsigned long *num)
{
	//if ((NULL != pPos))
	//{
		unsigned char n = (*num >> pPos) & 1;
		return n;
	//}
}


void afisareVector(unsigned int pVec[])
{
	int i = MAX_LONG_BITS-1;

	printf("\n");

	for (; i >= 0; i--)
	{
		printf("%d",*(pVec+i));
	}

	printf("\n");

}

void afisareVectorChar(unsigned char pVec[], unsigned int lungime)
{
	unsigned int i = 0;
	printf("\n");
	for (; i < lungime; i++)
	{
		printf("%c",*(pVec+i));
	}
	printf("\n");
}

void afisareVectors(unsigned int pVec[], int lungime)
{
	int i = 0;

	printf("\n");

	for (; i < lungime; i++)
	{
		printf("0x3%x ",*(pVec+lungime-1-i));
	}

	printf("\n");

}
void afisareVectorss(int pVec[], int lungime)
{
	int i = 0;

	printf("\n");

	for (; i < lungime; i++)
	{
		printf("%d ",*(pVec+i));
	}

	printf("\n");

}
void afisare( unsigned long *pNum)
{
	int i = MAX_LONG_BITS -1;

	printf("\n");

	for (; i >= 0; i--)
	{
		printf("%d", (*pNum >> i) & 1);
	}

	printf("\n");

}



void set(unsigned long *num, unsigned char pPos, unsigned int valoare)
{
	if ( valoare == 0 )
	{
		*num  &=  ~( 1 << pPos);
	}

	if ( valoare == 1 )
	{
		*num  |= ( 1 << pPos);
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 1 EX 1
/*
1.	Scrieti o functie care afiseaza valoarea in binar a unei variabile pe 8 biti (stocati fiecare bit intr-o variabila pe care o afisati folosind instructiunea “printf”).	
*/
#if (SET == 1) && (EX == 1)
void main ()
{
	char num = 25;
	char vec[8] = {0};
	int i = MAX_CHAR_BITS - 1;

	for (; i >= 0; i--)
	{
		vec[i] = (num >> i) & 1;
		printf("%d", vec[i]);
	}
	printf("\n");
}

#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 1 EX 2
/*
2.	Scrieti o functie care returneaza 0 sau 1, valoarea difera la fiecare apel a functiei (daca la apelul precedent a returnat 0, 
la apelul curent va returna 1, iar la urmatorul apel va returna 0, s.a.m.d.). Nu folositi instructiuni de testare. Folositi doar operatii pe biti.
*/
#if (SET == 1) && (EX == 2)
void negatePreviousReturn(char *num)
{
	char n = *num; 

	// n = (n ^ 1) & 1;
	n = (~n) & 1;

	printf("%d\n", n);

	*num = n;

}


void main ()
{

	char num = 0xFF;
	int i = 0;

	printf("%d\n", num); 

	for(; i <= 5; i++)
	{
		negatePreviousReturn(&num);
	}

}

#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 1 EX 3
/*
3.	Avand o variabila pe 8 biti (unsigned char), scrieti o functie “get” care citeste valoarea unui bit de 
la o anumita pozitie si o functie “set” care scrie un bit de la o anumita pozitie cu o anumita valoare data:
get (pozitie)
set (pozitie, valoare)
*/
#if (SET == 1) && (EX == 3)

#define MAX_BITS 8

unsigned char num = 15;

void set(unsigned char *pPos, unsigned char *valoare)
{
	if ((NULL != pPos) && (NULL != valoare))
	{
		if ( *valoare == 0 )
		{
			num  &=  ~( 1 << *pPos);
		}	

		if ( *valoare == 1 )
		{
			num  |= ( 1 << *pPos);
		}
	}
}

void get(unsigned char *pPos)
{
	if ((NULL != pPos))
	{
		unsigned char n = *pPos;
		printf("Bit at pos %d is %d\n", *pPos, (num >> *pPos) & 1 );
	}
}



void main()
{
	int i = (sizeof(char) * MAX_BITS) - 1;
	unsigned char vec[8] = {0};
	unsigned char noPos = 3;
	unsigned char valoare = 0;

	get(&noPos);

	printf("\n");

	printf("Before: ");

	for (; i >= 0; i--)
	{
		vec[i] = (num >> i) & 1;
		printf("%d", vec[i]);
	}

	printf("\n");

	set(&noPos, &valoare);
	
	printf("After: ");

	for (i = (sizeof(char) * MAX_BITS) - 1; i >= 0; i--)
	{
		vec[i] = (num >> i) & 1;
		printf("%d", vec[i]);
	}
	printf("\n");
}

#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 1 EX 4
/*
4.	Definiti o functie rightrot(a, n) care roteste circular (bitii care "ies" in dreapta "intra" in stanga) pe a cu n pozitii la dreapta. Incercati fara instructiuni de ciclare.
a – variabila pe 32 biti fara semn
n – variabila pe 8 biti fara semn
Ex.  a = 0x300C00FF, n = 2
*/
#if (SET == 1) && (EX == 4)

#define MAX_BITS 8
#define MAX_INT_BITS MAX_BITS*sizeof(int)

void rightRot(unsigned int *number, unsigned char *pPos)
{
	if ((NULL != pPos) && (NULL != number))
	{
		unsigned int temp = *number;
		*number >>= *pPos;
		temp = temp << (MAX_INT_BITS - *pPos);
		*number = *number | temp;
	}
}



void main ()
{
	unsigned int number = 0x300C00FF;
	unsigned char pos = 3;
	unsigned char vec[MAX_INT_BITS] = {0};
	int i = MAX_INT_BITS - 1;

	printf("Before: ");

	for (; i >= 0; i--)
	{
		vec[i] = (number >> i) & 1;
		printf("%d", vec[i]);
	}
	printf("\n");

	rightRot(&number, &pos);

	printf("After:  ");

	for (i = (sizeof(int) * MAX_BITS) - 1; i >= 0; i--)
	{
		vec[i] = (number >> i) & 1;
		printf("%d", vec[i]);
	}
	printf("\n");
}

#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 1 EX 5
/*
5.	Fie o variabila EBI_MCR pe 32 biti (unsigned long) care impacheteaza urmatoarele campuri (valori pozitive): SIZEN, SIZE, ACGE, EXTM, EARB, MDIS si DBM. 
Initializati aceste campuri cu valori furnizate de voi. Afisati valoarea lui EBI_MCR in urma initializarii. Afisati valorile campurilor. 
Modificati valoarea lui EBI_MCR si afisati din nou valorile campurilor. Folositi operatii pe biti si masti.
Inainte de afisare, stocati valoarea intr-o variabila.
*/
#if (SET == 1) && (EX == 5)

unsigned long EBI_MCR = 0;

#define DBM_POS 0
#define MDIS_POS 6
#define EARB_POS 13
#define EXTM_POS 14
#define ACGE_POS 15
#define SIZE24_POS 24
#define SIZE25_POS 25
#define SIZEN_POS 26

void get(unsigned char pPos,unsigned long num,unsigned char str[7])
{
	//if ((NULL != pPos))
	//{
		unsigned char n = pPos;
		printf("Valoarea lui %s este %d\n", str, (num >> pPos) & 1 );
	//}
}

void main ()
{
	unsigned char DBM = (EBI_MCR >> DBM_POS) & 1;
	unsigned char MDIS = (EBI_MCR >> MDIS_POS) & 1;
	unsigned char EARB = (EBI_MCR >> EARB_POS) & 1;
	unsigned char EXTM = (EBI_MCR >> EXTM_POS) & 1;
	unsigned char ACGE = (EBI_MCR >> ACGE_POS) & 1;
	unsigned char SIZE24 = (EBI_MCR >> SIZE24_POS) & 1;
	unsigned char SIZE25 = (EBI_MCR >> SIZE25_POS) & 1;
	unsigned char SIZEN = (EBI_MCR >> SIZEN_POS) & 1;
	unsigned char vec[32] = {0};
	int i = MAX_INT_BITS - 1;
	unsigned char sizen[7] = "SIZEN";
	unsigned char size24[7] = "SIZE24";
	unsigned char size25[7] = "SIZE25";
	unsigned char acge[7] = "ACGE";
	unsigned char extm[7] = "EXTM";
	unsigned char earb[7] = "EARB";
	unsigned char mdis[7] = "MDIS";
	unsigned char dbm[7] = "DBM";

	//SIZEN

	set(&EBI_MCR, SIZEN_POS, 1);
	get(SIZEN_POS, EBI_MCR, sizen);

	//SIZE24

	set(&EBI_MCR, SIZE24_POS, 0);
	get(SIZE24_POS, EBI_MCR, size24);

	//SIZE25
	
	set(&EBI_MCR, SIZE25_POS, 0);
	get(SIZE25_POS, EBI_MCR, size25);

	//ACGE
	
	set(&EBI_MCR, ACGE_POS, 1);
	get(ACGE_POS, EBI_MCR, acge);

	//EXTM
	
	set(&EBI_MCR, EXTM_POS, 1);
	get(EXTM_POS, EBI_MCR, extm);

	//EARB
	
	set(&EBI_MCR, EARB_POS, 1);
	get(EARB_POS, EBI_MCR, earb);

	//MDIS
	
	set(&EBI_MCR, MDIS_POS, 1);
	get(MDIS_POS, EBI_MCR, mdis);

	//DBM
	
	set(&EBI_MCR, DBM_POS, 1);
	get(DBM_POS, EBI_MCR, dbm);

	printf("Valoarea initializata a lui EBI_MCR: ");

	afisare(&EBI_MCR);

	printf("\n");
	
	set(&EBI_MCR, DBM_POS, 0);
	get(DBM_POS, EBI_MCR, dbm);

	set(&EBI_MCR, SIZE25_POS, 1);
	get(SIZE25_POS, EBI_MCR, size25);

	set(&EBI_MCR, SIZE24_POS, 1);
	get(SIZE24_POS, EBI_MCR, size24);

	printf("Valoarea lui EBI_MCR dupa modificari: ");

	afisare(&EBI_MCR);

}
#endif

#if (SET == 1) && (EX == 51)

unsigned long EBI_MCR = 0;

void GetField(unsigned int* puEBI_MCR, unsigned char uPosition, unsigned char uSize, unsigned int* puValue)
{
	unsigned int uVal = *puValue;
	unsigned int uRegister = *puEBI_MCR;
	uVal = (uRegister >> (uPosition - uSize + 1)) & (~((~0) << uSize));
	*puValue = uVal;
}

void SetField(unsigned long *ulEBI_MCR, unsigned char uPosition, unsigned char uSize, unsigned int uValue)
{
	unsigned long uRegister = *ulEBI_MCR;

	unsigned int uIdx;

	for( uIdx = 0 ; uIdx < uSize; uIdx++ )
	{
		uRegister &= ~(1 << (uPosition - uIdx));
		uRegister |= (uValue << (uPosition - uIdx - uSize + 1)) & (1 << (uPosition - uIdx));
	}
	*ulEBI_MCR = uRegister;
}

void main ()
{
	unsigned long EBO_MCR = 0;
	unsigned int value = 2;
	unsigned char size = 1;
	unsigned char position = 25;

	afisare(&EBO_MCR);

	SetField(&EBO_MCR, position, size, value);

	afisare(&EBO_MCR);

}

#endif
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 1 EX 6
/*
Fie o variabila EMIOS_CCR pe 16 biti (unsigned short) care impacheteaza urmatoarele campuri (valori pozitive): FREN, ODIS, ODISSL, UCPRE, UCPREN, DMA, IF, FCK si FEN. 
Initializati aceste campuri cu valori furnizate de voi. Verificati valoarea lui EMIOS_CCR in urma initializarii. Afisati valorile campurilor. 
Modificati valoarea lui EMIOS_CCR si afisati din nou valorile campurilor. Folositi operatii pe biti si masti.
Inainte de afisare, stocati valoarea intr-o variabila.
*/
#if (SET == 1) && (EX == 6)

void main ()
{
	unsigned short EMIOS_CCR = 0;

	unsigned char FEN = 1;
	unsigned char FCK = 2;
	unsigned char IF3 = 3;
	unsigned char IF4 = 4;
	unsigned char IF5 = 5;
	unsigned char IF6 = 6;
	unsigned char DMA = 8;
	unsigned char UCPREN = 9;
	unsigned char UCPRE10 = 10;
	unsigned char UCPRE11 = 11;
	unsigned char ODISSL12 = 12;
	unsigned char ODISSL13 = 13;
	unsigned char ODIS = 14;
	unsigned char FREN = 15;

	afisare(&EMIOS_CCR);

	set(&EMIOS_CCR, FEN, 1);
	set(&EMIOS_CCR, FCK, 1);
	set(&EMIOS_CCR, IF3, 1);
	set(&EMIOS_CCR, IF5, 1);
	set(&EMIOS_CCR, IF6, 1);
	set(&EMIOS_CCR, UCPREN, 1);
	set(&EMIOS_CCR, ODISSL13, 1);
	set(&EMIOS_CCR, FREN, 1);

	afisare(&EMIOS_CCR);
}

#endif
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// SET 1 EX 11
#if (SET == 1) && (EX == 11)

int main ()
{

	unsigned char a;
	signed char b,c;
	b=10;
	c=0;
	a=255;
	c= ~a-b++;
	printf("%d\n", c);
	//Care este valoarea lui c ? Faceti calculul pe hartie si apoi incercati pe PC

}
#endif
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*SET 2 EX 1 
1.	Scrieti o functie care converteste in binar un numar primit prin argumentul functiei; argumentul fiind de tip unsigned long. 
	Numarul e definit printr-o directiva de preprocesare. Folositi un tablou pentru stocarea bitilor numarului binar. Calculati si cati biti de 1 si de 0 are numarul binar.
*/
#if (SET == 2) && (EX == 1)

#define NUMARDECONVERTIT 52152156

void decimalToBinars(unsigned long *numar,unsigned int tablou[])
{
	unsigned long temp = *numar;
	int i = 0, counter1 = 0;
	
	for(; temp > 0; i++)
	{
		tablou[i] = temp % 2;
		if(tablou[i] == 1)
		{
			counter1++;
		}
		temp /= 2;
	}

	printf("Biti de 0 = %d \nBiti de 1 = %d", (MAX_LONG_BITS-counter1), counter1);

}

void decimalToBinarBit(unsigned long *numar, unsigned int tablou[])
{
	int i = MAX_LONG_BITS-1, counter1 = 0;
	unsigned long temp = *numar;
	
	for(; i >= 0; i--)
	{
		tablou[i] = (temp >> i) & 1;
		if(tablou[i] == 1)
		{
			counter1++;
		}
	}
	printf("Biti de 0 = %d \nBiti de 1 = %d", (MAX_LONG_BITS-counter1), counter1);
}

void main ()
{
	unsigned int vec[MAX_LONG_BITS] = {0};
	unsigned long numarDeConvertit = NUMARDECONVERTIT;

	decimalToBinarBit(&numarDeConvertit, vec);

	afisareVector(vec);

}

#endif
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*SET 2 EX 2
2. Scrieti un macro care seteaza un bit dintr-o variabila: setbit (pozitieBit, var)
Scrieti un macro care reseteaza un bit dintr-o variabila: clearbit (pozitieBit, var)
*/
#if ( SET == 2 ) && ( EX == 2 )


#define setBit(pozitieBit, var)  (var) |= ((1 << pozitieBit)) 
#define clearBit(pozitieBit, var)  (var) &= ~((1 << pozitieBit)) 

void main ()
{
	unsigned long x = 10;
	int i =3;
	unsigned int vec[10] = {0};
	unsigned int vec2[10] = {0};
	unsigned int vec3[10] = {0};
	decimalToBinar(&x, vec);
	afisareVectors(vec, 10);
	setBit(i, x);
	printf("%d\n", x);
	decimalToBinar(&x, vec2);
	afisareVectors(vec2, 10);
	clearBit(i, x);
	printf("%d\n", x);
	decimalToBinar(&x, vec3);
	afisareVectors(vec3, 10);
}

#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*SET 2 EX 3
3.	Scrieti o functie care inverseaza ordinea bitilor dintr-un numar primit prin argumentul functiei; argumentul fiind de tip unsigned long. Afisati pe biti numarul inainte si dupa modificare
*/
#if (SET == 2 && EX == 3)


void inverBits(unsigned long *numar)
{
	int i = 0;
	char tempInceput = 0;
	char tempFinal = 0;
	afisare(numar);
	for(; i < MAX_LONG_BITS/2; i++)
	{
		tempInceput = (getBit(i, numar));
		tempFinal = (getBit((MAX_LONG_BITS-i)-1, numar));
		set(numar, (MAX_LONG_BITS-i)-1, tempInceput);
		set(numar, i, tempFinal);
	}
	afisare(numar);
}
uint32_t mask = 1 << (sizeof(nb)*8 - 1);

for(i = 0; i < sizeof(nb)*8; i++)
{
if(nb & 0x01)
new_nb |= mask;
nb >>= 1;
mask >>= 1;
}


void main()
{
	unsigned long numar = 52151;
	inverBits(&numar);
}

#endif
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*SET 2 EX 4
4.	Avand urmatoarea sectiune de program (intr-un fisier main.h):

#define LUNGIME_TABLOU	7
unsigned long	tablouIntervale[LUNGIME_TABLOU] = {5,20,50,90,100,130,139};

Scrieti o functie (intr-un fisier main.c) care primeste printr-un argument de tip unsigned long o valoare (ex: valViteza) si printr-un alt argument - tabloul de intervale. 
Functia retureaza pozitia valori valViteza in cadrul tabloului, ca in urmatorul exemplu:

valViteza < 5 – functia returneaza 0
valViteza in intervalul [5,20) – functia returneaza 1
valViteza in intervalul [20,50) – functia returneaza 2
...
valViteza >= 139 – functia returneaza 7

Nota 1: Functia trebuie sa ruleze corect daca se modifica LUNGIME_TABLOU si 
             tablouIntervale. Folositi directive de preprocesare pentru a alege din mai multe variante 
             de tablouri.

Nota 2: tablouIntervale contine valori strict crescatoare.

*/
#if (SET == 2 && EX == 4)

char incadrareViteza(unsigned long ulvalViteza, unsigned long pTablouIntervale[], int lungime)
{
	int i = 1;
	int exit = 0;

	if (ulvalViteza < pTablouIntervale[0])
		{
			i = 0;
			exit = 1;
		}

	if (ulvalViteza >= pTablouIntervale[lungime-1])
		{
			i = lungime;
			exit = 1;
		}

	for(; (i < lungime-1) && (exit == 0); i++)
	{
		if (ulvalViteza < pTablouIntervale[i])
		{
			break;
		}
	}
	
	return i;
}


void main()
{
	unsigned long ulvalViteza = 7;
	int lungime = sizeof(tablouIntervale)/sizeof(tablouIntervale[0]);
	char valoare = incadrareViteza(ulvalViteza, tablouIntervale, lungime);
	printf("%d\n", valoare);
}

#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 2 EX 5
/*
5.	Scrieti un program care citeste dintr-un tablou de numere: tab_numere[LUNGIME_N]
Fiecare valoare citita este stocata intr-unul din cele 3 tablouri:

tab_nrPrimePozitive[LUNGIME_PP]              tablou de numere prime pozitive 
tab_nrNonPrimePozitive[LUNGIME_NPP]     tablou de numere pozitive care nu sunt prime 
tab_nrNegative[LUNGIME_NN]                      tablou de numere negative 

tablourile si lungimile sunt definite intr-un fisier: tablou.h. Intr-un alt fisier (decat cel care contine functia main, scrieti functia care depisteaza daca un numar este prim sau nu).


Programul se opreste in momentul in care unul din cele trei tablouri a fost umplut sau cand tabloul de numere a fost citit in totalitate dar nici unul din cele trei tablouri nu a fost umplut.
*/
#if(SET == 2 && EX == 5)

void umple_tablou(int tab_numere[], unsigned long tab_nrNegative[], unsigned long tab_nrNonPrimePozitive[], unsigned long tab_nrPrimePozitive[])
{
	int i = 0;
	int numarPus = 0;
	char prim = 1;
	signed char numar;
	int counterNrNegative = 0;
	int counterNrPrimePozitive = 0;
	int counterNrNonPrimePozitive = 0;
	int lungimeVec = sizeof(tab_numere)/sizeof(int);
	for(; i < lungimeVec; i++)
	{
		int d = 2;
		numar = tab_numere[i];
		prim = 1; // presupunem ca n este prim
		if(numar == 0 || numar == 1 || numar < 0)
		{
			if(numar < 0)
			{
				prim = 0;
				tab_nrNegative[counterNrNegative] = numar;
				counterNrNegative++;
				numarPus = 1;
			}
			else
			{
				prim = 0; // 0 si 1 nu sunt prime
				tab_nrNonPrimePozitive[counterNrNonPrimePozitive] = numar;
				counterNrNonPrimePozitive++;
				numarPus = 1;
			}
		}
		if(numarPus != 1)
		{
			for(; d * d <= numar ; d++)
			{
				if(numar % d == 0)
					prim = 0;
			}

			if(counterNrPrimePozitive < LUNGIME_PP && prim == 1)
			{
				tab_nrPrimePozitive[counterNrPrimePozitive] = numar;
				counterNrPrimePozitive++;
				
			}
			if(counterNrNonPrimePozitive < LUNGIME_NPP && prim == 0)
			{
				tab_nrNonPrimePozitive[counterNrNonPrimePozitive] = numar;
				counterNrNonPrimePozitive++;
			}
		}
		numarPus = 0;
	}
}


void main ()
{
	umple_tablou(tab_numere, tab_nrNegative, tab_nrNonPrimePozitive, tab_nrPrimePozitive);
	int lungimeTablouNegativ = (sizeof(tab_nrNegative) / sizeof(unsigned long));
	int lungimeTablouNrPrimePozitive = (sizeof(tab_nrPrimePozitive) / sizeof(unsigned long));
	int lungimeTablouNrNonPrimePozitive = (sizeof(tab_nrNonPrimePozitive) / sizeof(unsigned long));
	
	printf("tab_numere: ");
	afisareVectorss(tab_numere, sizeof(tab_numere)/sizeof(int));
	printf("\ntab_nrPrimePozitive: ");
	afisareVectors(tab_nrPrimePozitive, lungimeTablouNrPrimePozitive);
	printf("\ntab_nrNonPrimePozitive: ");
	afisareVectors(tab_nrNonPrimePozitive, lungimeTablouNrNonPrimePozitive);
	printf("\ntab_nrNegative: ");
	afisareVectors(tab_nrNegative, lungimeTablouNegativ);
}

#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 2 EX 7
/*
7.	Scrieti o functie care primeste un numar prin intermediul unui argument de tip unsigned long. Functia scrie intr-un tablou codurile ASCII pentru fiecare cifra a numarului primit. 

Nota: functia va calcula codul ASCII. Nu folositi alte biblioteci.

Exemplu:
              numar   tablou
           1234567890 {……0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x30}
                  18  {……0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x38}

*/

#if (SET == 2 && EX == 7)


int howManyDigits(unsigned long numar)
{
   int count = 0;
   int temp = numar;
   while(temp != 0) {
      temp = temp / 10;
      count++;
   }
   return count;
}

void codAsci(unsigned long *numar,unsigned int tablou[])
{

	int i = 0;
	int digit = 0;
	int numarDeDigits = howManyDigits(*numar);
	unsigned long temp = *numar;
	printf("%d\n nr digits: ", numarDeDigits);
	while(temp != 0)
	{
		digit = (temp%10);
		temp /= 10;
		tablou[i] = digit;
		i++;
	}

}


void main()
{
	unsigned long numar = 1234567890;
	int digits = howManyDigits(numar);
	unsigned int tablou[32] = {0x3};
	codAsci(&numar,tablou);
	afisareVectors(tablou, 31);
}


#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 2 EX 8
/*
8.	Scrieti o functie care permite obtinerea unui element din sirul Fibonacci. Se doreste o implementare nerecursiva fara a folosi tablouri.

*/
#if(SET == 2 && EX == 8)

void nthNumberFromFibonacci(int numarDinSerie)
{
	int temp1 = 0, temp2 = 1, nextTerm = 0, i = 0;
	if(numarDinSerie == 1)
	{
		printf("Primul numar din sirul lui Fibonacci este: %d\n", temp1);
	}
	if(numarDinSerie == 2)
	{
		printf("Al doilea numar din sirul lui Fibonacci este: %d\n", temp2);
	}
	if(numarDinSerie > 2 )
	{
		for(; i < numarDinSerie; i++)
		{
			nextTerm = temp1 + temp2;
			temp1 = temp2;
			temp2 = nextTerm;
			if (i == numarDinSerie-3)
			{
				printf("Al %d-lea numar din sirul lui Fibonacci este: %d\n", numarDinSerie, nextTerm);
			}
		}
	}

}


void main ()
{
	int x = 0;
	nthNumberFromFibonacci(x);
}


#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 2 EX 9
/*
9.	Intr-un alt fisier decat "main.c", scrieti o functie care returneaza pozitia unei chei in cadrul unui tablou unidimensional cu elemente sortate descrescator. 
Sa se scrie 2 variante (nerecursive) de implementare, una dintre ele mai rapida (cautare binara), 
daca se cunoaste la compilare care metoda se vrea a fi folosita (codul executabil nu trebuie sa contina ambele implementari).

*/
#if(SET == 2 && EX == 9)


void BinaryOrOther(int numarDeCautat, int lista[], int marime, int alegere)
{
	if(alegere == 1)
	{
		int n = BinarySearch(lista, numarDeCautat, marime);
		if(n == 1)
		{
			printf("Numarul %d este in lista.\n", numarDeCautat);
		}
		else
		{
			printf("Numarul %d nu este in lista.\n", numarDeCautat);
		}
	}else
	{
		int n = clasicSearch(lista, numarDeCautat, marime);
		if(n == 1)
		{
			printf("Numarul %d este in lista.\n", numarDeCautat);
		}
		else
		{
			printf("Numarul %d nu este in lista.\n", numarDeCautat);
		}
	}
}


void main ()
{
	int numarDeCautat = 1;
	int alegere = 0;
	int lista[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int marime = sizeof(lista)/sizeof(lista[0]);
	BinaryOrOther(numarDeCautat, lista, alegere, marime);
}

#endif


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 3 EX 1
/*
1.	Scrieti o functie care primeste ca argument un pointer la o variabila unsigned long. Afisati fiecare byte al valorii de tip unsigned long. Afisati toata valoarea de tip unsigned long. Ce observati ?
Nota: Folositi pointeri si NU operatii pe biti !
*/
#if(SET == 3 && EX == 1)

void afisareByte(unsigned long *numar)
{
	if(numar != NULL)
	{
		int i = 0, j = 0;
		printf("Valoare in hexa: %x\n", *numar);
		//printf("Value 0x%" PRIx32 "\n", *numar);

		for(; i < sizeof(unsigned long); i++)
		{
			printf("Valoare in hexa: %x\n", (char*)(numar+i));
		}
	}
}


void main()
{
	unsigned long numar = 0x52151;
	afisareByte(&numar);
}


#endif
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 3 EX 2
/*
2.  Scrieti o functie care primeste ca argument un pointer la o variabila FLASH_BIUCR pe 16 biti (unsigned short) 
care impacheteaza urmatoarele campuri (valori pozitive): APC, WWSC, RWSC, DPFEN, IPFEN, PFLIM si BFEN. 
Functia initializeaza aceste campuri cu valori furnizate de voi tot prin intermediul argumentelor. Folositi operatii pe biti si masti.
Afisati valoarea lui FLASH_BIUCR (folosind argument de tip pointer) intr-o alta functie.
*/
#if(SET == 3 && EX == 2)

// set register
ex_ret SetRegister(unsigned short *puRegister, unsigned short uFieldStart,unsigned char uFieldSize, unsigned short uFieldValue ) 
{
	ex_ret eret = ex_ret_ok;

	if(puRegister != NULL)
	{
		unsigned short uRegister = *puRegister;
		unsigned int i = 0;
		for(; i < uFieldSize; i++)
		{
			uRegister &= ~(1 << (uFieldStart - i));
		}
		uRegister |= (uFieldValue << (uFieldStart - uFieldSize +1  ));
		*puRegister = uRegister;
	}
	else
	{
		eret = ex_ret_invalid_param;
	}
	return eret;
}
// print register
ex_ret PrintRegister(const unsigned short *puRegister )
{
	ex_ret eret = ex_ret_ok;

	if(puRegister != NULL)
	{
		int i = MAX_SHORT_BITS-1;

		for (; i >= 0; i--)
		{
			printf("%d", (*puRegister >> i) & 1);
		}
		printf("\n");
	}
	else
	{
		eret = ex_ret_invalid_param;
	}
	return eret;
}

void main ()
{
	ex_ret eret = last;
	unsigned short FLASH_BIUCR = 0;
	unsigned int value = 3;
	unsigned char size = 2;
	unsigned char position = 12;

	printf("Before: ");

	PrintRegister(&FLASH_BIUCR);

	eret = SetRegister(&FLASH_BIUCR, position, size, value);

	printf("After: %d ", eret);

	PrintRegister(&FLASH_BIUCR);

}
#endif
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 3 EX 3
/*
3.	Scrieti o functie “calcul” care primeste prin argument un tablou si returneaza cel mai mic element din tablou, cel mai mare element din tablou si suma elementelor din tablou. 
Cum ar putea functia sa afle dimensiunea tabloului fara a folosi un argument suplimentar, variabila globala sau directiva de preprocesare ?

void calcul (char *ptablou, long *min, long *max, long *sum)
*/
#if(SET == 3 && EX == 3)

void calcul(char *ptablou, long *min, long *max, long *sum)
{
	int i = 1;
	if((ptablou != NULL) && (min != NULL) && (max != NULL) && (sum != NULL))
	{
		long lmin = *min, lmax = *max, lsum = *sum;
		for(; i < *ptablou; i++)
		{
			if( *(ptablou+i) < lmin)
			{
				lmin = *(ptablou+i);
			}
			if( *(ptablou+i) > lmax)
			{
				lmax = *(ptablou+i);
			}
			lsum += *(ptablou+i);
		}
	*min = lmin;
	*max = lmax;
	*sum = lsum;
	}
	
}

void main ()
{
	long max=0;
	long sum=0;
	char tablou[10] = {10, 5, 2, 3, 4, 5, 6, 7, 8, 9};
	long min = tablou[1];
	calcul(tablou, &min, &max, &sum);
	printf("Min: %d\nMax: %d\nSum: %d\n", min, max, sum);
}

#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 3 EX 4
/*
4.	Scrieti o functie care copiaza primele n caractere dintr-un buffer sursa (initializat cu un string de caractere) intr-un buffer destinatie:

strncopy (char *destinatie, char *sursa, unsigned int n)

*/
#if(SET == 3 && EX == 4)


void main ()
{
	int i = 0;
	char cdestinatie[13];
	char csursa[10] = {'a','b','d','e','f','x','y','z','\0'};
	unsigned int uin = 10;
	char sizeOfSursa = sizeof(csursa) / sizeof(csursa[0]), sizeOfDestinatie = sizeof(cdestinatie) / sizeof(cdestinatie[0]);
	strncopy(cdestinatie, csursa, uin, sizeOfDestinatie);
	printf("cdestinatie: ");
	for(; i < uin; i++)
	{
		printf("%c ", cdestinatie[i]);
	}
	printf("\n\n");
}

#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 3 EX 5
/*
5.	Scrieti cate o functie: 
“min” – pentru calcularea celui mai mic element, 
“max” – pentru calcularea celui mai mare element si 
“sum” - pentru calcularea sumei elementelor unui tablou. 
Scrieti o functie “handler” care primeste printr-un argument un pointer la o functie si printr-un alt argument tabloul. 
La apelarea functiei “handler” se dau ca argumente: ce functie va fi folosita (“min”,”max” sau ”sum”) si tabloul.
*/
#if(SET == 3 && EX == 5)

void arrayMin (unsigned int *tablou, unsigned int size)
{
	if((tablou != NULL))
	{
		unsigned int i = 0;
		unsigned min = *(tablou);
		for(; i < size; i++)
		{
			if(*(tablou+i) < min )
			{
				min = *(tablou+i);
			}
		}
		printf("min: %d\n", min);
	}
}

void arrayMax (unsigned int *tablou,unsigned int size)
{
	if((tablou != NULL))
	{
		unsigned int i = 0;
		unsigned max = *(tablou);
		for(; i < size; i++)
		{
			if(*(tablou+i) > max )
			{
				max = *(tablou+i);
			}
		}
		printf("Max: %d\n", max);
	}

}

void arraySum (unsigned int *tablou, unsigned int size)
{
	if((tablou != NULL))
	{
		unsigned int i = 0;
		unsigned sum = 0;
		for(; i < size; i++)
		{
			sum += *(tablou+i);
		}
		printf("sum: %d\n", sum);
	}
}

void main()
{
	unsigned int tablou[10] = {10, 5, 2, 3, 4, 0, 6, 7, 11, 9};
	unsigned int size = sizeof(tablou)/sizeof(tablou[0]);
	handler = &arrayMin;
	handler(tablou, size);
	handler = &arrayMax;
	handler(tablou, size);
	handler = &arraySum;
	handler(tablou, size);
}

#endif
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 3 EX 6
/*
6.	Scrieti o functie care primeste ca argument o matrice de N linii si M coloane (se vor folosi directive de preprocesare pentru a alege din mai multe variante de matrici). 
Functia va sorta in ordine crescatoare elementele de pe fiecare rand.
Folositi o alta functie pentru afisarea matricii.
Nota: Folositi pointeri.
Nota: Pentru sortare folositi metoda bubble-sort, pentru “swap” folositi o functie separata.


*/
#if(SET == 3 && EX == 6)




void bubbleSort(unsigned int *mat)
{
	int i = 0;
	if (mat != NULL)
	{
		for(; i < LINII; i++)
		{
			unsigned int *puRow = mat + i * COLOANE;
			int j = 0;
			for(; j < COLOANE; j++)
			{
				int q = 0;
				for(; q < COLOANE; q++)
				{
					if ((*(puRow + q)) > (*(puRow + q + 1)))
					{
						swap((puRow + q), (puRow + q + 1));
					}
				}
			}
		}
	}
}





void main()
{
	unsigned int matrice[LINII][COLOANE] = {{4, 3, 10, 1}, {22, 3, 2, 1}, {4, 5, 23, 1}, {2, 7, 11, 5}};
	printArray(*matrice);
	bubbleSort(*matrice);
	printArray(*matrice);
}



#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 3 EX 7
/*
7.	Scrieti o functie care primeste ca argument o matrice de N linii si N coloane (se vor folosi directive de preprocesare pentru a alege din mai multe variante de matrici). Scrieti cate o functie pentru:
-  afisarea matricii
-  incrementarea fiecarui numar aflat pe diagonala principala
-  interschimbarea elementelor aflate deasupra diagonalei principale cu elementele aflate sub diagonala principala: a[x][y] ↔ a[y][x] 
Nota: Folositi pointeri.
*/
#if(SET == 3 && EX == 7)

void sumDiagP(unsigned int *mat)
{
	if ((mat != NULL))
	{
		int i = 0, j = 0;
		for(; i < COLOANE; i++, j++)
		{
			unsigned int *puRow = mat + j * COLOANE;
			*(puRow+i) += 1;
		}
	}
}

void swapDiagP(unsigned int *mat)
{
	if(mat != NULL)
	{
		int i = 0, j = 0;
		for(; i < LINII; i++)
		{
			unsigned int *puRow = mat + i * COLOANE;
			for(j = 0; j < COLOANE; j++)
			{
				if ( i == j)
				{
					unsigned int *puNextRow = puRow + COLOANE;
					swap((puRow + j+1), (puNextRow + j));
				}
			}
		}
	}
}


void main ()
{
	unsigned int matrice[LINII][COLOANE] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	//unsigned int matrice[LINII][COLOANE] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	//unsigned int matrice[LINII][COLOANE] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};

	unsigned int sum = 0;
	printArray(*matrice);
	sumDiagP(*matrice);
	swapDiagP(*matrice);
	printArray(*matrice);
}
#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 3 EX 8
/*
8.	Avand un text scris pe mai multe randuri (ca in exemplul de mai jos):

“C is a general purpose programming language initially”
“developed by Dennis Ritchie between”
“1969 and 1973 at Bell Labs”

Stocati acest text folosind array de pointeri (fiecare pointer indica spre un rand).

Scrieti o functie care primeste ca argument acest text stocat, si un cuvant pe care sa-l caute in tot textul. Functia returneaza TRUE daca cuvantul a fost gasit in text sau FALSE daca nu a fost gasit. 
Nota: Pentru usurinta, cuvintele din text sunt delimitate prin spatii sau inceput/sfarsit de rand. Nu se vor folosi semne de punctuatie.
Nota: Nu se iau in considerare literele mari sau mici, astfel incat daca se cauta cuvantul “bell” in textul dat ca exemplu, functia va returna TRUE.
Nota: NU folositi functii din string.h (sau alte biblioteci similare)
*/
#if(SET == 3 && EX == 8)

static char isBlank (const char *myChar)
{
	char trueOrFalse = 0;
	if (myChar != NULL)
	{
		if((*myChar == ' ') || (*myChar == '\0') || (*myChar == '\n'))
		{
			trueOrFalse = 1;
		}
	}
	return trueOrFalse;
}


static unsigned int alternative(const char *c, const char *s)
{
	unsigned int adevaratSauFals = 0;
	if((c != NULL) && (s != NULL))
	{
		if((*s > 'A') && (*s < 'Z'))
		{
			if(*c == (*s + 32))
			{
				adevaratSauFals = 1;
			}

		}
		if((*s > 'a') && (*s < 'z'))
		{
			if(*c == (*s - 32))
			{
				adevaratSauFals = 1;
			}
		}
	}
	return adevaratSauFals;
}

static char searchWord (const char *row, const char *cuvant)
{
	char trueOrFalse = 0;

	if ((row != NULL) && (cuvant != NULL))
	{
		unsigned int i = 0, j = 0;
		unsigned int check = 0;
		unsigned int counter = 0;
		unsigned int size = arrLength(row);
		unsigned int sizeCuvant = arrLength(cuvant);
		unsigned int alternativeVar = 0;
		printf("sizeArray:  %d\n", size);
		printf("sizeCuvant:  %d\n", sizeCuvant);
		
		for(; i < size; i++)
		{
			check = isBlank(row+i);

			if(check != 1)
			{
				printf("row+i %c // cuvant+j: %c %d\n", *(row+i), *(cuvant+j), j);
				alternativeVar = alternative(row+i,cuvant+j);
				if(*(row+i) == *(cuvant+j) || (alternativeVar == 1))
				{
					j++;
					counter++;
					printf("Counter: %d j %d\n", counter, j);
				}
				else
				{
					j = 0;
					counter = 0;
					printf("Counter: %d j %d\n", counter, j);
				}


			}else
			{
				j = 0;
				counter = 0;
				printf("Counter: %d j %d\n", counter, j);
			}
			if(counter == sizeCuvant)
			{
				trueOrFalse = 1;
				break;
			}
			

		}
	}
	return trueOrFalse;
}

void main ()
{
	char strRow1[] ={ "C is a general purpose programming language initially"};
	char strRow2[] ={ "developed by Dennis Ritchie between"};
	char strRow3[] ={ "1969 and 1973 at Bell Labs"};

	char* Arr[] = {strRow1, strRow2, strRow3};

	int i = 0;
	int counter = 0;

	char cuvant[] = {"laNguage"};

	for(; i < 3; i++)
	{
		if(searchWord(*(Arr+i), cuvant) == 1)
		{
			printf("TRUE\n");
			break;
		}
		else
		{
			counter++;
		}
	}
	if(counter == 3)
	{
		printf("FALSE\n");
	}


}

#endif
#if(SET == 3 && EX == 81)

char isBlank (char *myChar)
{
	if (myChar != NULL)
	{
		int trueOrFalse = 0;
		if((*myChar == ' ') || (*myChar == '\0') || (*myChar == '\n'))
		{
			trueOrFalse = 1;
		}
		return trueOrFalse;
	}
}

unsigned int arrLength(char *s)
{
	if((s != NULL))
	{
		unsigned int i = 0;
		for(; *(s+i) != '\0';)
		{
			i++;
		}
		return i;
	}
}

unsigned int alternative(char *c, char *s)
{
	if((c != NULL) && (s != NULL))
	{
		unsigned int adevaratSauFals = 0;
		if(*s > 'A' && *s < 'Z')
		{
			if(*c == *s + 32)
			{
				adevaratSauFals = 1;
			}

		}
		if(*s > 'a' && *s < 'z')
		{
			if(*c == *s - 32)
			{
				adevaratSauFals = 1;
			}
		}
		return adevaratSauFals;
	}
}

char searchWord (char *row, char *cuvant)
{
	if ((row != NULL) && (cuvant != NULL))
	{
		char trueOrFalse = 0;
		unsigned int i = 0, j = 0;
		unsigned int check = 0;
		unsigned int counter = 0;
		unsigned int size = arrLength(row);
		unsigned int sizeCuvant = arrLength(cuvant);
		unsigned int alternativeVar = 0;
		
		for(; i < size; i++)
		{
			check = isBlank(row+i);
			if(check != 1)
			{
				alternativeVar = alternative(row+i,cuvant+j);
				if(*(row+i) == *(cuvant+j))
				{
					j++;
					counter++;
				}
				else if (alternativeVar == 1)
				{
					j++;
					counter++;
				}
				else
				{
					j = 0;
					counter = 0;
				}

			}else
			{
				j = 0;
				counter = 0;
			}
			if(counter == sizeCuvant)
			{
				trueOrFalse = 1;
				break;
			} 
		}
		return trueOrFalse;
	}
}

void main ()
{
	char strRow1[] = "C is a general purpose programming language initially";
	char strRow2[] = "developed by Dennis Ritchie between";
	char strRow3[] = "1969 and 1973 at Bell Labs";

	char* Arr[] = {strRow1, strRow2, strRow3};

	int i = 0;
	int counter = 0;

	char cuvant[] = {"BELL"};

	for(; i < 3; i++)
	{
		if(searchWord(*(Arr+i), cuvant) == 1)
		{
			printf("TRUE\n");
			break;
		}
		else
		{
			counter++;
		}
	}
	if(counter == 3)
	{
		printf("FALSE\n");
	}


}

#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 3 EX 9
/*
9. Write a function that appends a string to another string
*/
#if(SET == 3 && EX == 9)


void append(char *primulCuvant, char *alDoileaCuvant,  int currentLength, int sizePrimulCuvant,  int sizeIntreg, int *actualSizeOfRow)
{
	if((primulCuvant != NULL) && (alDoileaCuvant != NULL) && (actualSizeOfRow != NULL))
	{
		unsigned char i = 0;
		if((currentLength+sizeIntreg) < sizePrimulCuvant)
		{
			for(; i < sizeIntreg; i++)
			{
				*(primulCuvant+currentLength+i) = *alDoileaCuvant++;
			}
			*(primulCuvant+currentLength+i) = '\0';
		}
		*actualSizeOfRow = arrLength(primulCuvant);
	}
	printf("%d ", *actualSizeOfRow);
}


void main ()
{
	char strRow1[20];
	char strRow2[] = {"Primul"};
	char strRow3[] ={ "Al doilea"};
	
	int actualSizeOfRow = 0;

	strncpy(strRow1,strRow2, sizeof(strRow2), sizeof(strRow1));

	append(strRow1, strRow3, arrLength(strRow1), sizeof(strRow1), sizeof(strRow3), &actualSizeOfRow);

	printf("String: %s \n", strRow1);
}

#endif
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 3 EX 10
/*
10. Se dau 2 siruri de dimensiuni egale. Al doileas sir contine doar cifre.
Se cere sa se construieasca un alt treilea sir, prin repetarea pe rand, a fiecarui caracter din primul sir,
de un numar de ori egal cu cifra corespunzatoare din al doilea sir.

"abc" , "243" -> "aabbbbccc"
*/
#if(SET == 3 && EX == 10)

unsigned int dimensiuneSirTrei(unsigned char *sir2, const char dimensiuneSiruri)
{
	unsigned int dimensiuneAlTreileaSirTemp = 0;
	unsigned int asciiConv = 48;

	if( sir2 != NULL)
	{
		int i = 0;
		
		for(; i < dimensiuneSiruri; i++)
		{
			dimensiuneAlTreileaSirTemp += (*(sir2+i) - asciiConv);
		}
		printf("%d\n", dimensiuneAlTreileaSirTemp);
	}

	return dimensiuneAlTreileaSirTemp;
}


void alTreileaSir(unsigned char *sir1,unsigned char* sir2, const char dimensiuneSiruri, unsigned char *sir3)
{
	if( sir1 != NULL && sir2 != NULL)
	{
		int i = 0, j = 0, asciiConv = 48, counterSirTrei = 0;

		for(; i < dimensiuneSiruri; i++)
		{
			j = 0;
			for(; j < (*(sir2+i) - asciiConv); j++, counterSirTrei++)
			{
				*(sir3+counterSirTrei) = *(sir1+i);
				printf("%c", *(sir3+counterSirTrei));
			}
		}
		printf("\n");
		*(sir3+counterSirTrei) = '\0';
	}
}



void main ()
{
	unsigned char sir1[] = {"abc"};
	unsigned char sir2[] = {"243"};
	unsigned int size = arrLengthChar(sir1);
	unsigned int size2 = arrLengthChar(sir2);
	//int dimensineSirulTrei = dimensiuneSirTrei(sir2, size)

	unsigned char sir3[10];

	alTreileaSir(sir1, sir2, size, sir3);

}
#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 4 EX 1
/*
1.	Avand variabila SIU_PCR pe 8 biti (unsigned char) care impacheteaza urmatoarele campuri (valori pozitive): DSC, ODE, HYS, WPE si WPS folositi structuri si uniuni 
	pentru a schimba atat variabila cat si campurile acesteia. Folositi o functie care seteaza campurile (folositi un pointer ca argument) si o functie care afiseaza 
	variabila si campurile acesteia (argumentul nu este pointer).

	Tineti cont ca PC-ul are arhitectura little-endian.
*/

#if(SET == 4 && EX == 1)

typedef union _SIU_PCR_u
{
	struct _SIU_PCR_s
	{
		unsigned char WPS : 1;
		unsigned char WPE : 1;
		unsigned char res : 2;
		unsigned char HYS : 1;
		unsigned char ODE : 1;
		unsigned char DSC : 2;
	}SIU_PCR_s;

	unsigned char SIU_PCR;

}SIU_PCR_u;

void changeFields(unsigned char *SIU_PCR_P, fields position, unsigned char valoare)
{
	if(SIU_PCR_P != NULL)
	{
		SIU_PCR_u *SIU_PCR = (SIU_PCR_u*)SIU_PCR_P;

		switch(position)
		{
			case WPS : 
				SIU_PCR->SIU_PCR_s.WPS = valoare; 
				break;
			case WPE : 
				SIU_PCR->SIU_PCR_s.WPE = valoare; 
				break;
			case res : 
				SIU_PCR->SIU_PCR_s.res = valoare; 
				break;
			case HYS : 
				SIU_PCR->SIU_PCR_s.HYS = valoare; 
				break;
			case ODE : 
				SIU_PCR->SIU_PCR_s.ODE = valoare; 
				break;
			case DSC : 
				SIU_PCR->SIU_PCR_s.DSC = valoare; 
				break;
			default : 
				printf("Position not supported : %u \n", position);
				break;
		}
	}
}

void printFields(unsigned char SIU_PCR)
{
	int i = MAX_CHAR_BITS;

	SIU_PCR_u *SIU_PCR_P = (SIU_PCR_u*)&SIU_PCR;

	printf("\n%u\n", SIU_PCR_P->SIU_PCR);

	printf("%u", SIU_PCR_P->SIU_PCR_s.DSC);

	printf("%u", SIU_PCR_P->SIU_PCR_s.ODE);

	printf("%u", SIU_PCR_P->SIU_PCR_s.HYS);

	printf("%u", SIU_PCR_P->SIU_PCR_s.res);

	printf("%u", SIU_PCR_P->SIU_PCR_s.res);

	printf("%u", SIU_PCR_P->SIU_PCR_s.WPE);

	printf("%u", SIU_PCR_P->SIU_PCR_s.WPS);

	printf("\n");
}

void setReg(unsigned char *SIU_PCR, unsigned char valoare)
{
	if(SIU_PCR != NULL)
	{
		SIU_PCR_u *SIU_PCR_P = (SIU_PCR_u*)SIU_PCR;

		SIU_PCR_P->SIU_PCR = valoare;
	}
}


void main()
{
	unsigned char valoare = 1;
	unsigned char value = 0;
	fields pos = WPS;

	changeFields(&value, pos, valoare);
	pos = WPE;
	valoare = 1;
	changeFields(&value, pos, valoare);
	pos = HYS;
	valoare = 1;
	changeFields(&value, pos, valoare);
	pos = DSC;
	valoare = 1;
	changeFields(&value, pos, valoare);
	valoare = 101;
	setReg(&value, valoare); 
	printFields(value);
}

#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 4 EX 2
/*
2.	Fie un numar oarecare (definit printr-o directiva de preprocesare) de porturi, fiecare port avand o linie de iesire digitala (Out) si o linie de feedback (In) corespunzatoare iesirii - prin care se poate verifica ca intr-adevar iesirea are valoarea dorita (0=off sau 1=on).
Fie urmatoarea diagrama de stari prin care se seteaza starea unui port (stare normala, scurt-circuit la masa, scurt-circuit la baterie):

- Pentru fiecare port, stocati urmatoarele informatii: Out, In si starea curenta. 
- Pentru simularea valorilor Out si In se poate folosi functia rand()%2 astfel incat sa aveti 
  numai valori aleatoare de 0 si 1 (includeti biblioteca stdlib.h).
- Pentru starea curenta folositi un enum. 
- Pentru alegerea starii folositi switch-case.
- Folositi cate o functie pentru tratarea fiecarei stari.
- Initial, fiecare port e in starea “Normal”.
- Programul va rula in bucla de un numar limitat de ori (dat printr-o directiva de 
  preprocesare).

*/
// struct ptr port cu in out si stare
// enum pentru stare

#if(SET == 4 && EX == 2)

#define REPETARI 20

void S_SCBaterie(port *ports)
{
	if ((ports != NULL))
	{
		stare_e matStareBaterie[2][2] = {{ normal, SCB}, { SCM, SCB }};
		ports->starePort = matStareBaterie[ports->Pins_s.out][ports->Pins_s.in];
	}
}


void S_SCMasa(port *ports)
{
	if ((ports != NULL))
	{
		stare_e matStareMasa[2][2] = {{ SCM, SCB}, { SCM, normal }};
		ports->starePort = matStareMasa[ports->Pins_s.out][ports->Pins_s.in];
	}
}

void S_Normal(port *ports)
{
	if ((ports != NULL))
	{
		stare_e matStareNormal[2][2] = {{ normal, SCB}, { SCM, normal }};
		ports->starePort = matStareNormal[ports->Pins_s.out][ports->Pins_s.in];
	}

}

void setStare(port *ports) // switch in functie de stare care vine prin parametru
{
	if ((ports != NULL))
	{
		switch(ports->starePort)
		{
			case normal : 
				S_Normal(ports);
				break;
			case SCM : 
				S_SCMasa(ports);
				break;
			case SCB : 
				S_SCBaterie(ports);
				break;
			default: 
				printf("State not supported : \n");
				break;
		}
	}
}

void main()
{
	port port1 = {normal, 0};
	unsigned int i = 0;

	printf("NORMAL = 0 \n   SCM = 1 \n   SCB = 2 \n");

	for(; i < REPETARI; i++)
	{
		port1.Pins_s.in = rand() % 2;
		port1.Pins_s.out = rand() % 2;
		setStare(&port1);
		printf("OUT: %d, IN: %d, STARE: %d \n", port1.Pins_s.out, port1.Pins_s.in, port1.starePort);
	}
}

#endif
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//SET 4 EX 3
/*
3.	Fie o “baza de date” cu parametrii de calibrare. Pentru fiecare parametru de calibrare, stocati urmatoarele informatii: nume parametru, tip (intreg pe 8biti, intreg pe16biti, intreg pe 32biti, boolean, float) – folositi un enum, valoarea.
a)	Scrieti o functie prin care initializati baza de date cu toti parametri.
b)	Scrieti o functie care afiseaza baza de date.
c)	Scrieti o functie care sorteaza parametrii dupa tip (in ordinea: (intreg pe 8biti, intreg pe16biti, intreg pe 32biti, boolean, float) si o alta functie care sorteaza dupa valoare (pentru parametrii de tip boolean: valorile true=1 si false=0). 
Folositi metoda bubble-sort, pentru swap folositi o functie separata.

*/

#if(SET == 4 && EX == 3)
// variabila globala de tip array in care pastram parametri de calibrare

static int counter = 0;

void initBD(parDC *paramC)
{
	if(paramC != NULL)
	{
		switch(counter)
		{
			case 0 : 
				paramC->tipul = uint16;
				paramC->tipSolicitat_u.uint16 = 42;
				memcpy(paramC->vec,"Short",sizeof("Short"));
				break;
			case 1 :
				paramC->tipul = uint32f;
				paramC->tipSolicitat_u.uint32f = 123.521;
				memcpy(paramC->vec,"Float",sizeof("Float"));
				break;
			case 2: 
				paramC->tipul = uint8;
				paramC->tipSolicitat_u.uint8 = 14;
				memcpy(paramC->vec,"Char",sizeof("Char"));
				break;
			case 3:
				paramC->tipul = uint32;
				paramC->tipSolicitat_u.uint32 = 1055;
				memcpy(paramC->vec,"Int",sizeof("Int"));
				break;
			case 4: 
				paramC->tipul = boolean_;
				paramC->tipSolicitat_u.BOOL = TRUE;
				memcpy(paramC->vec,"BoolTrue",sizeof("BoolTrue"));
				break;
			case 5: 
				paramC->tipul = boolean_;
				paramC->tipSolicitat_u.BOOL = FALSE;
				memcpy(paramC->vec,"BoolFals",sizeof("BoolFals"));
				break;
			default: 
				printf("Error");
				break;
		}
		counter++;
	}
}

void printBD(parDC *vecStruct)
{
	char i = 0;
	if(vecStruct != NULL)
	{
		for(; i < 6; i++)
		{
			printf("Nume: %s ", vecStruct[i].vec);
			switch(vecStruct[i].tipul)
			{
				case uint8:
					printf("    Tip: CHAR  Valoare: %d\n", vecStruct[i].tipSolicitat_u.uint8);
					break;
				case uint16:
					printf("   Tip: SHORT Valoare: %d\n", vecStruct[i].tipSolicitat_u.uint16);
					break;
				case uint32:
					printf("     Tip: INT   Valoare: %d\n", vecStruct[i].tipSolicitat_u.uint32);
					break;
				case boolean_:
					printf("Tip: BOOL  Valoare: %d\n", vecStruct[i].tipSolicitat_u.BOOL);
					break;
				case uint32f:
					printf("   Tip: FLOAT Valoare: %f\n", vecStruct[i].tipSolicitat_u.uint32f);
					break;
				default:
					printf("ErrorPrint");
					break;
			}
		}
	}
}

void sortBDValoare(parDC *vecStruct)
{
	if(vecStruct != NULL)
	{
		bubbleSortBDVal(vecStruct);
	}
}

void sortBDTip(parDC *vecStruct)
{
	if(vecStruct != NULL)
	{
		bubbleSortBDTip(vecStruct);
	}
}

// convertim toate tipurile la valoarea cea mai mare
void main()
{
	parDC vecStruct[7];
	int i = 0;
	int j = 0;

	for(; i < 6; i++)
	{
		initBD(&vecStruct[i]);
		
	}

	for(; j < 6; j++)
	{
		printf("%d", vecStruct[j].tipul);
	}
	printf("\n");
	sortBDTip(vecStruct);

	printBD(vecStruct);
	for(j = 0; j < 6; j++)
	{
		printf("%d", vecStruct[j].tipul);
	}
	printf("\n");

	sortBDValoare(vecStruct);

	printBD(vecStruct);
}

#endif

