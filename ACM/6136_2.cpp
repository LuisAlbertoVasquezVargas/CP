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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef pair< pii , pii > ppii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;

vi dx = { 0 , 0 , 1 , -1 };
vi dy = { 1 , -1 , 0 , 0 };

int main(){
	ios_base :: sync_with_stdio( 0 );
	int n;
	while( cin >> n ){
		vs S( 2 * n - 1 );//2n-1,n
		REP( i , 2 * n - 1 ) cin >> S[ i ];
		
		vvi vis( 2 * n , vi( 2 * n + 1 ) );
		
		vector< ppii > SET;
		for( int i = 1 ; i <= 2 * n - 1 ; ++i ){
			for( int j = 1 ; j <= n ; ++j ){
				int x = i , y = 2 * j - ((i&1));
				//DEBUG2( x , y );
				pii a = mp( x - 1 , y - 1 );
				pii b = mp( x - 1 , y     );
				pii c = mp( x     , y - 1 );
				pii d = mp( x     , y     );
				if( S[ i - 1 ][ j - 1 ] == 'V' ){
					if( a >= b ) swap( a , b );
					if( c >= d ) swap( c , d );
					SET.pb( mp( a , b ) );
					SET.pb( mp( c , d ) );
					//Union( a , c );
					//Union( b , d );
				}else{
					if( a >= c ) swap( a , c );
					if( b >= d ) swap( b , d );
					SET.pb( mp( a , c ) );
					SET.pb( mp( b , d ) );
					//Union( a , b );
					//Union( c , d );
				}
			}

		}
		sort( all( SET ) );
		int ans = 0;
		REP( i , 2 * n ) REP( j , 2 * n + 1 ){//(2*n)x(2*n+1)
			if( !vis[ i ][ j ] ){
				ans ++;
				queue< pii > Q;
				Q.push( mp( i , j ) );
				vis[ i ][ j ] = 1;
				while( !Q.empty() ){
					pii U = Q.front(); Q.pop();
					int x = U.fi , y = U.se;
					REP( k , 4 ){
						int nx = x + dx[ k ];
						int ny = y + dy[ k ];
						if( nx >= 0 && ny >= 0 && nx < 2 * n && ny < 2 * n + 1 && !vis[ nx ][ ny ] ){
							pii V( nx , ny );
							auto cur = mp( U , V );
							if( cur.fi >= cur.se ) swap( cur.fi , cur.se );
							if( !binary_search( all( SET ) , cur ) ){
								Q.push( V );
								vis[ nx ][ ny ] = 1;
							}
						}
					}
				}
			}
		}
		cout << --ans << '\n';
	}
}




