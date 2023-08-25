#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e){
	int pivot = arr[e];
	int pindex = s;
	for(int i =s;i<e;i++){
		if(arr[i]<pivot){
			swap(arr[i],arr[pindex]);
			pindex++;
		}
	}
	swap(arr[e],arr[pindex]);
	return pindex;
}

int partition_r(int arr[],int s, int e){
	srand(time(NULL));
	int random = s + rand() % (e-s);
	
	swap(arr[random],arr[e]);
	return partition(arr,s,e);
}

void quicksort(int arr[], int s,int e){
	if(s<e){
		int p = partition_r(arr,s,e);
		quicksort(arr,s,p-1);
		quicksort(arr,p+1,e);
	}
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout<<arr[i]<<" ";
}
 
// Driver Code
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
    quicksort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
     
    return 0;
}