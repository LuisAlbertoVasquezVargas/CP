#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define pb push_back

#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;

void impr( vi ans ){
	printf( "%d\n" , SZ(ans) );
	assert( SZ(ans) <= 100 );
	REP( i , SZ(ans) ) printf( "%d%c" , ans[ i ] , (i + 1 == SZ(ans) ? 10 : 32) );
}
vi P = { 1,2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
void doit( int K ){
	cout << "this K : " << K << endl;
	if( K == 1 ){
		puts( "1" );
		puts( "1" );
		return;
	}
	REP( ax , SZ( P ) )
	 	for( int bx = ax ; bx < SZ(P) ; ++bx )
	 		for( int cx = bx ; cx < SZ(P) ; ++cx )
	 			for( int dx = cx ; dx < SZ(P) ; ++dx )
	 				for( int ex = dx ; ex < SZ(P) ; ++ex ){
			 			int a = P[ ax ] ;
						int b = P[ bx ] ;
						int c = P[ cx ] ;
						int d = P[ dx ];
						int e = P[ ex ];
			 			int term = a * b * c * d * e;
						if( term > K ) continue;
						int cur = K - term;
						vi v;
						if( a > 1 ) v.pb( a );
						if( b > 1 ) v.pb( b );
						if( c > 1 ) v.pb( c );
						if( d > 1 ) v.pb( d );
						if( e > 1 ) v.pb( e );
						if( !SZ(v) ) continue;
						if( cur * SZ(v) <= 100 - accumulate( all( v ) , 0 ) ){
							vi w;
							int it = 1;
							REP( i , SZ(v) ){
								vi vec;
								REP( j , v[ i ] ) vec.pb( it ++ );
								reverse( all( vec ) );
								REP( j , SZ(vec) ) w.pb( vec[ j ] );
							}
							vvi ww;
							REP( i , cur ){
								vi vec;
								REP( j , SZ(v) )
									vec.pb(it ++);
								ww.pb( vec );
							}
							reverse( all( ww ) );
							vi ans;
							REP( i , SZ( ww ) )REP( j , SZ(ww[ i ])) ans.pb( ww[ i ][ j ] );
							REP( i , SZ(w) ) ans.pb( w[ i ] );
							impr(ans);
							return;
						}
					}
	cout << "K  :" << K << endl;
	assert( 0 );
}
int main(){
	for( int K = 1 ; K <= 100000 ; ++K ) doit( K );
	int cases;
	scanf( "%d" , &cases );
	REP(tc , cases){
		 int K ;
		 scanf( "%d" , &K );
		 doit(K);
	}
}


