#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define N 5000
#define INF (1<<29)

typedef vector< int > vi;

struct Node
{
	int id , dist;
	Node(){}
	Node( int id , int dist ) : id( id ) , dist( dist ){}
};
bool operator < ( const Node &a , const Node &b ){ 
	if( a.dist != b.dist ) return a.dist > b.dist ; 
	return a.id > b.id;
}
vi ADJ[ N + 5 ] , DIST[ N + 5 ];
int n;
vi djkstra( int s ){
	vi D( n , INF );
	priority_queue< Node > Q;
	D[ s ] = 0;
	Q.push( Node( s , 0 ) );
	while( !Q.empty() ){
		Node p = Q.top();
		Q.pop();
		int u = p.id , dist = p.dist;
		int nv = ADJ[ u ].size();
		REP( i , nv ){
			int v = ADJ[ u ][ i ];
			int cuv = DIST[ u ][ i ];
			if( dist + cuv < D[ v ] ){
				D[ v ] = dist + cuv;
				Q.push( Node( v , D[ v ] ) );
			}
		}
	}
	return D;
}
int main()
{
	int m , O , F1 , F2 , u , v , w;
	while( sc( n ) == 1 ){
		sc( O ) , sc( F1 ) , sc( F2 ) , sc( m );
		O-- , F1 -- , F2 --;
		if( n == -1 ) break;
		REP( i , n ) ADJ[ i ].clear() , DIST[ i ].clear();
		while( m -- ){
			sc( u ) , sc( v ) , sc( w );
			u -- , v--;
			ADJ[ u ].pb( v );
			DIST[ u ].pb( w );
			ADJ[ v ].pb( u );
			DIST[ v ].pb( w );
		}
		vi D0 = djkstra( O ) , D1 = djkstra( F1 ) , D2 = djkstra( F2 );
		int ind = -1 , maxi = -1;
		REP( i , n ){
			//cout << i << " : " << D0[ i ] << endl;
			//if( i == F1  || i == F2 ) continue;
			if( D1[ i ] + D0[ i ] == D0[ F1 ] && D2[ i ] + D0[ i ] == D0[ F2 ] ){
				if( maxi < D0[ i ] ){
					ind = i;
					maxi = D0[ i ];
				}
			}
		}
		printf( "%d %d %d\n" , D0[ ind ] , D1[ ind ] , D2[ ind ] );
	}
}
