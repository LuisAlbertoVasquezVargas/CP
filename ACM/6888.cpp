#include <bits/stdc++.h>
using namespace std;
 
#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < (n) ; i++ )
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

#define N 10

typedef long long ll;
typedef vector< int > vi;
typedef pair< int , int > pii;
typedef vector< pii > vpii;

string mat[ N + 1 ];
int dx[] = { 0 , 0 , 1 , -1 };
int dy[] = { 1 , -1 , 0 , 0 };
int R , C;
bool valid( int x , int y ){
	return x >= 0 && x < R && y >= 0 && y < C;
}
vpii move( vpii &v , int pos , int dir ){
	REP( k , SZ( v ) ){
		pii x = v[ k ];
		if( k == pos ) continue;
		mat[ x.fi ][ x.se ] = 'W';
	}
	int a = v[ pos ].fi , b = v[ pos ].se;
	int ra , rb;
	REP( k , 1000 ){
		int na = a + k * dx[ dir ] , nb = b + k * dy[ dir ];
		if( valid( na , nb ) && mat[ na ][ nb ] != 'W' )
			ra = na , rb = nb;
		else break;
	}
	for( auto x : v ) mat[ x.fi ][ x.se ] = '.';
	
	vpii w = v;
	w[ pos ] = mp( ra , rb );
	return w;
}
int Hash( vpii v ){
	int ans = 0;
	REP( i , SZ( v ) ){
		ans = ans * 10 + v[ i ].fi;
		ans = ans * 10 + v[ i ].se;
	}
	return ans;
}
void impr( vpii &v ){
	for( auto x : v ) cout << "(" << x.fi << "," << x.se << ") "; cout << endl;
}
int main(){
	int n , L;	
	while( cin >> n >> C >> R >> L ){
		REP( i , R ) cin >> mat[ i ];
		vpii v( n );
		pii target;
		REP( i , R ) REP( j , C ){
			if( '1' <= mat[ i ][ j ] && mat[ i ][ j ] <= '9' )
				v[ mat[ i ][ j ] - '1' ] = mp( i , j );
			if( mat[ i ][ j ] == 'X' ) target = mp( i , j );
			if( mat[ i ][ j ] != 'W' ) mat[ i ][ j ] = '.';
		}
		vpii s = v;
		map< int , int > dist;
		queue< vpii > Q;
		dist[ Hash( s ) ] = 0;
		Q.push( s );
		int ans = INT_MAX;
		while( !Q.empty() ){
			auto u = Q.front() ; Q.pop();
			if( u[ 0 ] == target ){
				ans = min( ans , dist[ Hash( u ) ] );
				break;
			}
			if( dist[ Hash( u ) ] == L ) continue;
			REP( i , n ) REP( k , 4 ){
				auto v = move( u , i , k );
				if( !dist.count( Hash( v ) ) ){
					Q.push( v );
					dist[ Hash( v ) ] = dist[ Hash( u ) ] + 1;
				}
			}
		}
		if( ans >= INT_MAX ){
			puts( "NO SOLUTION" );
			continue;
		}
		printf( "%d\n" , ans );
	}
}





