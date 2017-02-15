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
	FILE * pFile = stdin;//fopen ( "C.IN" , "rb" );
	int n , m;
	fread( &n , sizeof(int) , 1 , pFile );
	fread( &m , sizeof(int) , 1 , pFile );
	//DEBUG2( n , m );
	REP( i , n ){
		fread( v , sizeof(int) , m , pFile );
		T[ i ] = vi(v , v + m);
	}
	int x , y;
	while( fread(&x,sizeof(int),1,pFile) == 1 ){
		fread(&y,sizeof(int),1,pFile);
		int ans = 0;
		REP( i , n ) ans += upper_bound( all( T[ i ] ) , y ) - lower_bound( all( T[ i ] ) , x );
		printf( "%d\n" , ans );
	}
}
