#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

typedef long long ll;
ll f( ll x ){
	if( x == 0 ) return -1;
	ll it = 1;
	int mask = 0;
	while( 1 ){
		ll cur = it * x;
		while( cur ){
			int temp = cur % 10;
			mask |= (1 << temp);
			cur /= 10;
		}
		if( mask == (1 << 10) - 1){
			return it * x;
		}
		it ++;
	}
}
int main(){
	/*
	for( int x = 0 ; x <= 1e6 ; ++x ){
		cout << x << " " << f( x ) << endl;
	}
	*/
	
	int cases;
	sc( cases );
	REP( tc , cases ){
		int x;
		sc( x );
		if( x == 0 ){
			cout << "Case #" << tc + 1 << ": " << "INSOMNIA" << '\n';
			continue;
		}
		cout << "Case #" << tc + 1 << ": " << f( x ) << '\n';
	}
}


