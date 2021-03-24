#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void afficherTab(bool t[], int n){
	// for (int i = 0; i < n; ++i){
	// 	printf("%d\t ", t[i]);
	// }
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
	IP[8]  = M[59]; IP[9]  = M[51]; IP[10]  = M[43]; IP[11] = M[35]; IP[12] = M[27]; IP[13] = M[19]; IP[14] = M[11]; IP[15] = M[3]; 
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
	IP[0]  = M[15]; IP[1]  = M[6]; IP[2]  = M[19]; IP[3]  = M[20];
	IP[4]  = M[28]; IP[5]  = M[11]; IP[6]  = M[27]; IP[7]  = M[16];
	IP[8]  = M[0]; IP[9]  = M[14]; IP[10] = M[22]; IP[11] = M[25];
	IP[12] = M[4]; IP[13] = M[17]; IP[14] = M[30]; IP[15] = M[9];
	IP[16] = M[1]; IP[17] = M[7]; IP[18] = M[23]; IP[19] = M[13];
	IP[20] = M[31]; IP[21] = M[26]; IP[22] = M[2]; IP[23] = M[8];
	IP[24] = M[18]; IP[25] = M[12]; IP[26] = M[29]; IP[27] = M[5];
	IP[28] = M[21]; IP[29] = M[10]; IP[30] = M[3]; IP[31] = M[24];

	return IP;
}
bool* xOr(bool p[], bool q[], int n){
	bool* IP = malloc(n*sizeof(bool));
	for (int i = 0; i < n; ++i){
		IP[i] = p[i]^q[i];
	}

	return IP;
}
int main(int argc, char const *argv[])
{
	bool C[64] = {0,1,1,0,0,0,1,1,
			     0,0,1,1,1,1,0,0,
			     1,1,0,0,0,1,1,1,
			     1,0,0,1,1,0,0,0,
			     0,1,1,1,0,0,1,1,
			     1,0,0,0,1,1,0,1,
			     1,0,0,1,1,1,1,0,
			     1,1,0,1,1,0,1,0};

	printf("C : "); afficherTab(C, 64);

	bool* t = permutationIni(C, 64);
	printf("Permut(C) : "); afficherTab(t, 64);

/*	int* d = permutationFin(t, 64);
	afficherTab(d, 64);*/

	bool* L = malloc(32*sizeof(bool));
	bool* R = malloc(32*sizeof(bool));
	for (int i = 0; i < 64; ++i){
		if (i < 32){
			R[i] = t[i];
		}else{
			L[i - 32] = t[i];
		}
	}
	printf("R16 : "); afficherTab(R, 32);
	printf("L16 : "); afficherTab(L, 32);

	printf("---------R15 = L16---------\n");
	bool* E = expension(L, 48);
	printf("E   : "); afficherTab(E, 48);
/*-----------------------------------------------------*/
	bool* R15S1 = malloc(6*sizeof(bool));
	bool* R15S2 = malloc(6*sizeof(bool));
	bool* R15S3 = malloc(6*sizeof(bool));
	bool* R15S4 = malloc(6*sizeof(bool));
	bool* R15S5 = malloc(6*sizeof(bool));
	bool* R15S6 = malloc(6*sizeof(bool));
	bool* R15S7 = malloc(6*sizeof(bool));
	bool* R15S8 = malloc(6*sizeof(bool));
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
	printf("R15S1 : "); afficherTab(R15S1, 6);
	printf("R15S2 : "); afficherTab(R15S2, 6);
	printf("R15S3 : "); afficherTab(R15S3, 6);
	printf("R15S4 : "); afficherTab(R15S4, 6);
	printf("R15S5 : "); afficherTab(R15S5, 6);
	printf("R15S6 : "); afficherTab(R15S6, 6);
	printf("R15S7 : "); afficherTab(R15S7, 6);
	printf("R15S8 : "); afficherTab(R15S8, 6);

	bool* DiffS1Input = xOr(R15S1, R15S1, 6);
	printf("xOr   : "); afficherTab(DiffS1Input, 6);
/*-----------------------------------------------------*/
/*	bool* E = expension(L, 48);
	printf("E   : "); afficherTab(E, 48);
	bool* F = expension(R, 48);
	printf("F   : "); afficherTab(F, 48);

	bool* x = xOr(E,F,48);
	printf("xOr : "); afficherTab(x, 48);*/

	free(t);
	free(R);
	free(L);
	free(R15S1);
	free(R15S2);
	free(R15S3);
	free(R15S4);
	free(R15S5);
	free(R15S6);
	free(R15S7);
	free(R15S8);
	free(DiffS1Input);

	return 0;
}