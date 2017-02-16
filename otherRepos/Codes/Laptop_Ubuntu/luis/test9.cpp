#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define MAXVAL 100000

typedef vector< int > vi;
typedef long long ll;

struct FT{
	int bit[ MAXVAL + 5 ];
	FT(){ clr( bit , 0 );}
	void update( int pos , int val ){
		while( pos <= MAXVAL ){
			bit[ pos ] += val;
			pos += pos & -pos;
		}
	}
	int query( int pos ){
		int sum = 0;
		while( pos ){
			sum += bit[ pos ];
			pos -= pos & -pos;
		}
		return sum;
	}
};

int main(){
	ios_base :: sync_with_stdio( 0 );
	int n;
	cin >> n;
	vi v( n );
	REP( i , n ) cin >> v[ i ];
	map< int , int > mapa;
	sort( all( v ) );
	REP( i , n ) mapa[ v[ i ] ] = i + 1 ;
	FT bit;
	while( 1 ){
		int op;
		cin >> op;
		if( !op ) break;
		if( op == 1 ){ // insertar
			int val;
			cin >> val;
			bit.update( mapa[ val ] , +1 );
		}else if( op == 2 ){ // eliminar
			int val;
			cin >> val;
			bit.update( mapa[ val ] , -1 );
		}else if( op == 3 ){ // lowerbound( primer valor mayor o igual )
			int val;
			cin >> val;
			int L = lower_bound( all( v ) , val ) - v.begin();			
			val = v[ L ];
			int pos = (!mapa.count( val )) ? -1 : mapa[ val ];
			L ++;
			//cout << "pos : " << pos << endl;
			if( pos != -1 && bit.query( pos ) - bit.query( pos - 1 ) ){
				cout << val << '\n';
				continue;
			}
			//cout << "L : " << L << endl;
			int lo = L , hi = MAXVAL;
			while( hi - lo > 1 ){
				int med = (lo + hi) >> 1;
				if( bit.query( med ) > bit.query( L ) ) hi = med;
				else lo = med;
			}
			//cout << "query( 100 ) : " << bit.query( 1 ) << endl;
			//cout << "hi : " << hi << endl;
			cout << v[ hi - 1 ] << '\n';
		}else if( op == 4 ){ // kth
			int k;
			cin >> k;
			int lo = 1 , hi = MAXVAL;
			if( bit.query( lo ) >= k ){
				int ind = lo;
				cout << v[ --ind ] << '\n';
				continue;
			}
			while( hi - lo > 1 ){
				int med = (lo + hi) >> 1;
				if( bit.query( med ) >= k ) hi = med;
				else lo = med;
			}
			int ind = hi;
			cout << v[ --ind ] << '\n';
		}else { // existe
			int val;
			cin >> val;
			int pos = mapa[ val ];
			if( bit.query( pos ) - bit.query( pos - 1 ) ) cout << "FOUND\n";
			else cout << "NOT FOUND\n";
		}
	} 
}



