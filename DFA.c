#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void afficherTab(bool t[], int n){
	int i;
	for ( i = 0, printf("["); i < n; ++i){
		printf("%d", t[i]);
		if(i < n-1) printf(", ");
	}
	printf("]");
	printf("\n");
}
bool* permutationIni(bool M[], int n){
	bool* IP = malloc(n*sizeof(bool));
	IP[0]  = M[57]; IP[1]  = M[49]; IP[2]  = M[41]; IP[3]  = M[33]; IP[4]  = M[25]; IP[5]  = M[17]; IP[6]  = M[9];  IP[7]  = M[1]; 
	IP[8]  = M[59]; IP[9]  = M[51]; IP[10] = M[43]; IP[11] = M[35]; IP[12] = M[27]; IP[13] = M[19]; IP[14] = M[11]; IP[15] = M[3]; 
	IP[16] = M[61]; IP[17] = M[53]; IP[18] = M[45]; IP[19] = M[37]; IP[20] = M[29]; IP[21] = M[21]; IP[22] = M[13]; IP[23] = M[5]; 
	IP[24] = M[63]; IP[25] = M[55]; IP[26] = M[47]; IP[27] = M[39]; IP[28] = M[31]; IP[29] = M[23]; IP[30] = M[15]; IP[31] = M[7]; 
	IP[32] = M[56]; IP[33] = M[48]; IP[34] = M[40]; IP[35] = M[32]; IP[36] = M[24]; IP[37] = M[16]; IP[38] = M[8];  IP[39] = M[0]; 
	IP[40] = M[58]; IP[41] = M[50]; IP[42] = M[42]; IP[43] = M[34]; IP[44] = M[26]; IP[45] = M[18]; IP[46] = M[10]; IP[47] = M[2]; 
	IP[48] = M[60]; IP[49] = M[52]; IP[50] = M[44]; IP[51] = M[36]; IP[52] = M[28]; IP[53] = M[20]; IP[54] = M[12]; IP[55] = M[4]; 
	IP[56] = M[62]; IP[57] = M[54]; IP[58] = M[46]; IP[59] = M[38]; IP[60] = M[30]; IP[61] = M[22]; IP[62] = M[14]; IP[63] = M[6]; 

	return IP;
}
bool* permutationFin(bool M[], int n){ 
	bool* IP = malloc(n*sizeof(bool));
	IP[0]  = M[39]; IP[1]  = M[7]; IP[2]  = M[47]; IP[3]  = M[15]; IP[4]  = M[55]; IP[5]  = M[23]; IP[6]  = M[63]; IP[7]  = M[31]; 
	IP[8]  = M[38]; IP[9]  = M[6]; IP[10] = M[46]; IP[11] = M[14]; IP[12] = M[54]; IP[13] = M[22]; IP[14] = M[62]; IP[15] = M[30]; 
	IP[16] = M[37]; IP[17] = M[5]; IP[18] = M[45]; IP[19] = M[13]; IP[20] = M[53]; IP[21] = M[21]; IP[22] = M[61]; IP[23] = M[29]; 
	IP[24] = M[36]; IP[25] = M[4]; IP[26] = M[44]; IP[27] = M[12]; IP[28] = M[52]; IP[29] = M[20]; IP[30] = M[60]; IP[31] = M[28]; 
	IP[32] = M[35]; IP[33] = M[3]; IP[34] = M[43]; IP[35] = M[11]; IP[36] = M[51]; IP[37] = M[19]; IP[38] = M[59]; IP[39] = M[27]; 
	IP[40] = M[34]; IP[41] = M[2]; IP[42] = M[42]; IP[43] = M[10]; IP[44] = M[50]; IP[45] = M[18]; IP[46] = M[58]; IP[47] = M[26]; 
	IP[48] = M[33]; IP[49] = M[1]; IP[50] = M[41]; IP[51] = M[9];  IP[52] = M[49]; IP[53] = M[17]; IP[54] = M[57]; IP[55] = M[25]; 
	IP[56] = M[32]; IP[57] = M[0]; IP[58] = M[40]; IP[59] = M[8];  IP[60] = M[48]; IP[61] = M[16]; IP[62] = M[56]; IP[63] = M[24]; 

	return IP;
}
bool* expension(bool M[], int n){ 
	bool* IP = malloc(n*sizeof(bool));
	IP[0]  = M[31]; IP[1]  = M[0];  IP[2]  = M[1];  IP[3]  = M[2];  IP[4]  = M[3];  IP[5]  = M[4];
	IP[6]  = M[3];  IP[7]  = M[4];  IP[8]  = M[5];  IP[9]  = M[6];  IP[10] = M[7];  IP[11] = M[8];
	IP[12] = M[7];  IP[13] = M[8];  IP[14] = M[9];  IP[15] = M[10]; IP[16] = M[11]; IP[17] = M[12];
	IP[18] = M[11]; IP[19] = M[12]; IP[20] = M[13]; IP[21] = M[14]; IP[22] = M[15]; IP[23] = M[16];
	IP[24] = M[15]; IP[25] = M[16]; IP[26] = M[17]; IP[27] = M[18]; IP[28] = M[19]; IP[29] = M[20];
	IP[30] = M[19]; IP[31] = M[20]; IP[32] = M[21]; IP[33] = M[22]; IP[34] = M[23]; IP[35] = M[24];
	IP[36] = M[23]; IP[37] = M[24]; IP[38] = M[25]; IP[39] = M[26]; IP[40] = M[27]; IP[41] = M[28];
	IP[42] = M[27]; IP[43] = M[28]; IP[44] = M[29]; IP[45] = M[30]; IP[46] = M[31]; IP[47] = M[0];

	return IP;
}
bool* permutationSimple(bool M[], int n){
	bool* IP = malloc(n*sizeof(bool));
	IP[0]  = M[15]; IP[1]  = M[6];  IP[2]  = M[19]; IP[3]  = M[20];
	IP[4]  = M[28]; IP[5]  = M[11]; IP[6]  = M[27]; IP[7]  = M[16];
	IP[8]  = M[0];  IP[9]  = M[14]; IP[10] = M[22]; IP[11] = M[25];
	IP[12] = M[4];  IP[13] = M[17]; IP[14] = M[30]; IP[15] = M[9];
	IP[16] = M[1];  IP[17] = M[7];  IP[18] = M[23]; IP[19] = M[13];
	IP[20] = M[31]; IP[21] = M[26]; IP[22] = M[2];  IP[23] = M[8];
	IP[24] = M[18]; IP[25] = M[12]; IP[26] = M[29]; IP[27] = M[5];
	IP[28] = M[21]; IP[29] = M[10]; IP[30] = M[3];  IP[31] = M[24];

	return IP;
}
bool* permutationSimpleInver(bool M[], int n){
	bool* IP = malloc(n*sizeof(bool));
	IP[0]  = M[8];  IP[1]  = M[16]; IP[2]  = M[22]; IP[3]  = M[30];
	IP[4]  = M[12]; IP[5]  = M[27]; IP[6]  = M[1];  IP[7]  = M[17];
	IP[8]  = M[23]; IP[9]  = M[15]; IP[10] = M[29]; IP[11] = M[5];
	IP[12] = M[25]; IP[13] = M[19]; IP[14] = M[9];  IP[15] = M[0];
	IP[16] = M[7];  IP[17] = M[13]; IP[18] = M[24]; IP[19] = M[2];
	IP[20] = M[3];  IP[21] = M[28]; IP[22] = M[10]; IP[23] = M[18];
	IP[24] = M[31]; IP[25] = M[11]; IP[26] = M[21]; IP[27] = M[6];
	IP[28] = M[4];  IP[29] = M[26]; IP[30] = M[14]; IP[31] = M[20];

	return IP;
}
void decouperEn6bits(bool* E, bool* R15S1, bool* R15S2, bool* R15S3, bool* R15S4, bool* R15S5, bool* R15S6, bool* R15S7, bool* R15S8){
	for (int i = 0; i < 48; ++i){
		if (i < 6){
			R15S1[i] = E[i]; 
		}else if (i >= 6 && i < 12 ){
			R15S2[i - 6] = E[i];
		}else if (i >= 12 && i < 18){
			R15S3[i - 12] = E[i];
		}else if (i >= 18 && i < 24){
			R15S4[i - 18] = E[i];
		}else if (i >= 24 && i < 30){
			R15S5[i - 24] = E[i];
		}else if (i >= 30 && i < 36){
			R15S6[i - 30] = E[i];
		}else if (i >= 36 && i < 42){
			R15S7[i - 36] = E[i];
		}else if (i >= 42 && i < 48){
			R15S8[i - 42] = E[i];
		}
	}
}
void decouperEn4bits(bool* E, bool* R16S1, bool* R16S2, bool* R16S3, bool* R16S4, bool* R16S5, bool* R16S6, bool* R16S7, bool* R16S8){
	for (int i = 0; i < 32; ++i){
		if (i < 4){
			R16S1[i] = E[i]; 
		}else if (i >= 4  && i < 8 ){
			R16S2[i - 4] = E[i];
		}else if (i >= 8 && i < 12){
			R16S3[i - 8] = E[i];
		}else if (i >= 12 && i < 16){
			R16S4[i - 12] = E[i];
		}else if (i >= 16 && i < 20){
			R16S5[i - 16] = E[i];
		}else if (i >= 20 && i < 24){
			R16S6[i - 20] = E[i];
		}else if (i >= 24 && i < 28){
			R16S7[i - 24] = E[i];
		}else if (i >= 28 && i < 32){
			R16S8[i - 28] = E[i];
		}
	}
}
void decouperEn2(bool* C, bool* R, bool* L){
	for (int i = 0; i < 64; ++i){
		if (i < 32){
			R[i] = C[i];
		}else{
			L[i - 32] = C[i];
		}
	}
}
bool* xOr(bool p[], bool q[], int n){
	bool* IP = malloc(n*sizeof(bool));
	for (int i = 0; i < n; ++i){
		IP[i] = p[i]^q[i];
	}

	return IP;
}
void determinationDeDiffInputEtOutput(bool* C, bool* Cf){

	//printf("--------------La permutation du chifffré pour Obtenire L16 et R16----------------\n");
	bool* t = permutationIni(C, 64);
	//printf("Permut(C) : "); afficherTab(t, 64);

	//printf("--------------La permutation du chifffré pour Obtenire L16 et R16----------------\n");
	bool* tf = permutationIni(Cf, 64);
	//printf("Permut(Cf): "); afficherTab(tf, 64);


/*	int* d = permutationFin(t, 64);
	afficherTab(d, 64);*/
	//printf("--------------L16 et R16----------------\n");
	bool* L = malloc(32*sizeof(bool));
	bool* R = malloc(32*sizeof(bool));

	decouperEn2(t, R, L);

	//printf("R16 : "); afficherTab(R, 32);
	//printf("L16 : "); afficherTab(L, 32);

	//printf("--------------L16f et R16f fautés----------------\n");
	bool* Lf = malloc(32*sizeof(bool));
	bool* Rf = malloc(32*sizeof(bool));

	decouperEn2(tf, Rf, Lf);

	//printf("R16f : "); afficherTab(Rf, 32);
	//printf("L16f : "); afficherTab(Lf, 32);

/*----------------------------------------------------*/
/*	bool* per = permutationSimple(R,32);
	printf("per : "); afficherTab(per, 32);

	bool* perInv = permutationSimpleInver(per,32);
	printf("perInv:"); afficherTab(perInv, 32);
	printf("R16 :  "); afficherTab(R, 32);*/
/*----------------------------------------------------*/

	//printf("---------R15 = L16, Expension de R15---------\n");
	bool* E = expension(L, 48);
	//printf("E   : "); afficherTab(E, 48);

	//printf("---------R15f = L16f, Expension de R15f fauté---------\n");
	bool* Ef = expension(Lf, 48);
	//printf("Ef  : "); afficherTab(Ef, 48);
/*-----------------------------------------------------*/
	//printf("--------------Decoupage en 8 block de 6 bits pour E(R15)----------------\n");
	bool* R15S1 = malloc(6*sizeof(bool));
	bool* R15S2 = malloc(6*sizeof(bool));
	bool* R15S3 = malloc(6*sizeof(bool));
	bool* R15S4 = malloc(6*sizeof(bool));
	bool* R15S5 = malloc(6*sizeof(bool));
	bool* R15S6 = malloc(6*sizeof(bool));
	bool* R15S7 = malloc(6*sizeof(bool));
	bool* R15S8 = malloc(6*sizeof(bool));

	decouperEn6bits(E, R15S1, R15S2, R15S3, R15S4, R15S5, R15S6, R15S7, R15S8);
/*
	printf("R15S1 : "); afficherTab(R15S1, 6);
	printf("R15S2 : "); afficherTab(R15S2, 6);
	printf("R15S3 : "); afficherTab(R15S3, 6);
	printf("R15S4 : "); afficherTab(R15S4, 6);
	printf("R15S5 : "); afficherTab(R15S5, 6);
	printf("R15S6 : "); afficherTab(R15S6, 6);
	printf("R15S7 : "); afficherTab(R15S7, 6);
	printf("R15S8 : "); afficherTab(R15S8, 6);*/

	//printf("--------------Decoupage en 8 block de 6 bits pour E(R15f) fauté----------------\n");
	bool* R15S1f = malloc(6*sizeof(bool));
	bool* R15S2f = malloc(6*sizeof(bool));
	bool* R15S3f = malloc(6*sizeof(bool));
	bool* R15S4f = malloc(6*sizeof(bool));
	bool* R15S5f = malloc(6*sizeof(bool));
	bool* R15S6f = malloc(6*sizeof(bool));
	bool* R15S7f = malloc(6*sizeof(bool));
	bool* R15S8f = malloc(6*sizeof(bool));

	decouperEn6bits(Ef, R15S1f, R15S2f, R15S3f, R15S4f, R15S5f, R15S6f, R15S7f, R15S8f);
/*
	printf("R15S1f : "); afficherTab(R15S1f, 6);
	printf("R15S2f : "); afficherTab(R15S2f, 6);
	printf("R15S3f : "); afficherTab(R15S3f, 6);
	printf("R15S4f : "); afficherTab(R15S4f, 6);
	printf("R15S5f : "); afficherTab(R15S5f, 6);
	printf("R15S6f : "); afficherTab(R15S6f, 6);
	printf("R15S7f : "); afficherTab(R15S7f, 6);
	printf("R15S8f : "); afficherTab(R15S8f, 6);*/

	printf("----------------------Différence en Input des s-box----------------------\n");

	bool* sI_1 = xOr(R15S1, R15S1f, 6);
	printf("sI_1  : "); afficherTab(sI_1, 6);

	bool* sI_2 = xOr(R15S2, R15S2f, 6);
	printf("sI_2  : "); afficherTab(sI_2, 6);

	bool* sI_3 = xOr(R15S3, R15S3f, 6);
	printf("sI_3  : "); afficherTab(sI_3, 6);

	bool* sI_4 = xOr(R15S4, R15S4f, 6);
	printf("sI_4  : "); afficherTab(sI_4, 6);

	bool* sI_5 = xOr(R15S5, R15S5f, 6);
	printf("sI_5  : "); afficherTab(sI_5, 6);

	bool* sI_6 = xOr(R15S6, R15S6f, 6);
	printf("sI_6  : "); afficherTab(sI_6, 6);

	bool* sI_7 = xOr(R15S7, R15S7f, 6);
	printf("sI_7  : "); afficherTab(sI_7, 6);

	bool* sI_8 = xOr(R15S8, R15S8f, 6);
	printf("sI_8  : "); afficherTab(sI_8, 6);

	/*-----------------------------------------------------*/
	//printf("--------------Permutation Inverse de P de f pour R16----------------\n");
	bool* PR16 = permutationSimpleInver(R, 32);
	//printf("PR16 :  "); afficherTab(PR16, 32);

	//printf("--------------Decoupage en 8 block de 4 bits pour PR16----------------\n");
	bool* R16S1 = malloc(4*sizeof(bool));
	bool* R16S2 = malloc(4*sizeof(bool));
	bool* R16S3 = malloc(4*sizeof(bool));
	bool* R16S4 = malloc(4*sizeof(bool));
	bool* R16S5 = malloc(4*sizeof(bool));
	bool* R16S6 = malloc(4*sizeof(bool));
	bool* R16S7 = malloc(4*sizeof(bool));
	bool* R16S8 = malloc(4*sizeof(bool));

	decouperEn4bits(PR16, R16S1, R16S2, R16S3, R16S4, R16S5, R16S6, R16S7, R16S8);
/*
	printf("R16S1 : "); afficherTab(R16S1, 4);
	printf("R16S2 : "); afficherTab(R16S2, 4);
	printf("R16S3 : "); afficherTab(R16S3, 4);
	printf("R16S4 : "); afficherTab(R16S4, 4);
	printf("R16S5 : "); afficherTab(R16S5, 4);
	printf("R16S6 : "); afficherTab(R16S6, 4);
	printf("R16S7 : "); afficherTab(R16S7, 4);
	printf("R16S8 : "); afficherTab(R16S8, 4);*/

	//printf("--------------Permutation Inverse de P de f pour R16f--------------------------------\n");
	bool* PR16f = permutationSimpleInver(Rf, 32);
	//printf("PR16f:  "); afficherTab(PR16f, 32);

	//printf("--------------Decoupage en 8 block de 4 bits pour R16f----------------\n");
	bool* R16S1f = malloc(4*sizeof(bool));
	bool* R16S2f = malloc(4*sizeof(bool));
	bool* R16S3f = malloc(4*sizeof(bool));
	bool* R16S4f = malloc(4*sizeof(bool));
	bool* R16S5f = malloc(4*sizeof(bool));
	bool* R16S6f = malloc(4*sizeof(bool));
	bool* R16S7f = malloc(4*sizeof(bool));
	bool* R16S8f = malloc(4*sizeof(bool));

	decouperEn4bits(PR16f, R16S1f, R16S2f, R16S3f, R16S4f, R16S5f, R16S6f, R16S7f, R16S8f);
/*
	printf("R16S1f : "); afficherTab(R16S1f, 4);
	printf("R16S2f : "); afficherTab(R16S2f, 4);
	printf("R16S3f : "); afficherTab(R16S3f, 4);
	printf("R16S4f : "); afficherTab(R16S4f, 4);
	printf("R16S5f : "); afficherTab(R16S5f, 4);
	printf("R16S6f : "); afficherTab(R16S6f, 4);
	printf("R16S7f : "); afficherTab(R16S7f, 4);
	printf("R16S8f : "); afficherTab(R16S8f, 4);*/

	printf("----------------------Différence en Ouput des s-box----------------------\n");

	bool* sO_1 = xOr(R16S1, R16S1f, 4);
	printf("sO_1  : "); afficherTab(sO_1, 4);

	bool* sO_2 = xOr(R16S2, R16S2f, 4);
	printf("sO_2  : "); afficherTab(sO_2, 4);

	bool* sO_3 = xOr(R16S3, R16S3f, 4);
	printf("sO_3  : "); afficherTab(sO_3, 4);

	bool* sO_4 = xOr(R16S4, R16S4f, 4);
	printf("sO_4  : "); afficherTab(sO_4, 4);

	bool* sO_5 = xOr(R16S5, R16S5f, 4);
	printf("sO_5  : "); afficherTab(sO_5, 4);

	bool* sO_6 = xOr(R16S6, R16S6f, 4);
	printf("sO_6  : "); afficherTab(sO_6, 4);

	bool* sO_7 = xOr(R16S7, R16S7f, 4);
	printf("sO_7  : "); afficherTab(sO_7, 4);

	bool* sO_8 = xOr(R16S8, R16S8f, 4);
	printf("sO_8  : "); afficherTab(sO_8, 4);
}
int main(int argc, char const *argv[])
{
	printf("--------------Le chiffré correct----------------\n");
	bool C[64] =	{0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};

	printf("C       : "); afficherTab(C, 64);
	printf("--------------Le chiffré fauté----------------\n");
	bool Cf[64] =   /*{0,1,1,0,0,0,0,1,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,1,0,0,1,0,1,1,1,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,0,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,1,1,0,0,0,1,1,1,1,1,0,1,1,0,1,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,0,0,1,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,0,0,1,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,1,1,0,0,1,1,1,0,0,1,1,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,1,0,1,1,0,0,0,1,1,1,0,0,1,1,0,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,0,0};
					{0,1,1,0,1,0,1,0,0,1,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,1,0,0,1,0,0,0,1,1,1,0,0,0,1,1,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,1,0,0,1,1,0,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,0,0,1,1,0,0,1,0,1,1,1,0,0,1,1,1,0,0,1,1,1,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,0,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,0,0,0,0,0,1,1,1,0,0,1,1,1,1,0,1,1,0,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,0,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,1,0,0,1,1,1,0,1,1,1,1,0,1,1,0,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,1};
					{0,0,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,1,1,0,0,1,0,1,1,0,1,1,0,1,1,0,1,0};
					{0,0,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,0,1,1,0,1,1,0,0,0,1,1,1,0,1,1,0,1,0,0,1,0};
					{0,1,0,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,0,0,1,1,1,1,1,0,0,1,1,0,1,1};
					{0,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,1,0,1,0,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,1,1,1,1,0,0,0,1,1,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,1,0};
					{0,1,1,1,0,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,0,0,0,1,1,0,1,1,0,0,1,1,1,1,0,1,0,0,1,1,0,1,0};
					{0,1,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1,0,1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,1,1,0,0,0,1,1,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,1,0};
					{0,1,1,1,0,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1,0,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,1,0,0,1,1,0,0,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,0,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,0};
					{1,1,1,1,0,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,1,0};*/
					{0,1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,0,0,0,1,1,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
/*					{0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,1,1,1,0,0,1,0,1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,0,1,1,0,0,1,0,1,0};
					{0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,0,1,0,1,1,0,0,1,1,1,0};
					{0,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,0,0,0,0,1,1,0,1,1,0,0,1,1,1,1,0,1,1,0,1,1,0,1,0};
					{0,1,1,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,1,0,0,0,1,1,1,1,0,1,1,0,1,1,1,1,0};
					{0,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,1,0,1,1,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,1,0};*/

	printf("C fauté : "); afficherTab(Cf, 64);

	determinationDeDiffInputEtOutput(C, Cf);
/*-----------------------------------------------------*/
/*-----------------------------------------------------*/

/*	bool* E = expension(L, 48);
	printf("E   : "); afficherTab(E, 48);
	bool* F = expension(R, 48);
	printf("F   : "); afficherTab(F, 48);

	bool* x = xOr(E,F,48);
	printf("xOr : "); afficherTab(x, 48);*/

/*	free(t);
	free(R);
	free(L);
	free(R15S1);
	free(R15S2);
	free(R15S3);
	free(R15S4);
	free(R15S5);
	free(R15S6);
	free(R15S7);
	free(R15S8);*/


	return 0;
}