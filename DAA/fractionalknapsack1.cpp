#include<bits/stdc++.h>
using namespace std;

struct item{
	int value;
	int weight;
};

bool compare(struct item a,struct item b){
	struct item x = a;
	struct item y = b;
	double r1 = (double)x.value/(double)x.weight;
	double r2 = (double)y.value/(double)y.weight;
	return (r1>r2);
}

double fractional_knapsack(int w,struct item arr[], int n){
	double max_profit = 0.0;
	int bagweight = w;
	sort(arr,arr+n,compare);
	for(int i=0;i<n;i++){
		if(bagweight >= arr[i].weight){
			max_profit+= (double)arr[i].value;
			bagweight -= arr[i].weight;
		}
		else{
			max_profit += arr[i].value*(bagweight/(double)arr[i].weight);
			break;
		}
	}
	return max_profit;
}

int main()
{
    int W = 50;
    struct item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    cout << fractional_knapsack(W, arr, N);
    return 0;
}

