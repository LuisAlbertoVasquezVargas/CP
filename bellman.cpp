int n , m , sz;
int orig[ N + 5 ] , dest[ N + 5 ] , peso[ N + 5 ];
void add_edge( int u , int v , int w ){
	orig[ sz ] = u ;
	dest[ sz ] = v;
	peso[ sz ] = w;
	sz++;
}
vi D;
bool relax( int k ){
	int u = orig[ k ] , v = dest[ k ] , w = peso[ k ];
	if( D[ u ] + w < D[ v ] ){
		D[ v ] = D[ u ] + w;
		return 1;
	}
	return 0;
}
bool bellmanFord(){
	D = vi( n , INF );
	D[ 0 ] = 0;
	REP( it , n - 1 )
		REP( i , m )
			relax( i );
	REP( i , m ) if( relax( i ) ) return 0;
	return 1;
}
int main()
{
	int cases , u , v , w ;
	sc( cases );
	while( cases -- ){
		sc( n ) , sc( m );
		sz = 0;
		REP( i , m ){
			sc( u ) , sc( v ) , sc( w );
			add_edge( u , v , w );
		}
		puts( bellmanFord() ? "not possible" : "possible" );
	}
}
