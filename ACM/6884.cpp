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

typedef long long ll;
typedef vector< int > vi;
typedef vector< string > vs;

vs S;
string CAD;
vi values;
vi used;
vi mapa;
vi factor;
vi forb;
int toi( string &s ){
	int ans = 0;
	REP( i , SZ( s ) ) ans = ans * 10 + s[ i ] - '0';
	return ans;
}
bool eval(){
	int n = SZ( S );
	int a = 0 , b = 0;
	REP( i , n ){
		string cad = S[ i ];
		REP( k , SZ( S[ i ] ) )
			cad[ k ] = mapa[ cad[ k ] ];
		if( cad[ 0 ] == '0' ) return 0;
		if( i == n - 1 ) b = toi( cad );
		else a += toi( cad );
	}
	return a == b;
}

int ans = 0;
void dfs( int pos , ll cur ){
	//DEBUG( pos );
	if( pos == SZ( CAD ) ){
		if( cur == 0 ) ans ++;
		return;
	}
	for( int i = 0 ; i <= 9 ; ++i ){
		if( i == 0 && forb[ CAD[ pos ] ] ) continue;
		if( !used[ i ] ){
			used[ i ] = 1;
			values[ pos ] = i;
			mapa[ CAD[ pos ] ] = '0' + i;
			dfs( pos + 1 , cur + i * factor[ CAD[ pos ] ] );
			used[ i ] = 0;
			values[ pos ] = -1;
			mapa[ CAD[ pos ] ] = -1;
		}
	}
}	
ll POT[ 15 + 1 ];
int main(){
	ios_base :: sync_with_stdio( 0 );
	POT[ 0 ] = 1;
	for( int i = 1 ; i <= 15 ; ++i ) POT[ i ] = POT[ i - 1 ] * 10LL;
	int n;
	while( cin >> n ){
		S = vs( n );
		mapa = vi( 256 , -1 );
		factor = vi( 256 , 0 );
		forb = vi( 256 , 0 );
		REP( i , n ) cin >> S[ i ];
		REP( i , n ){
			forb[ S[ i ][ 0 ] ] = 1;
			REP( j , SZ( S[ i ] ) ){
				if( i != n - 1 ) factor[ S[ i ][ j ] ] += POT[ SZ( S[ i ] ) - 1 - j ];
				else factor[ S[ i ][ j ] ] -= POT[ SZ( S[ i ] ) - 1 - j ];
			}
		}	
		string cad;
		REP( i , n ) cad += S[ i ];
		
		sort( all( cad ) );
		cad.resize( unique( all( cad ) ) - cad.begin() );
		CAD = cad;
		values = vi( SZ( cad ) , -1 );
		used = vi( 10 );
		if( SZ( cad ) > 10 ){
			cout << 0 << '\n';
			continue;
		}
		ans = 0;
		dfs( 0 , 0 );
		printf( "%d\n" , ans );
	}	
}




