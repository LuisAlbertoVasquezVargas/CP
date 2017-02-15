#include<bits/stdc++.h>
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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll solve( int n , ll c , vi P , vi T ){
	ll ans = 0 , x = 0 ;
	REP( i , n ){
		x += T[ i ];
		ans += max( 0LL , (ll)P[ i ]  - c * x );
	}
	return ans;
}
int main(){
	int n;
	ll c;
	while( cin >> n >> c ){
		vi P( n );
		REP( i , n ) cin >> P[ i ];
		vi T( n );
		REP( i , n ) cin >> T[ i ];
		ll a = solve( n , c , P , T );
		reverse( all( P ) );
		reverse( all( T ) );
		ll b = solve( n , c , P , T );
		
		if( a == b ){
			cout << "Tie\n";
			continue;
		}
		if( a < b ){
			cout << "Radewoosh\n";
			continue;
		}
		cout << "Limak\n";
	}
}



