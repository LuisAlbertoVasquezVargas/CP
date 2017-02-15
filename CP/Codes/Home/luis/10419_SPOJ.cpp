#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define N 100000
#define MOD 1000000007

string s;
int n , gap;
int pos[ N + 5 ] , tmp[ N + 5 ] , sa[ N + 5 ] , lcp[ N + 5 ];

bool sufCmp( int i , int j ){
	if( pos[ i ] != pos[ j ] ) return pos[ i ] < pos[ j ];
	i += gap , j += gap;
	return (i < n && j < n) ? pos[ i ] < pos[ j ] : i > j ;
}
void build(){
	n = s.size();
	REP( i , n ) sa[ i ] = i , pos[ i ] = s[ i ];
	for( gap = 1 ; ; gap <<= 1 ){
		sort( sa , sa + n , sufCmp );
		REP( i , n - 1 ) tmp[ i + 1 ] = tmp[ i ] + sufCmp( sa[ i ] , sa[ i + 1 ] );
		REP( i , n ) pos[ sa[ i ] ] = tmp[ i ];
		if( tmp[ n - 1 ] == n - 1 ) break;
	}
	for( int i = 0 , k = 0 ; i < n ; ++i )
		if( pos[ i ] != n - 1 ){
			for( int j = sa[ pos[ i ] + 1 ] ; s[ i + k ] == s[ j + k ] ; ) ++k;
			lcp[ pos[ i ] ] = k;
			if( k ) --k;
		}
}
int h[ N + 5 ] , bit[ N + 5 ] , DP[ N + 5 ];
void fix( int &x ){
	if( x >= MOD ) x -= MOD;
}
int query( int pos ){
	int sum = 0;
	while( pos ){
		sum += bit[ pos ];
		fix( sum );
		pos -= ( pos & -pos );
	}
	return sum;
}
void update( int pos , int val ){
	while( pos <= N + 1 ){
		bit[ pos ] += val;
		fix( bit[ pos ] );
		pos += ( pos & -pos );
	}
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	while( getline( cin , s ) ){
		build();
		REP( i , n ) h[ i ] = n - sa[ i ];
		/*
		REP( i , n ) cout << h[ i ] << endl;
		cout << endl;*/
		clr( bit , 0 );
		clr( DP , 0 );
		int ans = DP[ 0 ] = 1;
		update( h[ 0 ] , 1 );
		for( int pos = 1 ; pos < n ; ++pos ){
			int &dev = DP[ pos ] = 1;
			dev += query( h[ pos ] );
			fix( dev );
			update( h[ pos ] , dev );
			ans += dev;
			fix( ans );
		}
		cout << ans << '\n';
	}
}

