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

#define N 100000

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll comb3( ll n ){
	return (n * (n - 1) * (n - 2)) / 6LL;
}
ll comb2( ll n ){
	return (n * (n - 1)) / 2LL;
}

vi G[ N + 5 ];
int n;
ll corner = 0;
bool bipartite(){
	queue< int > Q;
	vi col( n , -1 );
	REP( s , n ){
		if( col[ s ] != -1 ) continue;
		vi ct( 2 );
		Q.push( s );
		col[ s ] = 0;
		ct[ col[ s ] ] ++;
		while( !Q.empty() ){
			int u = Q.front();
			Q.pop();
			for( auto v : G[ u ] ){
				if( col[ v ] == -1 ){
					col[ v ] = col[ u ] ^ 1;
					ct[ col[ v ] ] ++;
					Q.push( v );
				}else{
					if( col[ u ] == col[ v ] ) return 0;
				}
			}
		}
		REP( i , 2 ) corner += comb2( ct[ i ] );
	}
	return 1;
}
void doit( ll a , ll b ){
	cout << a << " " << b << '\n';
}

int main(){
	int m;
	while( sc( n ) == 1 ){
		sc( m );
		REP( i , N ) G[ i ].clear();
		vi deg( n );
		REP( i , m ){
			int u , v;
			sc( u ) , sc( v );
			u -- , v --;
			G[ u ].pb( v );
			G[ v ].pb( u );
			deg[ u ] ++;
			deg[ v ] ++;
		}
		corner = 0;
		if( !bipartite() ) {
			doit( 0 , 1 );
			continue;
		}
		if( m == 0 ){
			doit( 3 , comb3( n ) );
			continue;
		}
		int ct = 0;
		REP( u , n ) if( deg[ u ] >= 2 ) ct ++;
		if( ct ){
			doit( 1 , corner );
			continue;
		}
		ct = 0;
		REP( u , n ) if(deg[ u ] == 1) ct ++;
		ll ans = (ll)(n - 2) * (ll)(ct/2LL);
		doit( 2 , ans );
	}
}



