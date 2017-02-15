#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

typedef long long ll;
typedef unsigned int tint;
int main(){
	int n ;
	tint x ;
	while( sc( n ) == 1  ){
		priority_queue< tint > Q;
		int sz = n;
		n = n/2 + 1 ;
		REP( i , n ) scanf( "%u" , &x ) , Q.push( x );
		for( int i = n ; i < sz ; ++i ){
			sc( x );
			Q.push( x );
			Q.pop();
		}
		n = sz;
		if( n % 2 == 0 ){
			ll p = Q.top() ; Q.pop();
			ll q = Q.top() ; Q.pop();
			ll ans = (p + q);
			if( ans & 1 ) cout << (ans>>1) << ".5\n";
			else cout << (ans>>1) << "\n";
		}
		else cout << Q.top() << '\n';
	}
}
