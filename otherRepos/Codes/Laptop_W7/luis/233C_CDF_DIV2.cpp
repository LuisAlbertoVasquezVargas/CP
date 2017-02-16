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
#define INF (1LL<<60)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

ll SQ( ll x ){ return x * x;}
int main()
{
	sync
	int a ,b;
	while( cin >> a >> b ){
		if( a == 0 ){
			cout << -SQ( b ) << endl;
			cout << string( b , 'x' ) << '\n';
			continue;
		}
		ll maxi = -INF;
		int ind;
		for( int i = 1 ; i <= a ; ++i ){
			// puedo grupos( b ) de tamaño i - 1 , i + 1.
			if( b < i - 1 ) continue;
			ll bestA = i - 1 + SQ( a - ( i - 1 ) );
			ll q = b/( i + 1 ) , r = b % ( i + 1 );
			ll bestB = r * SQ( q + 1 ) + ( i + 1 - r ) * SQ( q );
			if( bestA - bestB > maxi ){
				ind = i;
				maxi = bestA - bestB;
			}
		}
		cout << maxi << '\n';
		int I = ind;
		if( b == I - 1 ){
			cout << string( a - ( I - 1 ) , 'o' );
			REP( k , I - 1 ) cout << "xo";
			cout << '\n';
		}
		else if( b == I ){
			cout << string( a - ( I - 1 ) , 'o' );
			cout << "x";
			REP( k , I - 1 ) cout << "ox";
			cout << '\n';
		}
		else
		{
			ll q = b/( I + 1 ) , r = b % ( I + 1 );
			// x o
			REP( k , I + 1 ){
				if( k == I ){
					if( k < r ) cout << string( q + 1 , 'x' );
					else cout << string( q , 'x' );
				}
				else{
					if( k < r ) cout << string( q + 1 , 'x' );
					else cout << string( q , 'x' );
					if( k == 0 ) cout << string( a - ( I - 1 ) , 'o' );
					else cout << "o";
				}
			}
			cout << '\n';
		}

	}
}



