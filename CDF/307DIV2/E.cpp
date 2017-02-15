#include<bits/stdc++.h>
using namespace std;
 
#define sc(x) scanf( "%d" , &x )
#define REP(i , n) for( int i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )
 
#define pb push_back
#define all(v) v.begin() , v.end()
#define SZ(v) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second

#define DEBUG( x ) cerr << #x << " " << x << endl;

typedef long long ll;
typedef pair< ll , ll > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef vector< vvi > vvvi;

int getLower( vi &v , int x ){
	return lower_bound( all( v ) , x ) - v.begin();
}
int getUpper( vi &v , int x ){
	return upper_bound( all( v ) , x ) - v.begin();
}

int getLower( vll &v , ll x ){
	return lower_bound( all( v ) , x ) - v.begin();
}
int getUpper( vll &v , ll x ){
	return upper_bound( all( v ) , x ) - v.begin();
}

int getLower( vpii &v , ll x ){
	pii par = mp( x , INT_MIN );
	return lower_bound( all( v ) , par ) - v.begin();
}

int getUpper( vpii &v , ll x ){
	pii par = mp( x , INT_MAX );
	return upper_bound( all( v ) , par  ) - v.begin();
}


void fix( int buck , vvll &buckets , vll &flag , vvpii &bucketsSorted , 
	int lo , int hi , int x , vvi &index ){
	
	for( auto &val : buckets[ buck ] ) val += flag[ buck ];
	flag[ buck ] = 0;

	for( int pos = lo ; pos <= hi ; ++pos )
		buckets[ buck ][ pos ] += x;
	vpii vec;
	REP( i , SZ( buckets[ buck ] ) )
		vec.pb( mp( buckets[ buck ][ i ] , index[ buck ][ i ] ) );
	sort( all( vec ) );
	bucketsSorted[ buck ] = vec;
}

int main(){
	int n , Q;
	while( sc( n ) == 1 ){
		sc( Q );
		vi A( n );
		int m = (int) sqrt( n );
		int len = (n - 1)/m + 1;
		vvll buckets( len );
		vvi index( len );
		vll flag( len );
		vi ind( n );
		vi lo( len , INT_MAX ) , hi( len , INT_MIN );
		REP( i , n ) sc( A[ i ] );

		vvpii bucketsSorted( len );		
		
		REP( i , n ){
			int bucket = i / m;
			buckets[ bucket ].pb( A[ i ] );
			lo[ bucket ] = min( lo[ bucket ] , i );
			hi[ bucket ] = max( hi[ bucket ] , i );
			index[ bucket ].pb( i );
			ind[ i ] = bucket;
		}
		
		REP( buck , len ) fix( buck , buckets , flag , bucketsSorted , 0 , 0 , 0 , index );
	
		REP( q , Q ){
			int op;
			sc( op );
			if( op == 1 ){
				int L , R , x;
				scanf( "%d%d%d" , &L , &R , &x );
				L -- , R -- ;
				int inda = getLower( lo , L );
				int indb = getUpper( hi , R );
				indb --;
				if( ind[ L ] == ind[ R ] ){
					int buck = ind[ L ];
					int a = getLower( index[ buck ] , L );
					int b = getLower( index[ buck ] , R );
					fix( buck , buckets , flag , bucketsSorted , a , b , x , index );
					continue;
				}else{
					if( inda <= indb ){
						for( int buck = inda ; ; buck ++ ){
							flag[ buck ] += x;
							if( buck == indb ) break;
						}
					}
					if( lo[ inda ] != L ){
						int buck = inda - 1;
						int a = getLower( index[ buck ] , L );
						int b = SZ( buckets[ buck ] ) - 1;
						fix( buck , buckets , flag , bucketsSorted , a , b , x , index );
					}
					if( hi[ indb ] != R ){
						int buck = indb + 1;
						int a = 0;
						int b = getLower( index[ buck ] , R );
						fix( buck , buckets , flag , bucketsSorted , a , b , x , index );
					}
					
				}
			}else{
				int y;
				sc( y );
				int a = INT_MAX , b = INT_MIN;
				REP( buck , len ){
					ll cur = (ll)y - flag[ buck ];
					int posa = getLower( bucketsSorted[ buck ] , cur );
					int posb = getUpper( bucketsSorted[ buck ] , cur );
					if( posa == posb ) continue;
					posb --;
					a = min( a , (int)bucketsSorted[ buck ][ posa ].se );
					b = max( b , (int)bucketsSorted[ buck ][ posb ].se );
				}
				if( a == INT_MAX ){
					puts( "-1" );
					continue;
				}
				printf( "%d\n" , b - a );
			}
			
		}
	}
}





