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

int main(){
	ios_base :: sync_with_stdio( 0 );
	string s;
	while( cin >> s ){
		if( s == "*" ) break;
		s.insert( s.begin() , 'a' );
		s.pb( 'a' );
		multiset< int > SET;
		for( int i = 1 ; i < SZ(s) ; ++i ){
			int cur = s[ i ] - s[ i - 1 ];
			if( cur < 0 ) cur += 26;
			//DEBUG( cur );
			if( cur > 0 && cur < 26 ) SET.insert( cur );
		}
		//test();
		int ans = 0;
		while( !SET.empty() ){
			if( SZ( SET ) >= 2 ){
				multiset< int > :: iterator a = SET.begin() ;
				int A = *a ;
				SET.erase( a );
				
				multiset< int > :: iterator b = --SET.end();
				int B = *b;
				SET.erase( b );
				
				B ++;
				if( B != 26 ) SET.insert( B );
				A --;
				if( A != 0 ) SET.insert( A );
				//DEBUG2( A , B );
				ans ++;
			}else{
				assert( 0 );
				int val = *SET.begin();
				ans += min( val , 26 - val );
				break;
			}
		}
		printf( "%d\n" , ans );
	}
}


