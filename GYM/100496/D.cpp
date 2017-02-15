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
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;


#define MAXVAL 200000

int bit[ MAXVAL + 5 ];
int last[ MAXVAL + 5 ];
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
int Query( int pos ){ return qry( pos + 1 ); }

int getId( vi &v , int x ){
	return lower_bound( all( v ) , x ) - v.begin();
}
struct query{
	int lo , hi , id , ans;
	query(){}
	query( int lo , int hi , int id , int ans ) : lo( lo ) , hi( hi ) , id( id ) , ans( ans ){}
};
bool operator < ( const query &a , const query &b ){
	if( a.hi != b.hi ) return a.hi < b.hi;
	if( a.lo != b.lo ) return a.lo < b.lo;
	return a.id < b.id;
}

vi solve( vi &A , vector< query > &V ){
	vi ans( SZ( V ) );
	clr( bit , 0 );
	clr( last , -1 );
    int end = 0;
    for( auto q : V ){
    	int lo = q.lo , hi = q.hi , id = q.id;
    	if( lo == -1 ){//query calculada previamente
    		ans[ id ] = q.ans;
    		continue;
    	}
    	for( int j = end ; j <= hi ; ++j ){
               if( last[ A[ j ] ] == -1 ){
                    last[ A[ j ] ] = j;
                    update( j , 1 );
               }else{
					update( last[ A[ j ] ] , -1 );
                    update( j , 1 );                    
                    last[ A[ j ] ] = j;
               }
		}
		ans[ id ] = Query(hi) - Query(lo - 1);//number of diferents
		ans[ id ] ++;
		end = hi;
    }
	return ans;
}
int main(){
	freopen( "data.in" , "r" , stdin );
	freopen( "data.out" , "w" , stdout );
	int n;
	while( sc( n ) == 1 ){
		vi A( n );
		REP( i , n ) sc( A[ i ] );
		vi a = A;
		sort( all( a ) );
		a.resize( unique( all( a ) ) - a.begin() );
		vvi T( SZ( a ) );
		REP( i , n ) T[ getId( a , A[ i ] ) ].pb( i );

		int Q;
		sc( Q );
		vector< query > V;
		REP( i , Q ){
			int pos , K;
			sc( pos ) , sc( K );
			pos --;
			
			int ida = getId( a , A[ pos + K - 1 ] );
			int p = lower_bound( all( T[ ida ] ) , pos ) - T[ ida ].begin();
			K = T[ ida ][ p ];
			// [pos K - 1][k]
			if( pos == K ){
				V.pb( query( -1 , -1 , i , 1 ) );
				continue;
			}
			V.pb( query( pos , K - 1 , i , -1 ) );
		}
		REP( i , n ) A[ i ] = getId( a , A[ i ] );
		sort( all( V ) );
		vi ans = solve( A , V );
		for( auto x : ans ) printf( "%d\n" , x );
	}
}


