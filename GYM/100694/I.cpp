#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF (1<<20)
#define N 200000

#define DEBUG( x ) cerr << #x << " " << (x) << endl;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef long long ll;

int dx[] = { 1 , 0 , -1 , 0 };
int dy[] = { 0 , 1 , 0 , -1 };
string cad[] = { "RIGHT" , "UP" , "LEFT" , "DOWN" };

int CEIL( int n , int b ){
	if( n == 0 ) return 0;
	return (n - 1)/b + 1;
}
int getDist( vi &A , vi &B , vi &d ){
	int dt;
	REP( i , 2 ){
		if( d[ i ] == 0 ){
			dt = CEIL( abs( A[ i ] - B[ i ] ) , 2 );
			break;
		}
	}
	REP( i , 2 ){
		if( d[ i ] != 0 ){
			int nA = A[ i ] + d[ i ] * dt;
			int dif = abs( nA - B[ i ] );
			if( nA < B[ i ] ){
				if( d[ i ] == 1 ) return dt + CEIL( dif , 3 );
				return dt + dif;
			}else{
				if( d[ i ] == 1 ) return dt + dif;
				return dt + CEIL( dif , 3 );
			}
		}
	}
}

int main(){
	ios_base :: sync_with_stdio( 0 );
	map< string , int > mapa;
	REP( i , 4 ) mapa[ cad[ i ] ] = i;
	vi A( 2 );
	while( cin >> A[ 0 ] ){
		REP( i , 2 ){
			if( !i ) continue;
			cin >> A[ i ];
		}
		string s , t;
		cin >> s;
		int dir = mapa[ s ];
		vi d = { dx[ dir ] , dy[ dir ] };
		int best = INT_MAX;
		int n;
		cin >> n;
		REP( k , n ){
			string p;
			cin >> p;
			vi B( 2 );
			REP( i , 2 ) cin >> B[ i ];
			int cur = getDist( A , B , d );
			//DEBUG( cur );
			if( cur < best ){
				best = cur;
				t = p;
			}
		}
		cout << t << '\n';
	}
}




