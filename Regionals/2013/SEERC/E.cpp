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

struct Matrix{
	ll M[ 2 ][ 2 ];
	Matrix(){
		M[ 0 ][ 0 ] = M[ 0 ][ 1 ] = M[ 1 ][ 0 ] = 1;
		M[ 1 ][ 1 ] = 0;
	}
	Matrix( ll t ){
		M[ 0 ][ 0 ] = M[ 1 ][ 1 ] = 1;
		M[ 0 ][ 1 ] = M[ 1 ][ 0 ] = 0;
	}
	void impr(){
		test();
		REP( i , 2 ){ 
			REP( j , 2 )
				cout << M[ i ][ j ] << " ";
			cout << endl;
		}
	}
};

Matrix operator * ( const Matrix &a , const Matrix &b ){
	Matrix C;
	REP( i , 2 )REP( j , 2 ){
		ll dev = 0;
		REP( k , 2 ) dev = ( dev + a.M[ i ][ k ] * b.M[ k ][ j ] );
		C.M[ i ][ j ] = dev;
	}
	return C;
}
void generate( vector< Matrix > &v , Matrix M ){
	Matrix cur( 1 );
	v.pb( cur );
	REP( k , 20 ){
		cur = cur * M;
		cur.impr();
		v.pb( cur );
	}
}

vector< Matrix > vA , vB;
int main(){
	Matrix A , B;
	REP( i , 2 ) REP( j , 2 ) A.M[ i ][ j ] = B.M[ i ][ j ] = 1;
	A.M[ 0 ][ 1 ] = 0 , B.M[ 1 ][ 0 ] = 0;
	
	generate( vB , B );
	//generate( vB , B );
}



