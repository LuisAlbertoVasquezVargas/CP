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

const int N=(int)1e5;
int P[ N + 5 ];
void sieve(){
	clr( P , -1 );
	P[ 0 ] = P[ 1 ] = 0;
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
}
void primefact( int n , vi &pr , vi &ex ){
	while( 1 ){
		int p = P[ n ];
		if( n == 1 ){
			return;
		}
		if( p == -1 ){
			pr.pb( n ) , ex.pb( 1 );
			break;
		}
		int exp = 0 ;
		while( n % p == 0 ) {
			exp ++;
			n /= p;
		}
		pr.pb( p ) , ex.pb( exp );
	}
}
int main(){
	sieve();
	int n;
	while(scanf("%d",&n)==1){
		vi F(N+5);
		int ans=1;
		REP(i,n){
			int x;
			scanf("%d",&x);
			vi p,e;
			primefact(x,p,e);
			for(auto s:p)
				F[s]++,ans=max(ans,F[s]);
		}
		printf("%d\n",ans);
	}
}


