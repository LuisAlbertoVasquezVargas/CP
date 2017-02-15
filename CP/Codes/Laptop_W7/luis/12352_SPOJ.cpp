#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" ,&x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t  , val ) memset( t , val , sizeof( t ) )
#define ones( x ) __builtin_popcount( x )

#define all( v ) v.begin() , v.end()
#define pb push_back

#define N 100005

typedef vector< int > vi;
typedef long long ll;

int P[ N + 1 ];

void init(){
	clr( P , -1 );
	for( int i = 2 ; i*i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i*i ; j <= N ; j += i )
				P[ j ] = i;
}
vi primeFact( int x ){
	vi v;
	if( x == 1 ) return v;
	while( 1 )
	{
		if( P[ x ] == -1 ){
			
			v.pb( x );
			sort( all( v ) );
			v.resize( unique( all( v ) ) - v.begin() );
			return v;
		}
		v.pb( P[ x ] );
		x /= P[ x ];
	}
}
void impr( vi &v ){
	int nv = v.size();
	REP( i , nv ) printf( "%d%s" , v[ i ] , i + 1 == nv ? "\n":" " );
}
int main()
{
	init();
	int Q , n , m ;
	sc( Q );
	while( Q-- )
	{
		sc( n ) , sc( m );
		vi v = primeFact( n );
		int nv = v.size();
		ll ans = 0;
		for( int mask = 1 ; mask < ( 1 << nv ) ; ++mask )
		{
			int P = 1;
			REP( i , nv )if( mask & ( 1 << i ) ) P *= v[ i ];
			if( P > m ) continue;
			//cout << "val : " << m/P << " mask " << mask << endl;
			if( ones( mask )&1 ) ans += m/P;
			else ans -= m/P;
		}
		cout << m - ans << '\n';
	}
}
