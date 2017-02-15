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

#define N 10000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

vi T[ N + 5 ];
int v[ N + 5 ];
int main(){
	//ios_base :: sync_with_stdio( 0 );
	ifstream myFile( "C.IN" , ios::in|ios::binary|ios::ate );
	int n , m;
	string line;
	getline( myFile , line );
	istringstream in1( line );
	in1 >> n >> m;
	DEBUG2( n , m );
	REP( i , n ){
		getline( myFile , line );
		istringstream in( line );
		REP( j , m ) cin >> v[ j ];
		T[ i ] = vi(v , v + m);
	}
	getline( cin , line );
	int x , y;
	while( getline( cin , line ) ){
		istringstream in( line );
		cin >> x >> y;
		int ans = 0;
		REP( i , n ) ans += upper_bound( all( T[ i ] ) , y ) - lower_bound( all( T[ i ] ) , x );
		cout << ans << '\n';
	}
}





