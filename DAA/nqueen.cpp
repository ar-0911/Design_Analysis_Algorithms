#include<bits/stdc++.h>
using namespace std;

int n;
bool found = false;
int board[20][20];

void print_solution(){
	int i,j;
	for(int i = 0 ; i<n;i++){
		for(int j = 0; j < n;j++){
			if(board[i][j]==1){
				cout<<" Q ";
			}
			else{
				cout<<" - ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}

bool isSafe(int row,int col){
	int i,j;
	
	//checking in same row
	for(i=0;i<n;i++){
		if(board[row][i]==1)
			return false;
	}
	
	//checking upper left diagonal
	for(i = row, j = col ; i >= 0 && j >= 0; i--,j--){
		if(board[i][j]==1)
			return false;
	}
	
	//checking lower left diagonal
	for(i = row, j = col ; i < n && j >= 0; i++,j--){
		if(board[i][j]==1)
			return false;
	}
	return true;
}

void solve(int col){
	if(col == n){
		found = true;
		print_solution();
		return;
	}
	
	for(int i =0 ;i < n ; i++){
		if(isSafe(i,col)){
			board[i][col]=1;
			solve(col+1);
			board[i][col]=0;
		}
	}
}

int main(){
	cout<<"Enter numbr of queens: ";
	cin>>n;
	solve(0);
	if(!found){
		cout<<"no solution";
	}
	return 0 ;
}