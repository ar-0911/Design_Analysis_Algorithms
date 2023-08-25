#include<bits/stdc++.h>
using namespace std;

char x[20],y[20],way[20][20];
int m,n,cost[20][20];

void print_solution(int i,int j){
	if(i==0 || j==0){
		return;
	}
	if(way[i][j]=='c'){
		print_solution(i-1,j-1);
		cout<<x[i-1];
	}
	else if(way[i][j]=='l'){
		print_solution(i,j-1);
	}
	else if(way[i][j]=='u'){
		print_solution(i-1,j);
	}
}


void lcs(){
	m = strlen(x);
	n = strlen(y);
	for(int i=0;i<=m;i++){
		cost[i][0] = 0;
	}
	for(int j = 0;j<=n;j++){
		cost[0][j]=0;
	}
	for(int i =1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(x[i-1]==y[j-1]){
				cost[i][j] = cost[i-1][j-1]+1;
				way[i][j]='c';
			}
			else if(cost[i-1][j]>cost[i][j-1]){
				cost[i][j]=cost[i-1][j];
				way[i][j]='u';
			}
			else{
				cost[i][j]=cost[i][j-1];
				way[i][j]='l';
			}
		}
	}
}

int main(){
	cout<<"Enter first sequence: ";
	cin>>x;
	cout<<"Enter second sequence: ";
	cin>>y;
	lcs();
	cout<<"lcs is: ";
	print_solution(m,n);
	return 0;
}