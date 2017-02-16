#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define all(v) v.begin(),v.end()

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef vector<int> vi;
typedef long double ld;
const int MAX_N=2000;
ld C[MAX_N+1][MAX_N+1];
ld get(int n,int k,int t,ld p){
	ld ans=1;
	REP(it,t)ans*=(it+1.0);
	REP(it,k)ans*=p/(it+1.0);
	REP(it,t-k)ans*=(1.0-p)/(it+1.0);
	return ans;
}
int main(){
	REP(i,MAX_N+1)C[i][i]=C[i][0]=1;
	for(int i=2;i<=MAX_N;++i)
		for(int j=1;j<i;++j)
			C[i][j]=C[i-1][j-1]+C[i-1][j];

	int n,t;
	ld p;
	while(cin>>n>>p>>t){
		ld ans=0;
		for(int k=0;k<=t;++k){
			ans+=C[t][k]*min(n,k)*pow(p,k)*pow(1-p,t-k);
			//ans+=get(n,k,t,p)*min(n,k);
		}
		printf("%.10f\n",(double)ans);
	}
}
