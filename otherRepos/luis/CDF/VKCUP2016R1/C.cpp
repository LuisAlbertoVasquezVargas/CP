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

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

void insert( int u , int v , vi &ind ){
	ind[ u ] ++;
	ind[ v ] ++;
	printf( "%d %d\n" , u + 1 , v + 1 );
}
void add( int from , int len , int &cur , vi &ind ){
	REP( i , len ){
		insert( from , cur , ind );
		from = cur;
		cur ++;
	}
}
int main(){
	int n , D , H;
	while( cin >> n >> D >> H ){
		if( D > 2 * H ){
			puts( "-1" );
			continue;
		}
		if( D == 1 ){
			if( n == 2 && H == 1 ){
				puts( "1 2" );
				continue;
			}
			puts( "-1" );
			continue;
		}
		vi ind( n );
		int cur = 1;
		add( 0 , H , cur , ind );
		add( 0 , D - H , cur , ind );
		int node = -1;
		REP( i , cur ){
			if( ind[ i ] >= 2 ) node = i;
		}
		if( node != -1 ){
			while( cur < n ){
				add( node , 1 , cur , ind );
			}
		}
		
	}
}



