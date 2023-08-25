#include<iostream>
#include<stack>
using namespace std;
int a[]={1,3,5,2};
int n = 4;
int target=6;
stack<int>stck;
bool found = false;

void print(){
	stack<int>temp;
	while(!stck.empty()){
		temp.push(stck.top());
		stck.pop();
	}
	while(!temp.empty()){
		cout<<temp.top();
		stck.push(temp.top());
		temp.pop();
	}
	cout<<"\n";
}

void solve(int curr, int ind){
	if(curr>target){
		return;
	}
	if(curr==target){
		found = true;
		print();
		return;
	}
	for(int i =ind;i<n;i++){
		stck.push(a[i]);
		solve(curr+a[i],i+1);
		stck.pop();
	}
}

int main(){
	solve(0,0);
	if(found ==false){
		cout<<"no solution";
		return 0;
	}
}