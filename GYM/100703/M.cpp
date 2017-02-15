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

#define test() cout << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;


#define MOD1 100003LL
#define MOD2 100019LL
#define MOD3 1000000007LL
#define MOD4 1000000009LL

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef vector< vvpii > vvvpii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;

int ceil( int a , int b ){
	if( a == 0 ) return 0;
	return (a - 1)/ b + 1;
}
int main(){
	int n;
	while( sc( n ) == 1 ){
		vi Q( n ) , C( n ) , P( n );
		REP(i , n) sc( Q[ i ] );
		REP(i , n) sc( C[ i ] ); 
		REP(i , n) sc( P[ i ] );
		int mini = INT_MAX;
		for( int cant = 100 ; cant >= 0 ; --cant ){
			bool possible = 1;
			int cost = 0 ;
			REP( i , n )
				if( C[ i ] * cant >= Q[ i ] ) cost += (C[ i ] * cant - Q[ i ]) * P[ i ];
				else possible = 0;
			if( possible ) mini = min( mini , cost );
		}
		printf( "%d\n" , mini );
	}

}


