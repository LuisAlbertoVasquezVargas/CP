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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	int n;
	while( sc( n ) == 1 ){
		int c100 = 0 , c25 = 0 , c50 = 0;
		int solve = 1;
		REP( i , n ){
			int x;
			sc( x );
			if( x == 25 ) c25 ++;
			else if( x == 50 ){
				if( c25 ){
					c25 --;
					c50 ++;
				}else solve = 0;
			}else{ // x = 100
				if( c50 >= 1 && c25 >= 1 ){
					c50 -- , c25 --;
					c100 ++;
				}else if( c25 >= 3 ){
					c25 -= 3;
					c100 ++;
				}else solve = 0;
			}
		}
		puts( solve ? "YES" : "NO" );
	}
}


