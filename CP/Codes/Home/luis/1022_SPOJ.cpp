#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 300
#define NA 22500
#define NB 22500

typedef vector< int > vi;

int nA , nB ;
int match[ NB + 5 ] , vis[ NA + 5 ];
vi G[ NA + 5 ];
int dfs( int u ){
	if( vis[ u ] ) return 0;
	vis[ u ] = 1;
	REP( i , G[ u ].size() ){
		int v = G[ u ][ i ];
		if( match[ v ] == -1 || dfs( match[ v ] ) ){
			match[ v ] = u;
			return 1;
		}
	}
	return 0;
}

char S[ N + 5 ][ N + 5 ];
int mat[ N + 5 ][ N + 5 ] , MAT[ N + 5 ][ N + 5 ];
/*
void print( int t[ N + 5 ][ N + 5 ] , int a , int b ){
	REP( i , a ) REP( j , b ) cout << t[ i ][ j ] << char( j + 1 == b ? 10 : 32 );
	cout << endl;
}*/
int main(){
	int cases , R , C;
	char c;
	cin >> cases;
	REP( tc , cases ){
		cin >> R >> C;
		REP( i , R ) REP( j , C ) cin >> c , S[ i ][ j ] = c;
		nA = 0;
		for( int i = 0 ; i < R ; ++i ){
			for( int j = 0 ; j < C ; ++j ){
				if( S[ i ][ j ] == 'A' ) {
					mat[ i ][ j ] = -1;
					continue;
				}
				int ind;
				for( int k = j ; k < C ; ++k )
					if( S[ i ][ k ] != 'A' ) ind = k;
					else break;
				for( int k = j ; k <= ind ; ++k ) mat[ i ][ k ] = nA;
				nA ++;
				j = ind;
			}
		}
		nB = 0;
		for( int j = 0 ; j < C ; ++j ){
			for( int i = 0 ; i < R ; ++i ){
				if( S[ i ][ j ] == 'A' ) {
					MAT[ i ][ j ] = -1;
					continue;
				}
				int ind;
				for( int k = i ; k < R ; ++k )
					if( S[ k ][ j ] != 'A' ) ind = k;
					else break;
				for( int k = i ; k <= ind ; ++k )
					MAT[ k ][ j ] = nB;
				nB ++;
				i = ind;
			}
		}
		REP( i , nA ) G[ i ].clear();
		REP( i , R ) REP( j , C ) 
			if( MAT[ i ][ j ] != -1 && S[ i ][ j ] !=  'D' )
				G[ mat[ i ][ j ] ] . pb( MAT[ i ][ j ] );
		REP( i , nB ) match[ i ] = -1;
		int ans = 0;
		REP( i , nA ){
			clr( vis , 0 );
			ans += dfs( i );
		}
		printf( "%d\n" , ans );
	}
}


