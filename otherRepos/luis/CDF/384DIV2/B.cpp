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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int solve(int myN,ll K){
	for(int n=myN;n>=1;--n){
		ll len=(1LL<<(n-1))-1;
		if(K<=len)continue;
		if(K==len+1)return n;
		K-=len+1;
	}
	assert(0);
}
int main(){
	int myN;
	ll K;
	while(cin>>myN>>K)
		cout<<solve(myN,K)<<'\n';
}


