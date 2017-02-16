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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

int f( string s ){
	int h = (s[ 0 ] - '0')*10 + s[ 1 ] - '0';
	int m = (s[ 3 ] - '0')*10 + s[ 4 ] - '0';
	return 60*h + m;
}
string F( int x ){
	int h = x/60 , m = x %60;
	return string( 1 , '0' + h/10 ) + string( 1 , '0' + h%10 ) + ":" + string( 1 , '0' + m/10 ) + string( 1 , '0' + m%10 ); 
}
int main()
{
	int S , T;
	string s , t;
	while( cin >> s >> t ){
		S = f( s ) , T = f( t );
		if( S >= T ) cout << F( S - T ) << endl;
		else cout << F( S + ( 24*60 - T ) ) << endl;
	}
}



