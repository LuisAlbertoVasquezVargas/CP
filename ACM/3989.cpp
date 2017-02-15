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

#define N 1000
int n;
int pref_men[ N ][ N ] , pref_women[ N ][ N ] , inv[ N ][ N ] , cont[ N ] , husband[ N ] , wife[ N ];
void stable_marriage(){
	REP( i , n )REP( j , n ) inv[ i ][ pref_women[ i ][ j ] ] = j;
	clr( cont , 0 );
	clr( husband , -1 );
	int m , w , dumped;
	REP( i , n )
	{
		m = i;
		while( m >= 0 ){
			while( 1 )
			{
				w = pref_men[ m ][ cont[ m ] ];
				++cont[ m ];
				if( husband[ w ] < 0 || inv[ w ][ m ] < inv[ w ][ husband[ w ] ] ) break;
			}
			dumped = husband[ w ];
			husband[ w ] = m;
			wife[ m ]=  w;
			m = dumped;
		}
	}
}

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		sc( n );
		REP( i , n ) REP( j , n ) sc( pref_men[ i ][ j ] ) , pref_men[ i ][ j ] --;
		REP( i , n ) REP( j , n ) sc( pref_women[ i ][ j ] ) , pref_women[ i ][ j ] --;
		stable_marriage();
		if( tc ) puts( "" );
		REP( i , n ) printf( "%d\n" , wife[ i ] + 1 );
	}
}


