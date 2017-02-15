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

int match( string s , string t ){
	int ans = 0;
	REP( i , min( SZ( s ) , SZ( t ) ) ){
		if( s[ i ] == t[ i ] ) ans ++;
		else break;
	}
	return ans;
}
int main(){
	int cases;
	cin >> cases;
	REP( tc , cases ){
		string s;
		int K;
		cin >> s >> K;
		int ans = 0 , n = SZ( s );
		for( int i = 0 ; i < n ; ++i )
			for( int j = i ; j < n ; ++j )
				for( int a = 0 ; a < n ; ++ a )
					for( int b = a ; b < n ; ++b ){
						if( i == a && j == b ) continue;
						string x = s.substr( i , j - i + 1 );
						string y = s.substr( a , b - a + 1 );
						if( match( x , y ) >= K ) ans ++;
					}
		cout << ans << '\n';
	}
}


