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

#define N 1000000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int id[ N + 5 ];
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ) );}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( pu != pv ) id[ pu ] = pv;
}
char op[ 10 ];
int main(){
	int n;
	sc( n );
	REP( i , n ) id[ i ] = i;
	while( 1 ){
		scanf( "%s" , op );
		if( op[ 0 ] == '-' ) break;
		if( op[ 0 ] == 'C' ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			Union( u , v );
		}else{
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			puts( Find( u ) == Find( v ) ? "Yes" : "No" );
		}
	}
}




