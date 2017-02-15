#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr<<"hola que hace ?"<<endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int solve(int n,int m,int K){
	if(2*K+3<=n)return (m-1)/K+1;
	return INT_MAX;
}
int solve2(int n,int m,int K){
	if(n>=2*K+1&&m>=2*K+3)return K==1?5:4;
	return INT_MAX;
}
int main(){
	int cases;
	scanf("%d",&cases);
	REP(tc,cases){
		int n,m,K;
		scanf("%d%d%d",&n,&m,&K);
		int ans=INT_MAX;
		ans=min(ans,solve(n,m,K));
		ans=min(ans,solve(m,n,K));

		ans=min(ans,solve2(n,m,K));
		ans=min(ans,solve2(m,n,K));
		if(ans>=INT_MAX)ans=-1;
		printf("Case #%d: %d\n",tc+1,ans);
	}
}


