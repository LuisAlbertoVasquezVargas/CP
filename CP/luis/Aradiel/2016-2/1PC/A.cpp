#include<bits/stdc++.h>
using namespace std;

int main(){
	double x , y;
	while(scanf("%lf%lf" , &x , &y) == 2){
		if(y >= 0 && y <= 2) break;
		printf("Incorrect values\n");
	}
	double X = x - y - 1;
	double S = 0;
	double term = X;
	int den = 2 , it = 0;
	while(1){
		if(abs(term) < 1e-6) break;
		S += term;
		term = term * X / den;
		den ++;
		it ++;
	}
	printf("Number of iterations : %d\n" , it);
	printf("Algorithm calculation : %.10f\n",S);
	printf("Exact value           : %.10f\n",exp(X) - 1);
	//https://en.wikipedia.org/wiki/Exponential_function#Formal_definition
}


