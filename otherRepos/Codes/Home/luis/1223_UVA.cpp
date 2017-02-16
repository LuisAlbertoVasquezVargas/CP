#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , %x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

#define B 27LL
#define MOD1 1000000007LL
#define MOD2 1000000009LL
#define N 5000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;

int n , gap;
string s;
int pos[ N + 5 ] , sa[ N + 5 ] , temp[ N + 5 ] , lcp[ N + 5 ];
bool sufCmp( int i , int j ){
	if( pos[ i ] != pos[ j ] ) return pos[ i ] < pos[ j ];
	i += gap , j += gap;
	return (i < n && j < n) ? pos[ i ] < pos[ j ] : i > j;
}
void buildSA(){
	n = s.size();
	REP( i , n ) sa[ i ] = i , pos[ i ] = s[ i ];
	for( gap = 1 ; ; gap <<= 1 ){
		sort( sa , sa + n , sufCmp );
		REP( i , n - 1 ) temp[ i + 1 ] = temp[ i ] + sufCmp( sa[ i ] , sa[ i + 1 ] );
		REP( i , n ) pos[ sa[ i ] ] = temp[ i ];
		if( temp[ n - 1 ] == n - 1 ) break;
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

int main(){
	ios_base :: sync_with_stdio( 0 );

	int cases;
	cin >> cases;
	getline( cin , s );
	REP( tc , cases ){
		getline( cin , s );
		buildSA();
		buildLCP();
		int maxi = 0;
		REP( i , n - 1 ) maxi = max( maxi , lcp[ i ] );
		cout << maxi << '\n';
	}
}
