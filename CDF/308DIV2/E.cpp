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

#define INF (1<<29)
#define DEBUG( x ) cerr << #x << "=" << (x) << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << (x) << " " << #y << "=" << (y) <<endl;

typedef vector< int > vi;
typedef vector< string > vs;
typedef unsigned long long ull;
typedef vector< ull > vull;

struct Node{
	ull len;
	ull S;
	ull lo , hi;
	Node(){
		S = len = lo = hi = 0;
	}
	Node( vull &v , ull &sum ){
		S = sum;
		lo = v.front();
		hi = v.back();
		len = SZ(v);
	}
};
Node operator + ( const Node &a , const Node &b ){
	if( !a.len ) return b;
	if( !b.len ) return a;
	
	Node c;
	c.len = a.len + b.len;
	c.lo = a.lo;
	c.hi = b.hi;
	c.S = a.S + b.S;
	return c;
}
Node operator * ( const Node &a , const Node &b ){
	if( !a.len ) return b;
	if( !b.len ) return a;
	Node c;
	c.len = a.len + b.len - 1;
	ull prod = (a.hi * b.lo);
	c.S = a.S - a.hi + prod + b.S - b.lo;
	c.lo = (a.len == 1) ? prod : a.lo;
	c.hi = (b.len == 1) ? prod : b.hi;
	return c;
}

Node eval( int lo , int hi , string &s ){//like 5+10+8*8
	vull STACK;
	for( int i = lo ; i <= hi ; i += 2 ){
		if( i == lo ){
			STACK.pb( s[ i ] - '0' );		
		}else if( s[ i - 1 ] == '+' ){
			STACK.pb( s[ i ] - '0' );
		}else{
			ull last = STACK.back();
			STACK.pop_back();
			ull factor = s[ i ] - '0';
			STACK.pb( factor * last );
		}
	}
	ull S = accumulate( all( STACK ) , 0ULL );
	return Node( STACK , S );
}

int main(){
	string s;
	while( cin >> s ){
		int n = SZ( s );
		vector< Node > pref(n + 1) , suf( n + 1 );
		for( int i = 0 ; i < n ; i += 2 ){
			pref[ i ] = eval( 0 , i , s );
			suf[ i ] = eval( i , n - 1 , s );
		}
		
		ull ans = 0;
		
		for( int i = 0 ; i < n ; i += 2 ){
			vull STACK;
			ull S = 0;
			
			for( int j = i ; j < n ; j += 2 ){
				if( j == i ){
					ull last = s[ j ] - '0';
					STACK.pb( last );
					S += last;
				}else if( s[ j - 1 ] == '+' ) {
					ull last = s[ j ] - '0';
					STACK.pb( last );
					S += last;
				}else{
					ull last = STACK.back();
					STACK.pop_back();
					S -= last;
					ull factor = s[ j ] - '0';
					STACK.pb( factor * last );
					S += STACK.back();
				}
				Node a = ((i - 2 < 0) ? Node() : pref[ i - 2 ]);
				Node b;
				b.len = 1 , b.lo = b.hi = b.S = S;
				Node c = ((j + 2 >= n) ? Node() : suf[ j + 2 ]);

				Node temp = a;
				if( i - 1 >= 0 ){
					if( s[ i - 1 ] == '+' ) temp = temp + b;
					else temp = temp * b;
				}else temp = b;
				if( j + 1 < n ){
					if( s[ j + 1 ] == '+' ) {
						temp = temp + c;
					}else temp = temp * c;
				}
				ans = max( ans , temp.S );
			}
			
		}
		
		cout << ans << '\n';
	}
}


