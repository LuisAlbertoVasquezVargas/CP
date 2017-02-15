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

#define N 18
#define INF (1<<20)

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

inline int ones( int x ){ return __builtin_popcount( x );}
int n;
int A[ N + 5 ];
int G[ N + 5 ][ N + 5 ];
bool used[ N + 1 ][ 1 << N ];
int memo[ N + 1 ][ 1 << N ];

int get( string s ){
	istringstream in( s );
	int x;
	in >> x;
	return x;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	int cases;
	cin >> cases;
	string dumm;
	string pattern = " --> ";
	REP( tc , cases ){
		int m;
		cin >> n >> m;
		getline( cin , dumm );
		map< string , int > mapa;
		REP( i , n ){
			string s;
			getline( cin , s );
			int last = -1;
			for( int j = SZ(s) - 1 ; j >= 0 ; --j )
				if( s[ j ] == ' ' || isdigit( s[ j ] ) ) last = j;
				else break;
			assert( last != -1 );
			string a = s.substr( 0 , last );
			int val = get( s.substr( last ) );
			mapa[ a ] = i;
			A[ i ] = val;
		}
		clr( G , 0 );
		
		REP( i , m ){
			string s;
			getline( cin , s );
			int pos = s.find( pattern );
			string a = s.substr( 0 , pos );
			string b = s.substr( pos + SZ(pattern) );
			int u = mapa[ a ] , v = mapa[ b ];
			
			G[ u ][ v ] = 1;
		}
		vi ind( n , 0 );
		REP( u , n ) REP( v , n )
			if( G[ u ][ v ] ) ind[ v ] ++;
		priority_queue< pair< int , int > > Q;

		//REP( i , n ) printf( "%d%c" , ind[ i ] , (i + 1 == n) ? 10 : 32 );
		int ans = 0 , lvl = 1;
		REP( i , n )
			if( !ind[ i ] )
				Q.push( mp( -A[ i ] , i ) );
		//DEBUG( SZ( Q ) );
		assert( !Q.empty() );
		while( !Q.empty() ){
			auto p = Q.top(); Q.pop();
			int u = p.se , w = -p.fi;
			ans += lvl * w;
			lvl ++;
			REP( v , n )
				if( G[ u ][ v ] ){
					ind[ v ] --;
					if( !ind[ v ] ){
						Q.push( mp( -A[ v ] , v ) );
					}
				}
		}
		printf( "%d\n" , ans );
	}
}

