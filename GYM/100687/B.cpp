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

bool f( string &s , string &t ){
	REP( i , SZ(s) ){
		if( t[ i ] == '?' ) continue;
		if( s[ i ] != t[ i ] ) return 0;
	}
	return 1;
}

int main(){
	int n;
	while( cin >> n ){
		string S;
		cin >> S;
		int maxi = 0;
		vector< string > T( n );
		vi G( n );
		map< string , int > mapa;
		REP( i , n ) cin >> T[ i ] >> G[ i ] , mapa[ T[ i ] ] ++;
		REP( i , n ){
			if( f( S , T[ i ] ) && mapa[ T[ i ] ] == 1 ) 
				maxi = max( maxi , G[ i ] );
		}
		cout << maxi << '\n';
	}
}


