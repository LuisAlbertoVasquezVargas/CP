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
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << " " << z << endl;

#define N 200000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

//map< ll , bool > mapa;
bool isSQ[ N + 1 ];
int S , K;
vi vec , ans;
bool solved;
void dfs( int last , int cnt , int sum ){
	//DEBUG3( last , cnt , sum );
	if( solved ) return;
	if( (last * cnt > sum) || (cnt == 0) || (sum == 0) ) {
		if( cnt == 0 && sum == 0 ){
			ans = vec;
			solved = 1;
		}
		return;
	}	
	dfs( last + 1 , cnt , sum );
	if( solved ) return;
	if( cnt - 1 >= 0 && sum - last >= 0 && S - last >= 0 && isSQ[ S - last ] ){
		vec.pb( last );
		dfs( last + 1 , cnt - 1 , sum - last );
		vec.pop_back();
	}
}


int main(){
	freopen( "squary.in" , "r" , stdin );
	freopen( "squary.out" , "w" , stdout );
	
	for( int i = 0 ; i * i <= N ; ++i )
		isSQ[ i * i ] = 1;
	
	while( cin >> S >> K ){
		vec.clear();
		solved = 0;
		dfs( 1 , K , S );
		puts( solved ? "YES" : "NO" );
		if( !solved ) continue;
		REP( i , SZ( ans ) ) printf( "%d%c" , ans[ i ] , (i + 1 == SZ(ans)) ? 10 : 32 );
	}
	
}



