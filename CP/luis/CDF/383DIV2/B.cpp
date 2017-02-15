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

const int MAX_VAL=(1<<20);
int main(){
	int n,X;
	while(scanf("%d%d",&n,&X)==2){
		vi A(n);
		REP(i,n)scanf("%d",&A[i]);
		vi F(MAX_VAL+1);
		ll ans=0;
		for(int i=n-1;i>=0;--i){
			ans+=F[A[i]^X];
			F[A[i]]++;
		}
		cout<<ans<<'\n';
	}
}

