#include<bits/stdc++.h>
using namespace std;

void compute_lps(char* pat, int m, int* lps);

void kmp(char* pat, char* text){
	int m = strlen(pat);
	int n = strlen(text);
	
	int lps[m];
	
	compute_lps(pat,m,lps);
	
	int i=0;
	int j=0;
	while(i<n){
		if(text[i]==pat[j]){
			i++;
			j++;
		}
		else{
			if(j!=0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}
		if(j==m){
			cout<<"index found at: "<<i-j<<endl;
			j = lps[j-1];
		}
	}
}

void compute_lps(char* pat, int m, int* lps){
	lps[0]=0;
	int len=0;
	int i =1;
	while(i<m){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len = lps[len-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}

int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    kmp(pat, txt);
    return 0;
}