#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "DFAonDES.h"


/*---------------------------------------------------------------------------------------------------------------------------------*/
static long getL(long x) {
	long a = (x >> 32) & 0xFFFFFFFFL;
	return a;
}
/*---------------------------------------------------------------------------------------------------------------------------------*/	
static long getR(long x) {
	long a = x & 0xFFFFFFFFL;
	return a;
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static long permutation(long aPermuter, int tableDePermutation[] ,int inputSize, int outputSize) {
	long res = 0x0L;
	long bitPermuted, mask;
	for (int i = 0; i < outputSize; i++) {
		mask = 0x1L << (inputSize - tableDePermutation[i]);
		bitPermuted = aPermuter & mask;
		if (bitPermuted != 0){
			bitPermuted = 0x1L;
			bitPermuted = bitPermuted << (outputSize - i - 1);
		} 
		res = res | bitPermuted;
	}
	return res;
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static long expension(long aEtendre) {
	return permutation(aEtendre, E, 32, 48);
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static long rotationCirculaire(long x) {
	long poidsFort;
	long n = (long)pow(2, 27);
	if (x > n) {
		poidsFort = 1;
	}else {
		poidsFort = 0;
	}
    x = x << 1;
    x = (x & 0x0FFFFFFFL) | poidsFort;
    return x;
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static long leftShift(long T) {
    long C = (T & 0xFFFFFFF0000000L) >> 28;
    long D = T & 0x0000000FFFFFFFL;

	C = rotationCirculaire(C);
	D = rotationCirculaire(D);
	
	C = C << 28;
	return (C | D);
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static long* keySchedule(long cleffMaitresse) {
	long* subKeys = malloc(16*sizeof(long));
	int nbPermutations[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
	long T = permutation(cleffMaitresse, PC1, 64, 56);
	
	for(int i = 0; i < 16; i++) {
		if (nbPermutations[i] == 1) {
			T = leftShift(T);
		}else {
			T = leftShift(leftShift(T));
		}
		subKeys[i] = permutation(T, PC2, 56, 48);
	}
	return subKeys;
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static long f_function(long R, long subKeys) {
	long block, msbDoubled, lsb;
	int line, column;
	long T = expension(R) ^ subKeys;
	long res = 0x0L;
	for (int i = 1 ; i < 9 ; i++){
		block = (T >> (48 - i*6)); 
		
		msbDoubled = (block & 0b100000) >> 4;
		lsb = block & 1;
	
		line = (int)(msbDoubled + lsb);
		column = (int) ((block & 0b011110) >> 1);
		
		res = res | (Sbox[i - 1][line][column] << (32 - i*4));
	}
	return permutation(res, P, 32, 32);
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static long DES(long clair, long K) {
	long* subKeys =  keySchedule(K);
	
	long clairIP = permutation(clair, IP, 64, 64);
	
	long L = getL(clairIP);
	long R = getR(clairIP);
	
	long LiPlus1, RiPlus1;
	for (int i = 0; i < 16; i++) {
		LiPlus1 = R;
		RiPlus1 = L ^ f_function(R, subKeys[i]);
		L = LiPlus1;
		R = RiPlus1;	
	}
	long swapped = (R << 32) | L;
	return permutation(swapped, IPinv, 64, 64);
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static long rechercheDeK16ParmisToutesLesPossibites(long K16, int sol[][6][64], int nbSol[][6], int s) {
	int numSolf0 = 0;
	long candidat = (long) sol[s][0][numSolf0];
	for (int f = 1; f < 6; f++){
		int numSolf;
		for (numSolf = 0; numSolf < nbSol[s][f]; numSolf++) {
			if (candidat == sol[s][f][numSolf]) break;
		}
		if (numSolf == nbSol[s][f]){
			if (numSolf0+1 >= nbSol[s][0]){
				printf("\nProblème Sbox : \n");
				break;
			}
			f = 1;
			++numSolf0;
			candidat = (long) sol[s][0][numSolf0];
		}
	}
	printf("Solution %d = ",(s+1));
	K16 = K16 << 6;
	K16 = K16 | candidat;
	printf("K16 actuel = %lx",K16);
	printf("\n");
	return K16;
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static void isSolutionValide(long verif, long E_R15, long E_R15f, int sol[][6][64], int nbSol[][6], int s, int f) {
	long tmp; long tmpf; int r; int c; int rf; int cf;
	for (int k16i = 0; k16i < 64; k16i++) {
		tmp = ((E_R15 & mask6[s]) >> ((7 - s) * 6)) ^ k16i;
		tmpf = ((E_R15f & mask6[s]) >> ((7 - s) * 6)) ^ k16i;
		/*-------------------------------------------*/
		r = (int) (2 * ((tmp & 0x20) >> 5) + (tmp & 0x1));
		c = (int) ((tmp & 0x1E) >> 1);
		/*-------------------------------------------*/
		rf = (int) (2 * ((tmpf & 0x20) >> 5) + (tmpf & 0x1));
		cf = (int) ((tmpf & 0x1E) >> 1);
		/*-------------------------------------------*/
		int PP = (int) ((verif & mask4[s]) >> ((7 - s) * 4));
		int SS = Sbox[s][r][c] ^ Sbox[s][rf][cf];
		/*-------------------------------------------*/
		if ( PP ==	SS ) {	
			sol[s][f][nbSol[s][f]] = k16i;
			++nbSol[s][f];
		}
	}
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static void afficherLesPotentiellesCles(int sol[][6][64], int nbSol[][6], int s) {
	printf("\nSbox %d",s + 1);
	for (int f = 0; f < 6; f++) {
		printf(" Faute: %d => solutions: %d possibles\t", f+1, nbSol[s][f]);
		for (int i = 0; i < nbSol[s][f]; i++) { 
			printf(" %d ",sol[s][f][i]);
		}
		printf("\n");
	}
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
long find_K16(long chiffreJuste, long chiffreFaux[]) {
	long K16 = 0x000000000000L;
	long dechiffJuste, dechiffFaux, L16, R15, L16f, R15f, verif, E_R15, E_R15f;
	/*-------------------------------------------*/
	int sol[8][6][64];
	int nbSol[8][6];
	
	/*-------------------------------------------*/
	dechiffJuste = permutation(chiffreJuste, IP, 64, 64); 
	L16 = getL(dechiffJuste); 
	R15 = getR(dechiffJuste);
	/*-------------------------------------------*/
	for (int s = 0; s < 8; s++) {
		for (int f = 0; f < 6; f++) {
			dechiffFaux = permutation(chiffreFaux[faux[s][f]], IP, 64, 64);
			L16f = getL(dechiffFaux); 
			R15f = getR(dechiffFaux);
			/*-------------------------------------------*/

			verif = permutation(L16 ^ L16f, Pinv, 32, 32);
			E_R15 = permutation(R15, E, 32, 48); 
			E_R15f = permutation(R15f, E, 32, 48);
			/*-------------------------------------------*/
			isSolutionValide(verif, E_R15, E_R15f, sol, nbSol, s, f);
		}
		afficherLesPotentiellesCles(sol, nbSol, s);
		K16 = rechercheDeK16ParmisToutesLesPossibites(K16, sol, nbSol, s);
	}
	return K16;
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static long rechercheDes8bitsInconnus(long mask) {
	long pos[] = {14, 15, 19, 20, 51, 54, 58, 60};
	long res = 0x0L;
	
	for(int i = 0; i < 8; i++) 
		res = res | ( ((mask >> i) & 1) << (64 - pos[i]) );

	return res;
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static long find_K56(long clair, long chiffre, long K16) {
	long K48b = permutation(permutation(K16, PC2inv, 48, 56), PC1inv, 56, 64);
	
	//System.out.println("\n48 bons bits de K = "+K48b);
	long mask = 0x00L;
	long hypothesis = K48b;
	
	while( mask < 256 && chiffre != DES(clair, hypothesis) ) 
	{
		hypothesis = K48b | rechercheDes8bitsInconnus(mask);
		mask = mask + 1;
	}
	if (mask == 256)
		printf("\nProblème : impossible de trouver K 56 bits\n");
	
	return hypothesis;
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
static long find_K(long K56b) {
	long res = K56b;
	long tmp, parite;
	
	for(int i = 0; i < 8; i++) {
		parite = 0;
		for(int j = 0; j < 8; j++) {
			if(j != 7) {
				tmp = 0x1L << ( ((7 - i) * 8) + (7 - j) );
				tmp = K56b & tmp;
				parite = tmp ? parite ^ 1 : parite ^ 0;
			}
			else {
				tmp = !parite;
				res |= tmp << ((7 - i) * 8);
			}
		}
	}
	return res;
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------------------------------*/
int main(){
	long clair = 0xDF1549D00BA1E0C4L; 
	long chiffreJuste = 0x633CC798738D9EDAL;
	long chiffreFaux[] = {  0x6139C7D8738C9EDAL, 0x632EC798738C9EDAL, 0x633CC59C738C9EDAL, 0x636CC7DA638D9EDAL, 
			                0x627CC79C618C9EDAL, 0x627CC798738F9EDAL, 0x623CC798638D9CDAL, 0x633CC39963999ED8L, 
							0x6A7CC799238D9EDAL, 0x6334C798339D9EDAL, 0x633CCF99739D9EDAL, 0x233CC79073D99EDAL, 
							0x233CC7993BD99EDAL, 0x633CD79873859EDBL, 0x233CD798738D96DAL, 0x233CD79877CD8ED2L, 
							0x433CC79873CD8F9BL, 0x631CC798738D8E9AL, 0x633CE798778D9F9AL, 0x773CC7B8778D9E9AL, 
							0x673C8698578D9F9AL, 0x773CC79873AD9EDAL, 0x733C8698738DBEDAL, 0x733C8798728DDEFAL, 
							0xF73CC788738DDEDAL, 0x63BCC788728D9EDAL, 0x633C4788738DDADAL, 0x6338C718728DDACAL, 
							0x633CC798F38DDACEL, 0x6339C798730D9EDAL, 0x6338C798738D1EDEL, 0x6339C7D8738C9E4AL };	
	
	long K16 = find_K16(chiffreJuste, chiffreFaux);
	printf("%lx\n", K16);

	long K56 = find_K56(clair, chiffreJuste, K16);
	printf("%lx\n", K56);

	long K = find_K(K56);
	printf("%lx\n", K);	

	printf("Vérification de la clé trouvée\n");
	printf("Chiffré donné = %lx\n",chiffreJuste);
	printf("Chiffré trouvé = %lx\n",DES(clair,K));

	return 0;
}