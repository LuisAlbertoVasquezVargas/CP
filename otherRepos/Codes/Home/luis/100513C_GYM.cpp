#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define N 300000

typedef vector< int > vi;
typedef vector< string > vs;

struct FT {
	vi T;
	vi id;
	int len;
	int MAXVAL;
	FT() {}
	FT( int x , vi &vec ) {
		MAXVAL = x + 1;
		len = x;
		T = vi( MAXVAL + 1 );
		id = vec;
	}
	void Update( int pos , int val ) { update( pos + 1 , val ); }
	void update( int pos , int val ) {
		while( pos <= MAXVAL ){
			T[ pos ] += val;
			pos += pos & -pos;
		}
	}
	int get2( int lo , int hi ) { return Query( hi ) - Query( lo - 1 ); }
	int Query( int pos ){ return query( pos + 1 );}
	int query( int pos ) {
		int sum = 0;
		while( pos ){
			sum += T[ pos ];
			pos -= pos & -pos;
		}
		return sum;
	}
	int getFirst( int end ){
		int lo = 0 , hi = end;
		if( Query( lo ) == Query( hi ) ) return id[ lo ];
		while( hi - lo > 1 ){
			int med = (lo + hi) >>1;
			if( Query( med ) == Query( hi ) ) hi = med;
			else lo = med;
		}
		return id[ hi ];
	}
} st[ N + 5 ];

int chain[ N + 5 ] , tam[ N + 5 ] , h[ N + 5 ] , p[ N + 5 ];

int n ; 
int peso[ N + 5 ];
int csz , cola[ N + 5 ];
vi E[ N + 5 ];

int querynodos( int u , int v ) {
	int sum = 0;
	while( chain[ u ] != chain[ v ] ) {
		if( h[ chain[ u ]]  < h[ chain[ v ] ]) swap( u , v );
		int c = chain[ u ] , len = st[ c ].len;
		sum += st[ c ].get2( 0 , h[ u ] - h[ c ] );
		u = p[ chain[ u ] ];
	}
	if( h[ u ] < h[ v ] ) swap( u , v );
	int c = chain[ u ] , len = st[ c ].len;
	sum += st[ c ].get2( h[ v ] - h[ c ] , h[ u ] - h[ c ] );
	return sum;
}
int up( int u ){
	while( 1 ) {
		int c = chain[ u ] , len = st[ c ].len;
		if( st[ c ].get2( 0 , h[ u ] - h[ c ] ) ){
			return st[ c ].getFirst( h[ u ] - h[ c ] );
		}else u = p[ chain[ u ] ];
	}
}
void parse( string s , string &key , string &value ){
	int pos = s.find( "=" );
	key = s.substr( 0 , pos ) , value = s.substr( pos + 1 );
}
struct comp{
	vs keys , values;
	int id , p;
	comp(){}
	comp( int id , int p , vs keys , vs values ) : id( id ) , p( p ) , keys( keys ) , values( values ) {}
};
struct event{
	int u , idQ;
	event( int u , int idQ ) : u( u ) , idQ( idQ ) {}
};
int getId( vs &vec , string s ){ return lower_bound( all( vec ) , s ) - vec.begin();}

int main(){
	ios_base :: sync_with_stdio( 0 );
	while( cin >> n ){
		REP( i , N ) E[ i ].clear();
		vs allKeys;
		vector< comp > components( n );
		REP( v , n ) {
			int u , len;
			cin >> u >> len;
			u --;
			if( u >= 0 ){
				E[ u ].pb( v );
				E[ v ].pb( u );
			}
			vs keys , values;
			vector< pair< string , string > > vec;
			REP( i , len ){
				string s;
				cin >> s;
				string key , value;
				parse( s , key , value );
				vec.pb( mp( key , value ) );
				allKeys.pb( key );
			}
			sort( all( vec ) );
			REP( i , SZ( vec ) ) keys.pb( vec[ i ].fi ) , values.pb( vec[ i ].se );
			components[ v ] = comp( v , u , keys , values );
		}
		sort( all( allKeys ) );
		allKeys.resize( unique( all( allKeys ) ) - allKeys.begin() );

		vector< vi > ev1( SZ( allKeys ) );
		REP( i , n ){
			int p = components[ i ].p ;
			vs keys = components[ i ].keys , values = components[ i ].values;
			REP( j , SZ( keys ) ){
				int id = getId( allKeys , keys[ j ] );
				ev1[ id ].pb( i );
			}
		}

		clr( p , -1 );
		csz = 0;
		cola[ csz++ ] = 0;
		p[ 0 ] = 0;
		h[ 0 ] = 0;
		REP( i , csz ) {
			int u = cola[ i ];
			FOR( e , E[ u ] ) {
				int v = *e;
				if ( ~p[ v ] ) continue;
				cola[ csz++ ] = v;
				p[ v ] = u;
				h[ v ] = h[ u ] + 1;
			}
		}
		for( int i = csz - 1 ; i >= 0 ; --i ) {
			int u = cola[ i ];
			tam[ u ] = 1;
			FOR( e , E[ u ] ) {
				int v = *e;
				if( p[ u ] == v ) continue;
				tam[ u ] += tam[ v ];
			}
		}
		clr( chain , -1 );
		REP( i , csz ) {
			int u = cola[ i ];
			if ( ~chain[ u ] ) continue;
			chain[ u ] = u;
			int v = u;
			while( 1 ) { 
				int next = -1;
				FOR( v , E[ u ] ) if( p[ *v ] == u )
					if ( next ==-1 || tam[ next ] < tam[ *v ] ) next = *v;
				if( next == -1 ) break;
				chain[ next ] = chain[ u ];
				u = next;
			}
			int len = h[ u ] - h[ v ] + 1;
			vi id( len );
			
			REP( i , len ) {
				id[ i ] = u;
				u = p[ u ];
			}
			reverse( all( id ) );
			st[ v ] = FT( len , id );
		}
		int Q;
		cin >> Q;
		vector< vector< event > > ev2( SZ( allKeys ) );

		REP( q , Q ) {
			int u;
			string key;
			cin >> u >> key;
			cout << "";
			u -- ;
			if( !binary_search( all( allKeys ) , key ) ) continue;
			int id = getId( allKeys , key );
			ev2[ id ].pb( event( u , q ) );
			/*
			if( op == 'I' ) {
				scanf( "%d%d" , &u , &v ); u--;//// increment in v to u
				int c = chain[ u ] , len = st[ c ].len;
				st[ c ].update( h[ u ] - h[ c ] , v );
			}else {
				scanf("%d%d", &u, &v); u-- , v--;
				int ans = querynodos( u , v );
				printf( "%d\n" , ans );
			}
			*/
		}
		/*
		cout << "CHAINS" << endl;
		REP( i , n ) cout << chain[ i ] << " ";
		cout << endl;
		*/
		/*
		REP( i , SZ( ev2 ) ) {
			REP( j , SZ( ev2[ i ] ) ) cout << "( " << ev2[ i ][ j ].u << " , " << ev2[ i ][ j ].idQ << " ) ";
			cout << endl;
		}
		*/
		vs ans( Q , "N/A" );
		
		REP( i , SZ( ev1 ) ) {
			/*
			cout << allKeys[ i ] << " :: ";
			REP( j , SZ( ev1[ i ] ) ) cout << ev1[ i ][ j ] << " ";
			cout << endl;
			*/
			REP( j , SZ( ev1[ i ] ) ) {
				int u = ev1[ i ][ j ] ;
				int c = chain[ u ];
				/*
				cout << u << " " << c << endl;
				cout << h[ u ] << " " << h[ c ] << " " << st[ c ].len << endl;
				*/
				st[ c ].Update( h[ u ] - h[ c ] , +1 );
			}
			/*
			REP( j , n ) cout << querynodos( j , j ) << " ";
			cout << endl;
			cout << "len queries " << SZ( ev2[ i ] ) << endl;
			*/
			REP( j , SZ( ev2[ i ] ) ){
				int u = ev2[ i ][ j ].u , idQ = ev2[ i ][ j ].idQ;
				if( querynodos( 0 , u ) == 0 ) continue;
				int v = up( u );
				//cout << "beg : " << u << "   end : " << v << endl ;
				int id = getId( components[ v ].keys , allKeys[ i ] );
				/*
				cout << "target = " << allKeys[ i ] << endl;
				REP( k , SZ( components[ v ].keys ) ) cout << components[ v ].keys[ k ] << " ";
				cout << endl;
				*/
				//cout << "id : " << id << " contains : " << components[ v ].keys[ id ] << endl;
				ans[ idQ ] = components[ v ].values[ id ];
			}
			
			REP( j , SZ( ev1[ i ] ) ) {
				int u = ev1[ i ][ j ] ;
				int c = chain[ u ];
				st[ c ].Update( h[ u ] - h[ c ] , -1 );
			}
			
		}
		
		REP( i , SZ( ans ) ) {
			cout << ans[ i ] << '\n';
			//fflush(stdout);
		}
		
	}
}



