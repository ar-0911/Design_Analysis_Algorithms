#include<bits/stdc++.h>
using namespace std;

#define d 256

void rabin_karp(char pat[],char text[],int q){
	int m = strlen(pat);
	int n = strlen(text);
	int p=0;
	int t=0;
	int h = 1;
	int i,j;
	//calculating pow(d,m-1)%q
	for(i = 0;i<m-1;i++){
		h = (h*d)%q;
	}
	
	for(i =0;i<m;i++){
		p = (d * p + pat[i]) % q;
		t = (d * t+ text[i]) % q;
	}                      
	
	for(i=0;i<=n-m;i++){
		//if hash value is same;
		if(p==t){
			for(j = 0;j<m;j++){
				if(text[i+j]!=pat[j]){
				break;
				}
			}	
			if(j==m){
				cout<<"pattern found at index "<<i<<endl;
			}	
		}
		if(i<n-m){
			t = (d*(t-text[i]*h)+text[i+m])%q;
		}
		if(t<0){
			t=(t+q);
		}
	}
}

int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
 
    // we mod to avoid overflowing of value but we should
    // take as big q as possible to avoid the collison
    int q = INT_MAX;
 
    // Function Call
    rabin_karp(pat, txt, q);
    return 0;
}
 

