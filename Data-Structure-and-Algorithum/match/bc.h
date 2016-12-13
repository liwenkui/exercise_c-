#include <cstring>

int* buildBC(char *P){
	int *bc=new int[256];
	for(size_t j=0;j<256;j++)
		bc[j]=-1;
	for(size_t m=strlen(P),j=0;j<m;j++)
		bc[P[j]]=j;
	return bc;
}
