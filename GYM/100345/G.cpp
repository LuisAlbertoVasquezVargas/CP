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
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;


int main(){
	freopen( "pulp.in" , "r" , stdin );
	freopen( "pulp.out" , "w" , stdout );
	int n;
	while( sc( n ) == 1 ){
		vpii E;
		REP( i , n ){
			int x , y;
			sc( x ) , sc( y );
			E.pb( mp( x , y ) );
		}
		sort( all( E ) );
		string cad = "0";
		ull ans = 0;
		priority_queue< int , vi , greater< int > > Q;
		REP( i , n ){
			Q.push( E[ i ].se );
			ull cur = E[ i ].fi , tope = (i == n - 1) ? ULLONG_MAX : E[ i + 1 ].fi;
			while( SZ( Q ) && cur + Q.top() <= tope ){
				cur += Q.top();
				ans += cur;
				Q.pop();
			}
			if( SZ( Q ) && cur + Q.top() > tope ){
				ull temp = cur + Q.top() - tope;
				Q.pop();
				Q.push( temp );
			}
		}
		cout << ans << '\n';
	}
}


