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

#define MAXNODES 1000
#define ALP 2
#define EPS (1e-40)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef double ld;
typedef vector< ld > vld;
typedef vector< vld > vvld;

int nAlp = 2;
struct AHO{
	int NEXT[ MAXNODES + 5 ][ ALP + 1 ],  term[ MAXNODES + 5 ] , T[ MAXNODES + 5 ];
	AHO(){}
	int nodes;
	void init(){
	    nodes = 1;
	    clr( NEXT , 0 );
	    clr( term , 0 );
	}
	void add( string &s , vi &P ){
	    int ns = s.size() , p = 0;
	    P.pb( p );
	    REP( i , ns ){
	        int c = s[ i ] - '0';
	        if( NEXT[ p ][ c ] ) p = NEXT[ p ][ c ];
	        else p = NEXT[ p ][ c ] = nodes ++;
	        P.pb( p );
	    }
	    term[ p ] = 1;
	}
	void aho(){
	    queue< int > Q;
	    REP( c , nAlp ){
	        int u = NEXT[ 0 ][ c ];
	        if( u ) T[ u ] = 0 , Q.push( u );
	    }
	    while( !Q.empty() ){
	        int u = Q.front() ; Q.pop();
	        REP( c , nAlp ){
	            int v = NEXT[ u ][ c ] , x = NEXT[ T[ u ] ][ c ];
	            if( v == 0 ) NEXT[ u ][ c ] = x;
	            else Q.push( v ) , T[ v ] = x , term[ v ] |= term[ T[ v ] ];
	        }
	    }
	}
}ST[ 3 ];
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

int getId( int a , int b , int n ){
	return a * n + b;
}
string S[ 2 ];
int main(){
	while( cin >> S[ 0 ] ){
		
		REP( i , 2 ){
			if( !i ) continue;
			cin >> S[ i ];
		}
		if( S[ 0 ] == "0" && S[ 1 ] == "0" ) break;
		REP( i , 3 ) ST[ i ].init();
		vvi p( 3 );
		REP( i , 2 ) ST[ i ].add( S[ i ] , p[ i ] );
		REP( i , 2 ) ST[ 2 ].add( S[ i ] , p[ 2 ] );
		int n = SZ( S[ 0 ] ) , m = (n + 1) * (n + 1);
		REP( i , 3 ) ST[ i ].aho();
		vvld A( m , vld( m ) ) , B( A );
		vi vis( m );
		int cur = 0;
		//DEBUG( n );		
		
		for( int i = 0 ; i <= n ; ++i )
			for( int j = 0 ; j <= n ; ++j ){
				int pa = p[ 0 ][ i ] , pb = p[ 1 ][ j ];
				int u = getId( pa , pb , n + 1 );
				
				if( i == n && j == n ){
					A[ cur ][ u ] = 1;
					B[ cur ][ 0 ] = 0;
					vis[ u ] = 1;
					cur ++;
					continue;
				}
				if( i == n ){
					A[ cur ][ u ] = 1;
					B[ cur ][ 0 ] = 1;
					vis[ u ] = 1;
					cur ++;
					continue;
				}
				if( j == n ){
					A[ cur ][ u ] = 1;
					B[ cur ][ 0 ] = 0;
					vis[ u ] = 1;
					cur ++;
					continue;
				}
				
				//DEBUG2( pa , pb );
				A[ cur ][ u ] = 1;
				vis[ u ] = 1;
				REP( k , 2 ){
					int qa = ST[ 0 ].NEXT[ pa ][ k ];
					int qb = ST[ 1 ].NEXT[ pb ][ k ];
					int v = getId( qa , qb , n + 1 );
					A[ cur ][ v ] -= 0.5;
					//DEBUG2( qa , qb );
				}
				B[ cur ][ 0 ] = 0;
				cur ++;
			}
			
		bool ok = invert( A , B , m );
		//DEBUG( ok );
		
		printf( "%.3f\n" , (double)B[ 0 ][ 0 ] );
	}
}



