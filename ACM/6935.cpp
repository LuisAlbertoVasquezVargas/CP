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
#define DEBUG( x ) cout <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cout << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

void solve( ll &curW , ll &curB , ll FW , ll FB , ll F , int &ans ){
	ll a = FW * curB;
	if( a % FB ){
		curW += F;
		return;
	}
	ll x = (a / FB) - curW;
	if( x > 0 && x <= F ){
		ans ++;
		curW += F;
		return;
	}else{
		curW += F;
		return;
	}
}

char s[ 5 ];
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vi v , w;
		ll FW = 0 , FB = 0 ;
		REP( i , n ){
			int x;
			sc( x );
			scanf( "%s" , s );
			v.pb( x );
			w.pb( s[ 0 ] == 'W' );
			if( s[ 0 ] == 'W' ) FW += x;
			else FB += x;
		}
		if( FW == 0 ){
			cout << FB << '\n';
			continue;
		}
		if( FB == 0 ){
			cout << FW << '\n';
			continue;
		}
		int ans = 0;
		ll curW = 0 , curB = 0;
		REP( i , n ){
			if( w[ i ] == 1 ){
				solve( curW , curB , FW , FB , v[ i ] , ans );
			}else{
				solve( curB , curW , FB , FW , v[ i ] , ans );
			}
		}
		printf( "%d\n" , ans );
	}
}




