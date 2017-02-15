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

#define N 10000

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

int id[ N + 5 ];
int Find( int x ){ return id[ x ] = ((id[ x ] == x) ? x : Find(id[ x ]));}
void Union( int u , int v ){
	int pu = Find( u ) , pv = Find( v );
	if( id[ pu ] != id[ pv ] ) id[ pu ] = pv;
}

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n , m;
		sc( n ) , sc( m );
		REP( i , n ) id[ i ] = i;
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			Union( u , v );
		}
		int cnt = 0;
		REP( i , n ) if( Find( i ) == i ) cnt ++;
		printf( "%d\n" , (cnt * (cnt - 1)) >> 1 );
	}
}


