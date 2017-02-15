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

ll get( vi &x , int a , int b ){
	return abs( x[ a ] - x[ b ] );
}

int main(){
	int n;
	while( sc( n ) == 1 ){
		vi x( n );
		REP( i , n ) sc( x[ i ] );
		
		REP( i , n ){
	
			vi POS = { 0 , n - 1 };
			ll maxi = 0;
			REP( j , SZ(POS) )
				if( POS[ j ] != i ) maxi = max( maxi , get( x , i , POS[ j ] ) );
	
			POS = { i - 1 , i , i + 1 };
			ll mini = LLONG_MAX;
			REP( j , SZ(POS) )
				if( POS[ j ] >= 0 && POS[ j ] < n && POS[ j ] != i ) 
					mini = min( mini , get( x , i , POS[ j ] ) );
	
			cout << mini << " " << maxi << '\n';
		}
	}
}

