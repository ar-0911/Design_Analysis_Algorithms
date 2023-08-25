#include<stdio.h>
#include<string.h>

void search (char* pattern, char* text){
	int m = strlen(pattern);
	int n = strlen(text);
	
	for(int i =0;i<=n-m;i++){
		int j;
		
		for(j=0;j<m;j++){
			if(text[i+j]!=pattern[j]){
				break;
			}   
		}
		if(j==m){
			printf("Pattern found a index %d\n",i);
		}
	}
}

int main(){
	char txt[]="AABAACAADABABABAAABA";
	char pat[]="AABA";
	search(pat,txt);
	return 0;
}