#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF (1<<20)
#define N 200000

#define DEBUG( x ) cout << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;

int main(){
	ios_base :: sync_with_stdio( 0 );
	int n;
	while( cin >> n ){
		vi STACK;
		REP( i , 2 * n ){
			string s;
			int x;
			cin >> s >> x;
			if( s[ 0 ] == 'i' ){
				if( !STACK.empty() )
					cout << STACK.back() << " " << x << '\n';
				STACK.pb( x );
			}else{
				STACK.pop_back();
			}
		}
	}
}

