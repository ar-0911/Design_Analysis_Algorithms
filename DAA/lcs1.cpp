##include<stdio.h>
#include<string.h>


int m,n,value[20][20];
char x[20],y[20],way[20][20];

void print_sequence(int i,int j){
	if(i==0 || j==0){
		return;
	}
	if(way[i][j]=='c'){
		print_sequence(i-1,j-1);
		printf("%c",x[i-1]);
	}
	else if(way[i][j]=='u'){
		print_sequence(i-1,j);
	}
	else{
		print_sequence(i,j-1);
	}
}

void lcs(){
	m = strlen(x);
	n = strlen(y);
	int i,j;
	for(i=0;i<=m;i++){
		value[i][0]=0;
	}
	for(j=0;j<=m;j++){
		value[0][j]=0;
	}
	
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(x[j-1]==y[j-1]){
				value[i][j] = value[i-1][j-1]+1;
				way[i][j]='c';
			}
			else{
				if(value[i-1][j]>value[i][j-1]){
					value[i][j]=value[i-1][j];
					way[i][j]='u';
				}
				else{
					value[i][j]=value[i][j-1];
					way[i][j]='l';
				}
			}
		}		
	}
}

int main(){
	pritntf("Enter first sequence: ");
	scanf("%s",x);
	pritntf("Enter second sequence: ");
	scanf("%s",y);
	lcs();
	print_sequence(m,n);
	return 0;
}