#include<iostream>
#include<cstdio>

using namespace std;

#define MOD1 1000000007
#define MOD2 1000000009
#define MOD3 1000000011

string b;
int a;

long long M1,M2,M3;

void f(){
	M1=0;M2=0;
	for(int i=0;i<b.length();i++){
		M2=(M2*10+(b[i]-'0'))%MOD2;
		M1=(M1*10+(b[i]-'0'))%MOD1;
		M3=(M3*10+(b[i]-'0'))%MOD3;
		
	}
}


int t;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&a);
		cin>>b;
		f();	
		long long a1=1,a2=1,a3=1;
		int ans=0;
		while(a1!=M1&&a2!=M2&&a3!=M3){
			a1=(a1*a)%MOD1;
			a2=(a2*a)%MOD2;
			a3=(a3*a)%MOD3;
			ans++;
		}
		cout<<ans<<endl;
	}
	
}
