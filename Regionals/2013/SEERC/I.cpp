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

#define N 5000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int n;
vi G[ N + 5 ];
int vis[ N + 5 ]; //0 not calculated 1 en process 2 calcullated
int cnt = 0;
void dfs( int u ){
	vis[ u ] = 1;
	cnt ++;
	for( auto v : G[ u ] ){
		if( !vis[ v ] ) dfs( v );
	}
}
int f( int u ){
	REP( i , n ) vis[ i ] = 0;
	cnt = 0;
	dfs( u );
	return cnt;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int K;
	while( cin >> n >> K ){
		vi X( K );
		REP( i , K ) cin >> X[ i ] , X[ i ] -- ;
		string dummy;
		getline( cin , dummy );
		
		REP( i , n ) G[ i ].clear();

		REP( i , n ){
			string cad;
			getline( cin , cad );
			int u , v;
			istringstream in( cad );
			in >> u;
			u --;
			while( in >> v ){
				v --;
				G[ u ].pb( v );
			}
		}
		
		REP( i , n ) vis[ i ] = 0;
		
		sort( all( X ) );
		int ind = -1 , maxi = 0;
		for( auto u : X )
			if( f( u ) > maxi ) ind = u , maxi = f( u );
		cout << ind + 1 << '\n';
	}
}



