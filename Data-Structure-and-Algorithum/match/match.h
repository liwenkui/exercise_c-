#include <cstring>
int match(char *P,char* T){
	size_t n=strlen(T),i=0;
	size_t m=strlen(P),j;
	for(i=0;i<n-m+1;i++){
		for(j=0;j<m;j++)
			if(T[i+j]!=P[j]) break;
		if(j>=m)break;
	}
	return i;
}
