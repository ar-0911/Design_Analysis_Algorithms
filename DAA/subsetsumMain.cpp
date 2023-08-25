#include<bits/stdc++.h>
using namespace std;

int arr[]={1,3,5,2};
int n = 4;
int tar = 6;
stack<int> s;
bool found = false;

void print_solution(){
	stack<int>temp;
	while(!s.empty()){
		temp.push(s.top());
		s.pop();
	}
	while(!temp.empty()){
		cout<<temp.top()<<"\t";
		s.push(temp.top());
		temp.pop();
	}
	cout<<endl;
}

void solve(int curr,int ind){
	if(curr>tar){
		return;
	}
	if(curr == tar){
		found = true;
		print_solution();
		return;
	}
	for(int i = ind;i<n;i++){
		s.push(arr[i]);
		solve(curr+arr[i],i+1);
		s.pop();
	}
}

int main(){
	solve(0,0);
	if(!found){
		cout<<"no solution";
	}
	return 0;
}