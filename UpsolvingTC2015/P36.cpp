#include<bits/stdc++.h>
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
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;

#define MAXNODES 1000
#define ALP 2
#define EPS (1e-40)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;
typedef long double ld;
typedef vector< ld > vld;
typedef vector< vld > vvld;

bool invert( vector< vector< ld > > &A , vector< vector< ld > > &B , int n ){
    REP( i , n ){
        int jmax = i ;
        for( int j = i + 1 ; j < n ; ++j )
            if( abs( A[ j ][ i ] ) > abs( A[ jmax ][ i ] ) ) jmax = j;
        REP( j , n )
            swap( A[ i ][ j ] , A[ jmax ][ j ] ) , swap( B[ i ][ j ] , B[ jmax ][ j ] );
        if( abs( A[ i ][ i ] ) < EPS ) {
            return 0;
        }
        ld tmp = A[ i ][ i ];
        REP( j , n ) A[ i ][ j ] /= tmp , B[ i ][ j ] /= tmp;
        REP( j , n )
        {
            if( i == j )continue;
            tmp = A[ j ][ i ];
            REP( k , n )
                A[ j ][ k ] -= A[ i ][ k ] * tmp , B[ j ][ k ] -= B[ i ][ k ] * tmp;
        }
    }
    return 1;
}
string get( string a , string b ){// a = suf , b = pref
	string ans;
	REP( i , SZ( a ) + 1 ){
		string c = a.substr( SZ(a) - i );
		if( c == b.substr( 0 , i ) ) ans = c;
	}
	return ans;
}
string S[ 2 ];
int main(){
	
	while( cin >> S[ 0 ] ){
		
		REP( i , 2 ){
			if( !i ) continue;
			cin >> S[ i ];
		}
		if( S[ 0 ] == "0" && S[ 1 ] == "0" ) break;
		map< string , int > mapa;
		int n = SZ( S[ 0 ] ) , id = 0;
		vs pack;
		REP( k , 2 ){
			REP( L , n + 1 ){
				string cad = S[ k ].substr( 0 , L );
				if( !mapa.count( cad ) ){
					mapa[ cad ] = id ++;
					pack.pb( cad );
				}
			}
		}
		int m = SZ( mapa );
		vvld A( m , vld( m ) ) , B( A );

		vi vis( m );
		int cur = 0;
		//DEBUG( m );
		
		for( auto s : pack ){
			int u = mapa[ s ];
			A[ cur ][ u ] = 1;
			//DEBUG2( u , s );
			
			if( s == S[ 0 ] ){
				B[ cur ][ 0 ] = 1;
				cur ++;
				continue;
			}
			if( s == S[ 1 ] ){
				B[ cur ][ 0 ] = 0;
				cur ++;
				continue;
			}
			REP( k , 2 ){
				string t = s + string( 1 , '0' + k );
				string a = get( t , S[ 0 ] );
				string b = get( t , S[ 1 ] );
				
				//DEBUG3( k , a , b );
				if( SZ( a ) > SZ( b ) ) swap( a , b );
				
				if( !mapa.count( b ) ) continue;
				
				int v = mapa[ b ];
				//DEBUG3( k , v , b );
				A[ cur ][ v ] -= 0.5;
			}
			B[ cur ][ 0 ] = 0;
			cur ++;
		}
		bool ok = invert( A , B , m );
		assert( ok );
		//DEBUG( ok );
		printf( "%.3f\n" , (double)B[ 0 ][ 0 ] );
	}
}



