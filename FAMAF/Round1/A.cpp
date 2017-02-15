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

#define N 1000
#define M 1000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int ISSQ[ M + 5 ];
int main(){
	ios_base :: sync_with_stdio(0);
	REP( i , N + 1 ) 
		if( i ) ISSQ[ i * i ] = i;
	string s;
	int n , m;
	while( cin >> n >> m ){
		int fichas = 0;
		REP( i , n ){
			cin >> s;
			fichas += count( all( s ) , 'o' );
		}
		cout << (ISSQ[ fichas ] && ISSQ[ fichas ] <= min( n , m ) )<< '\n';
	}	
}



