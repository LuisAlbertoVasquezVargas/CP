#include <bits/stdc++.h>
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

#define test() cerr << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 1000000

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< int > vi;


int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int n , P;
		string s;
		cin >> n >> s >> P;
		if( s[ 0 ] == 'o' ){
			cout << 2 * P << '\n';
		}else{
			cout << 2 * P - 1 << '\n';
		}
	}
}


