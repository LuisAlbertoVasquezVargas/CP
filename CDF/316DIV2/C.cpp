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

#define MAXVAL 300005

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int bit[ MAXVAL + 5 ];

void upd( int pos , int val ){
	while( pos <= MAXVAL ){
		bit[ pos ] += val;
		pos += (pos & -pos); 
	}
}
void update( int pos , int val ){
	upd( pos + 1 , val );
}
int qry( int pos ){
	int sum = 0;
	while( pos ){
		sum += bit[ pos ];
		pos -= ( pos & -pos );
	}
	return sum;
}
int query( int pos ){
	return qry( pos + 1 );
}
bool full( int a , int b ){
	return b - a + 1 == query( b ) - query( a - 1 );
}
int getL( int pos ){
	int lo = 0 , hi = pos;
	if( full( lo , pos ) ) return lo;
	while( hi - lo > 1 ){
		int med = (lo + hi) >> 1;
		if( full( med , pos ) ) hi = med;
		else lo = med;
	}
	return hi;
}
int n;
int getR( int pos ){
	int lo = pos , hi = n - 1;
	if( full( pos , hi ) ) return hi;
	while( hi - lo > 1 ){
		int med = (lo + hi) >> 1;
		if( full( pos , med ) ) lo = med;
		else hi = med;
	}
	return lo;
}
char S[ MAXVAL + 5 ] , cad[ 10 ];
int f( int len ){
	if( len <= 1 ) return 0;
	return len - 1;
}
int main(){
	int m;
	while( sc( n ) == 1 ){
		sc( m );
		scanf( "%s" , S );
		clr( bit , 0 );
		int ans = 0;
		REP( i , n ){
			if( S[ i ] != '.' ) continue;
			int ind;
			for( int j = i ; j < n ; ++j )
				if( S[ j ] == '.' ) ind = j , update( j , +1 );
				else break;
			ans += f( ind - i + 1 );
			i = ind;
		}
		REP( it , m ){
			int pos;
			sc( pos );
			pos --;
			scanf( "%s" , cad );
			char c = cad[ 0 ];
			if( c == '.' ){
				if( S[ pos ] == '.' ){
					printf( "%d\n" , ans );
				}else{
					if( pos + 1 < n && S[ pos + 1 ] == '.' ){
						int lo = pos + 1;
						int hi = getR( pos + 1 );
						int len = hi - lo + 1;
						ans -= f( len );
					}
					if( pos - 1 >= 0 && S[ pos - 1 ] == '.' ){
						int lo = getL( pos - 1 );
						int hi = pos - 1;
						int len = hi - lo + 1;
						ans -= f( len );
					}
					S[ pos ] = c;
					update( pos , +1 );
					int lo = getL( pos );
					int hi = getR( pos );
					int len = hi - lo + 1;
					ans += f( len );
					printf( "%d\n" , ans );
				}
			}else{// c == 'a'
				if( S[ pos ] == '.' ){
					S[ pos ] = c;
					int lo = getL( pos );
					int hi = getR( pos );
					int len = hi - lo + 1;
					ans -= f( len );
					ans += f( (pos - 1) - lo + 1 );
					ans += f( hi - (pos + 1) + 1 );
					update( pos , -1 );
					printf( "%d\n" , ans );
				}else{
					printf( "%d\n" , ans );
				}
			}
		}
	}
}


