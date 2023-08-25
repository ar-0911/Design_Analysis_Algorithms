#include<stdio.h>
#include<math.h>

int num_size(long num){
	int count = 0;
	while(num>0){
		count++;
		num/=10;
	}
	return count;
}

int max(int a,int b){
	return (a>b?a:b);
}

long long karatsuba_multiplication(long num1,long num2){
	if(num1<10 || num2<10){
		return num1*num2;
	}
	int max_size = max(num_size(num1),num_size(num2));
	int m =(int)ceil(max_size/2.0);
	long p = (long)pow(10,m);
	long a = (long)floor(num1/(double)p);
	long b= num1%p;
	long c= (long)floor(num2/(double)p);
	long d = num2%p;
	long ac = karatsuba_multiplication(a,c);
	long bd = karatsuba_multiplication(b,d);
	long ac_bd = karatsuba_multiplication(a+b,c+d)-ac-bd;
	return (long)(long)((ac*pow(10,2*m))+(ac_bd*pow(10,m))+bd);
}

void main(){
	long a,b,answer;
	printf("Enter number 1: ");
	scanf("%ld",&a);
	printf("Enter number 2: ");
	scanf("%ld",&b);
	answer = karatsuba_multiplication(a,b);
	printf("%ld X %ld = %ld\n",a,b,answer);
}