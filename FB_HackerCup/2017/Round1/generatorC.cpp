#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int main(){
	int cases=100,n=100,m=5000,K=5000,val=1000000;
	cout<<cases<<'\n';
	REP(tc,cases){
		cout<<n<<" "<<m<<" "<<K<<'\n';
		REP(i,m){
			while(1){
				int a=1+rand()%n;
				int b=1+rand()%n;
				if(a==b)continue;
				int g=1+rand()%1000;
				cout<<a<<" "<<b<<" "<<g<<'\n';
				break;
			}
		}
		REP(i,K){
			while(1){
				int a=1+rand()%n;
				int b=1+rand()%n;
				if(a==b)continue;
				cout<<a<<" "<<b<<'\n';
				break;
			}
		}
	}
}
