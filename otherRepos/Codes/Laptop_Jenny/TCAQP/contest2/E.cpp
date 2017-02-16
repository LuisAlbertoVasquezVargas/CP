#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define N 105

int n , m , Q;
string S[ N ];

bool val( int x , int u ){ return x >= 0 && x < u; }
bool valid( int x , int y ){
	return val( x , n ) && val( y , m );
}
bool isValid( int i , int j , int k ){
	if( !valid( i - k , j - k ) ) return 0;
	if( !valid( i - k , j + k ) ) return 0;
	if( !valid( i + k , j - k ) ) return 0;
	if( !valid( i + k , j + k ) ) return 0;
	char c = S[ i ][ j ];
	for( int t = - k ; t <= k ; ++t ){
		if( S[ i - k ][ j + t ] != c ) return 0;
		if( S[ i + k ][ j + t ] != c ) return 0;
		if( S[ i + t ][ j - k ] != c ) return 0;
		if( S[ i + t ][ j + k ] != c ) return 0;						
	}
	return 1;
}
int query( int x , int y ){
	int k = 0;
	REP( i , N ) 
		if( isValid( x , y , i ) ) k = i;
		else break;
	return 2*k + 1;
}
int main()
{
	int cases , Q , x , y ;
	cin >> cases;
	while( cases -- ){
		cin >> n >> m >> Q;
		cout << n << " " << m << " " << Q << '\n';
		REP( i , n ) cin >> S[ i ];
		while( Q -- ){
			cin >> x >> y;
			//x -- , y--;
			cout << query( x , y ) << '\n';
		}
	}
}
