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

#define N 1000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

string ans;
int state[ N + 5 ];
int NEXT[ N + 5 ][ 2 ];
ll B[ N + 5 ];

int main(){
	ios_base :: sync_with_stdio( 0 );
	ll balls;
	while( cin >> balls ){
		int n;
		cin >> n;
		ans = string( n , '*' );
		REP( i , n ){
			char c;
			int L , R;
			cin >> c >> L >> R;
			int cur = i + 1;
			state[ cur ] = (c == 'L'? 0 : 1);
			NEXT[ cur ][ 0 ] = L;
			NEXT[ cur ][ 1 ] = R;
		}
		REP( i , n + 1 ) B[ i ] = 0;
		
		queue< int > Q;
		Q.push( 1 );
		B[ 1 ] = balls;
		while( !Q.empty() ){
			int u = Q.front(); Q.pop();
			//DEBUG2( u , B[ u ] );
			if( !B[ u ] ) continue;
			if( u == 0 ) continue;
			
			int v = NEXT[ u ][ state[ u ] ];
			int w = NEXT[ u ][ state[ u ] ^ 1 ];
			
			ll parity = (B[ u ] & 1);
			state[ u ] ^= parity;
			ll cant = B[ u ] >> 1;
			B[ v ] += (B[ u ] - cant);
			B[ w ] += cant;
			//DEBUG2( B[v] , B[w] );
			B[ u ] = 0;
			Q.push( v );
			Q.push( w );
		}
		REP( i , n ) ans[ i ] = state[ i + 1 ] ? 'R' : 'L';
		cout << ans << '\n';
	}
}





