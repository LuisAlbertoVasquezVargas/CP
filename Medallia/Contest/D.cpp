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
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z << endl;

#define N 100

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;
typedef vector< ld > vld;

int vis[ N + 5 ][ N + 5 ];
int n , m , ans ;
int dx[] = { 0 , -1 , 0  , 1 };
int dy[] = { 1 , 0  , -1 , 0 };
bool valid( int x , int y ){ return x >= 0 && y >= 0 && x < n && y < m ;}
int timer[ N + 5 ][ N + 5 ];
void dfs( int x , int y , int dir ){
	timer[ x ][ y ] = ans ++;
	vis[ x ][ y ] = 1;
	REP( k , 4 ){
		int nx = x + dx[ (dir - k + 4)%4 ];
		int ny = y + dy[ (dir - k + 4)%4 ];
		if( valid( nx , ny ) && !vis[ nx ][ ny ] ){
			dfs( nx , ny , (dir + k - 1 + 4)%4 );
			return;
		}
	}
}
int main(){
	while( sc( n ) == 1 ){
		sc( m );
		clr( vis , 0 );
		ans = 0;
		dfs( 0 , 0 , 0 );
		REP( i , n ) REP( j , m ) printf( "%d%c" , timer[ i ][ j ] , (j + 1 == m ? 10 : 32) );
		printf( "%d\n" , ans );
	}	
}


