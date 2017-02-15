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

#define test() cerr << "hola q hace" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef vector< ll > vll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;
typedef vector< vi > vvi;

int cnt;
int n;
int lvl;
void dfs( int pos , int last , ll sum , ll prod ){
	if( pos == lvl ){
		if( sum == prod ) cnt++;
		return;
	}
	for( int val = last ; val <= n ; ++val ){
		if( pos < lvl - 1 ){
			if( prod * val <= n ) dfs( pos + 1 , val , sum + val , prod * val );
		}else{
			dfs( pos + 1 , val , sum + val , prod * val );
		}
	}
}
int solve(){
	int ans = 0;
	for( int k = 1 ; k <= min( 10 , n ) ; ++k ){
		int ones = n - k;
		cnt = 0;
		lvl = k;
		dfs( 0 , 2 , ones , 1 );
		ans += cnt;
	}
	return ans;
}
int main(){
	freopen( "sump.in" , "r" , stdin );
	freopen( "sump.out" , "w" , stdout );
	
	while( sc( n ) == 1 ){
		printf( "%d\n" , solve() );
	}	
}


