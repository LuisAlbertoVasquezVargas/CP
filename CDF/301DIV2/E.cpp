#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define SZ( v ) ((int)(v).size())
#define all( v ) v.begin() , v.end()

#define mp make_pair
#define fi first
#define se second

#define N 1000000

typedef long long ll;
typedef vector< int > vi;

struct FT{
	ll bit[ N + 5 ];
	FT(){}
	void clear(){
		clr( bit , 0 );
	}
	ll qry( int pos ){
		ll s = 0;
		while( pos ){
			s += bit[ pos ];
			pos -= pos & -pos;
		}
		return s;
	}
	ll query( int pos ){ return qry( pos + 1 );}
	void upd( int pos , int val ){
		while( pos <= N ){
			bit[ pos ] += val;
			pos += pos & -pos;
		}
	}
	void update( int pos , int val ){
		upd( pos + 1 , val );
	}
}tree;

void UNIQUE( vi &v ){
	sort( all( v ) );
	v.resize( unique( all( v ) ) - v.begin() );
}
int getPos( vi &v , int x ){
	return lower_bound( all( v ) , x ) - v.begin();
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		vi x( n ) , y( n );
		REP( i , n ) sc( x[ i ] ) , sc( y[ i ] );
		
		vi A , B , val;
		REP( i , n ){
			A.pb( x[ i ] );
			A.pb( y[ i ] );
		}
		UNIQUE( A );
		REP( i , SZ( A ) ){
			if( i == SZ( A ) - 1 ){
				B.pb( A[ i ] );
				val.pb( 1 );
			}else{
				if( A[ i ] == A[ i + 1 ] - 1 ){
					B.pb( A[ i ] );
					val.pb( 1 );
				}else{
					B.pb( A[ i ] );
					val.pb( 1 );
					B.pb( A[ i ] + 1 );
					val.pb( A[ i + 1 ] - A[ i ] - 1 );
				}
			}
		}
		tree.clear();
		
		A = B;
		
		REP( i , n ){
			int a = getPos( A , x[ i ] );
			int b = getPos( A , y[ i ] );
			swap( B[ a ] , B[ b ] );
		}
		//REP( i , SZ(B) ) cout << B[ i ] << " " << val[ i ] << endl;
		ll ans = 0;
		for( int i = SZ(B) - 1 ; i >= 0 ; --i ){
			ans += (ll)val[ i ] * tree.query( getPos( A , B[ i ] ) - 1 );
			tree.update( getPos( A , B[ i ] ) , val[ i ] );
		}
		cout << ans << '\n';
	}
}



