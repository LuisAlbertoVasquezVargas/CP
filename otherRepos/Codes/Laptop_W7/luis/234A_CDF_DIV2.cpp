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

void impr( vector< pii > v ){
	int nv = v.size();
	cout << nv;
	REP( i , nv ) cout << " " << v[ i ].fi << "x" << v[ i ].se ;
	cout << endl;
}
string s;
void doit(){
	vector< pii > sol;
	for( int a = 1 ; a <= 12 ; ++a ){
		if( 12 % a ) continue;
		int b = 12 / a;
		vector< string > v( b );
		REP( i , 12 ) v[ i % b ] .pb( s[ i ] );
		/*REP( i , b ) cout << v[ i ] << endl;
		cout << endl;
		*/
		bool solve = 0;
		REP( i , b ) if( v[ i ] == string( a , 'X' ) ) solve = 1;
		if( solve ){
			sol.pb( mp( a , b ) );
		}
	}
	impr( sol );
}
int main()
{
	int cases;
	while( cin >> cases ){
		REP( tc , cases ) cin >> s , doit();
	}
}



