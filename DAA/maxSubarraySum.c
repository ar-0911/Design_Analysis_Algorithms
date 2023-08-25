#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
	return (a>b?a:b);
}

int max2(int a,int b,int c){
	return (max(max(a,b),c));
}
int maxcrossingSum(int arr[],int l, int m, int h){
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
	for(int i = m;i<=h;i++){
		sum+=arr[i];
		if(sum>right_sum){
			right_sum = sum;
		}
	}
	return max2(left_sum+right_sum-arr[m],left_sum,right_sum);
}

int maxSubarraySum(int arr[], int l, int h){
	if(l>h){
		return INT_MIN;
	}
	if(l==h){
		return arr[l];
	}
	int m = (l+h)/2;
	return max2(maxSubarraySum(arr,l,m-1),
			   maxSubarraySum(arr,m+1,h),
			   maxcrossingSum(arr,l,m,h));
}

int main(){
	int arr[] = {2,3,4,5,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	int max_sum = maxSubarraySum(arr,0,n-1);
	printf("Maximum continguos sum is: %d",max_sum);
	return 0;
}