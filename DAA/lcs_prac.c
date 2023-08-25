#include<string.h>
#include<stdio.h>
//i = rows and j = columns
int m,n,c[20][20];
char x[20],y[20],way[20][20];
int i,j;

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
	for(i=0;i<=m;i++){
		c[i][0]=0;
	}
	for(j=0;j<=m;j++){
		c[0][j]=0;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(x[i-1] == y[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				way[i][j]='c';
			}
			else if(c[i-1][j]>c[i][j-1]){
				c[i][j] = c[i-1][j];
				way[i][j] = 'u';
			}
			else{
				c[i][j] = c[i][j-1];
				way[i][j]='l';
			}
		}
	}
}

int main(){
	printf("Enter first sequence: ");
	scanf("%s",x);
	printf("Enter second sequence: ");
	scanf("%s",y);
	lcs();
	print_sequence(m,n);
}