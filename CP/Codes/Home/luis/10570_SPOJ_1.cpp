#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 100100
#define LOGN 21
#define INF (1<<30)

typedef vector< int > vi;

int n , gap;
string s;
int sa[ N + 5 ] , tmp[ N + 5 ] , lcp[ N + 5 ] , pos[ N + 5 ];
int sufCmp( int i , int j ){
	if( pos[ i ] != pos[ j ] ) return pos[ i ] < pos[ j ];
	i += gap , j += gap;
	return (i < n && j < n) ? pos[ i ] < pos[ j ] : i > j;
}
void buildSA(){
	n = s.size();
	REP( i , n ) pos[ i ] = s[ i ] , sa[ i ] = i;
	for( gap = 1 ; ; gap <<= 1 ){
		sort( sa , sa + n , sufCmp );
		REP( i , n - 1 ) tmp[ i + 1 ] = tmp[ i ] + sufCmp( sa[ i ] , sa[ i + 1 ] );
		REP( i , n ) pos[ sa[ i ] ] = tmp[ i ];
		if( tmp[ n - 1 ] == n - 1 ) break;
	}
}
void buildLCP(){
	for( int i = 0 , k = 0 ; i < n ; ++i )
		if( pos[ i ] != n - 1 ){
			for( int j = sa[ pos[ i ] + 1 ] ; s[ i + k ] == s[ j + k ]; ) ++k;
			lcp[ pos[ i ] ] = k;
			if( k ) --k;
		}
}
int rmq[ LOGN + 1 ][ N + 5 ];
void buildRMQ(){
	REP( i , n ) rmq[ 0 ][ i ] = lcp[ i ];
	for( int k = 1 ; k <= LOGN ; ++k )
		for( int i = 0 ; i + (1<<k) <= n ; ++i )
			rmq[ k ][ i ] = min( rmq[ k - 1 ][ i ] , rmq[ k - 1 ][ i + (1<<(k - 1)) ] );
}
int query( int i , int j ){
	int r = 31 - __builtin_clz( j - i + 1 );
	return min( rmq[ r ][ i ] , rmq[ r ][ j - (1<<r) + 1 ] );
}
int LCP( int i , int j ){
	return query( i , j - 1 );
	int mini = INF;
	for( int k = i ; k < j ; ++k ) mini = min( mini , lcp[ k ] );
	return mini;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	string t;
	int cases , m;
	cin >> cases;
	REP( tc , cases ){
		cin >> m;
		s.clear();
		REP( i , m ){
			cin >> t;
			s += t + string( 1 , '$' + i );
		}
		if( m == 1 ){
			cout << t.size() << '\n';
			continue;
		}
		buildSA();
		buildLCP();
		buildRMQ();
		vi id( n , -1 );
		int sz = 0;
		for( int i = 0 ; i < n ; ++i )
			if( isalpha( s[ i ] ) ){
				int ind;
				for( int j = i ; j < n ; ++j )
					if( isalpha( s[ j ] ) ) ind = j , id[ j ] = sz;
					else break;
				sz++;
				i = ind;
			}
		vi last( m , -1 );
		int ans = 0;
		REP( i , n ){
			if( id[ sa[ i ] ] == -1 ) continue;
			last[ id[ sa[ i ] ] ] = max( last[ id[ sa[ i ] ] ] , i );
			int mini = INF;
			REP( j , m )
				mini = min( mini , last[ j ] );
			if( mini == -1 ) continue;
			ans = max( ans , LCP( mini , i ) );
		}
		//REP( i , n ) cout << setw( 2 ) << s[ i ] << char( i + 1 == n ? 10 : 32 );
		//REP( i , n ) cout << setw( 2 ) << id[ i ] << char( i + 1 == n ? 10 : 32 );
		cout << ans << '\n';
	}
}
