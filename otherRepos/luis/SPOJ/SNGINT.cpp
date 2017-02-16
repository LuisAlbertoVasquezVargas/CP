#include<bits/stdc++.h>
void solve(int n){
	if(n==0){puts("10");return;}
	if(n==1){puts("1");return;}
	std::vector<int>F(10),best,cur;
	for(auto k:{5,7,2,3}){while(n%k==0) n/=k,F[k]++;}
	if(n!=1){puts("-1");return;}
	int alpha=F[2],betha=F[3];
	int lenBest=INT_MAX;
	for(int a=0;a<=1;++a)for(int d=0;(d<=1)&&(a+d<=alpha);++d)for(int b=0;(b<=1)&&(b+d<=betha);++b)for(int c=0;(c<=1)&&(a+2*c+d<=alpha);++c){
		int e=alpha-(a+2*c+d),f=betha-(b+d);
		if(e%3==0&&f%2==0){
			e/=3,f/=2;
			cur={0,0,a,b,c,F[5],d,F[7],e,f};
			if(a+b+c+d+e+f<lenBest){lenBest=a+b+c+d+e+f;best=cur;continue;}
			if(a+b+c+d+e+f==lenBest){best=max(best,cur);continue;}
		}
	}
	for(int i=2;i<=9;++i)for(int j=0;j<best[i];++j)printf("%d",i);
	puts("");
}
int main(){
	int tc,n;
	scanf("%d",&tc);
	while(tc--){scanf("%d",&n);solve(n);}
}

