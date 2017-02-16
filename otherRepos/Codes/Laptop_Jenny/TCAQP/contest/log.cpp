#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	int t;
	double a,b;
	scanf("%d",&t);
	while(t--){
		cin>>a>>b;
		cout<<b<<endl;
		long long res=(long long) (log(b)/log(a));
		double dif=1000000.0;
		long long sol;
		for(int i=max(0LL,res-5);i<=res+5;++i){
			double calc=pow(a,i);
			if(fabs(calc-b)<dif){
				dif=fabs(calc-b);
				sol=i;
			}
		}
		cout<<sol<<endl;
	}
}
