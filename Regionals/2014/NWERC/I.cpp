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
 
#define N 14
 
typedef long long ll;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef vector< vvll > vvvll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll D[N + 1][N + 1];
int n;
ll L;
void add( vvvll &mat , vi &v ){
	sort( all( v ) );
	do{
		ll d = 0;
		REP( i , SZ(v) - 1 ) d += D[ v[ i ] ][ v[ i + 1 ] ];
		mat[ v.front() ][ v.back() ].pb( d );
	}while( next_permutation( all(v) ) );
}
void solve(){
	if( n == 2 ){
		if( 2LL * D[ 0 ][ 1 ] == L ) cout << "possible\n";
		else cout << "impossible\n";
		return;
	}
	vi len = { (n - 1)/2 , n - (n - 1)/2 };
	REP( mask , (1 << (n - 1)) ){
		if( __builtin_popcount( mask ) == len[ 0 ] ){
			vi v , w;
			REP( i , n - 1 )
				if( mask & (1 << i) ) v.pb( i + 1 );
				else w.pb( i + 1 );
			
			vvvll mat1(n ,vvll(n)) , mat2(n , vvll(n));
			add( mat1 , v );
			add( mat2 , w );

			REP( i , n )REP( j , n ){
				sort( all( mat1[i][j] ) );
				sort( all( mat2[i][j] ) );
			}
			/// 0 [ A ] [ B ]
			// D[iniB][finB] = L - (d( 0 , iniA ) + (p)D[iniA][finA] + d(finA , iniB) +  + d(finB,0)) 
			for( int iniA = 1 ; iniA < n ; ++iniA )
				for( int finA = 1 ; finA < n ; ++finA )
					for( int iniB = 1 ; iniB < n ; ++iniB )
						for( int finB = 1 ; finB < n ; ++finB ){
							ll target = L - D[0][iniA] - D[finA][iniB] - D[finB][0];
							for( auto p : mat1[iniA][finA] )
								if( binary_search( all(mat2[iniB][finB]) , target - p ) ){
									cout << "possible\n"; 
									return;
								}
						}	
		}
	}
	cout << "impossible\n";
}
int main(){
	while( cin >> n >> L ){
		REP( i , n ) REP( j , n ) cin >> D[ i ][ j ];
		solve();
	}	
}




