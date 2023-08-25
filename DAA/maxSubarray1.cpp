#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
	return a>b?a:b;
}

int max1(int a,int b,int c){
	return max(max(a,b),c);
}

int maxCrossingSum(int arr[], int l, int r, int m){
	int sum = 0;
	int left_sum = INT_MIN;
	for(int i=m;i>=l;i--){
		sum+=arr[i];
		if(sum>left_sum){
			left_sum = sum;
		}
	}
	
	sum = 0;
	int right_sum = INT_MIN;
	for(int i = m;i<=r;i++){
		sum+=arr[i];
		if(sum>right_sum){
			right_sum = sum;
		}
	}
	
	return max1(left_sum,right_sum,left_sum+right_sum-arr[m]);
}


int maxSubarraySum(int arr[], int l, int r){
	//base case
	if(l>r){
		return INT_MIN;
	}
	
	if(l==r){
		return arr[l];
	}
	
	int m = (l+r)/2;
	return max1(maxSubarraySum(arr,l,m-1),
				maxSubarraySum(arr,m+1,r),
				maxCrossingSum(arr,l,r,m));
}


int main(){
	int arr[]={-2,1,-3,4,-1,2,1,-5,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<"Largest sum is: "<<maxSubarraySum(arr,0,size-1);
	return 0;
}




