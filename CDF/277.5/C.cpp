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

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

string getMin( int m , int S ){
	string cad(m , '0');
	cad[ 0 ] ++;
	S --;
	for( int i = SZ(cad) - 1 ; i >= 0 ; --i ){
		int cur = min( '9' - cad[ i ] , S );
		S -= cur;
		cad[ i ] += cur;
	}
	return cad;
}
string getMax( int m , int S ){
	string cad(m ,'0');
	REP( i , m ){
		int cur = min( '9' - cad[ i ] , S );
		S -= cur;
		cad[ i ] += cur;
	}
	return cad;
}
int main(){
	int m , S;
	while( cin >> m >> S ){
		int lo = (m == 1 ? 0 : 1), hi = 9 * m;
		if( lo <= S && S <= hi ){
			cout << getMin( m , S ) << " " << getMax( m , S ) << '\n';
		}else{
			cout << "-1 -1\n";
		}
	}
}


