#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define all( v ) v.begin() , v.end()
#define SZ(v) ((int)v.size())
#define pb push_back

typedef vector< int > vi;
typedef long long ll;
typedef vector< ll > vll;

bool doit( int n , string &s , vi &v ){
	vi vis( n );
	int cur = 0;
	while( 1 ){
		if( vis[ cur ] ) return 0;
		vis[ cur ] = 1;
		int dir = s[ cur ] == '<' ? -1 : +1;
		int Next = cur + v[ cur ] * dir;
		if( Next >= 0 && Next < n ){
			cur = Next;
		}else{
			return 1;
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(0);
	int n;
	string s;
	while( cin >> n >> s ){
		vi v( n );
		REP( i , n ) cin >> v[ i ];
		
		puts( doit( n , s , v ) ? "FINITE" : "INFINITE" );
		
	}
}


