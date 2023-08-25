#include<bits/stdc++.h>
using namespace std;

struct item{
	int profit;
	int weight;
	
	item(int profit, int weight){
		this->profit = profit;
		this->weight= weight;
	}
};

static bool cmp(struct item a, struct item b){
	double r1 = (double)a.profit/(double)a.weight;
	double r2 = (double)b.profit/(double)b.weight;
	
	return r1>r2;
}

double fractionalKnapsack(int TWeight, struct item arr[], int No_of_objects){
	
	sort(arr,arr+No_of_objects,cmp);
	double final_val = 0.0;
	
	for(int i=0;i<No_of_objects;i++){
		if(arr[i].weight<=TWeight){
			TWeight -= arr[i].weight;
			final_val += arr[i].profit; 
		}
		
		else{
			final_val += arr[i].profit*((double)TWeight/(double)arr[i].weight);
			break;
		}
	}
	
	return final_val;
}

int main(){
	int W=50;
	item arr[]={{60,10},{100,20},{120,30}};
	int N = sizeof(arr)/sizeof(arr[0]);
	cout<<fractionalKnapsack(W,arr,N);
}