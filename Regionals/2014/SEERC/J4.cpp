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
 
#define N 30000
 
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< pii > vpii;
typedef vector< int > vi;

int n;
vpii V[ N + 5 ];
void update( int x , int ylo , int yhi ){
	if( ylo >= n ) return;
	ylo = max( ylo , 0 );
	yhi = min( yhi , n - 1 );
	if( ylo > yhi ) return;
	//DEBUG( x );
	//DEBUG2( ylo , yhi );
	V[ x ].pb( mp( ylo , yhi ) );
}
const int maxN = 100224;
 
struct BIT {
    int data[maxN];
    void update(int idx, int val) {
        while (idx < maxN) {
            data[idx] += val;
            idx += idx & -idx;
        }
    }
    void update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }
    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += data[idx];
            idx -= idx & -idx;
        }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l);
    }
};
 
struct LazyBIT {
    BIT bitAdd, bitSub;
    void update(int l, int r, int val) {
        bitAdd.update(l, r, val);
        bitSub.update(l, r, (l - 1) * val);
        bitSub.update(r + 1, (-r + l - 1) * val);
    }
    int query(int idx) {
        return idx * bitAdd.query(idx) - bitSub.query(idx);
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
}ST;

int main(){
	while( sc( n ) == 1 ){
		REP( i , n ) V[ i ].clear();
		int Q;
		sc( Q );
		REP( it , Q ){
			int x , y , p , ori;
			sc( x ) , sc( y ) , sc( p ) , sc( ori );
			//DEBUG2( x , y );
			//3 (0:SW, 1:SE, 2:NE, 3:NW).
			if( ori == 0 ){
				//***
				///**
				////*
				REP( i , p )
					if( x + i < n ) update( x + i , y - (p - 1) + i , y );
					else break;
			}else if( ori == 1 ){
				//***
				//**
				//*
				REP( i , p )
					if( x + i < n ) update( x + i , y , y + (p - 1) - i );
					else break;
			}else if( ori == 2 ){
				//*
				//**
				//***
				REP( i , p )
					if( x - i >= 0 ) update( x - i , y , y + (p - 1) - i );
					else break;
			}else{
				////*
				///**
				//***
				REP( i , p ) 
					if( x - i >= 0 ) update( x - i , y - (p - 1) + i , y );
					else break;
			}
			/*
			REP( i , n ) {
				REP( j , 10 ){
					bool ok = T[ i ][ 0 ] & (1 << j);
					cout << ok ;
				}
				cout << endl;
			}
			*/
		}
		
		int ans = 0;
		REP( i , n ){
			REP( k , 2 ){
				for( auto p : V[ i ] )
					update( 0 , 0 , n - 1 , p.fi , p.se );
				if( k == 0 ) ans += query( 0 , 0 , n - 1 , 0 , n - 1 );
			}
		}
		printf( "%d\n" , ans );
	}
}



