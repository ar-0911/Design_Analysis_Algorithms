#include<bits/stdc++.h>

using namespace std;

struct Item{
	int profit;
	int weight;
};

bool compare(struct Item a, struct Item b){
	double a_ratio = (double)a.profit/(double)a.weight;
	double b_ration = (double)b.profit/(double)b.weight;
	return (a_ratio>b_ration?true:false);
}

double fractionalKnapsack(struct Item arr[], int w,int n){           // n is size of array
	double max_profit = 0.0;
	sort(arr,arr+n,compare);
	
	for(int i =0;i<n;i++){
		if(arr[i].weight<w){
			max_profit += arr[i].profit;
			w -= arr[i].weight;
		}
		else{
			max_profit += arr[i].profit*(w/(double)arr[i].weight);
			break;
		}
	}
	return max_profit;

}

// Driver Code
int main()
{
    // Weight of knapsack
    int w = 60;
  
    // Given weights and values as a pairs
    Item arr[] = { { 100, 10 },
                   { 280, 40 },
                   { 120, 20 },
                   { 120, 24 } };
  
    int size = sizeof(arr) / sizeof(arr[0]);
  
    // Function Call
    cout << "Maximum profit earned = "
         << fractionalKnapsack(arr, w, size);
    return 0;
}