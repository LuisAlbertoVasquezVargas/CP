#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )

int phi( int n ){
	int ans = n;
	for( int i = 2 ; i*i <= n ; ++i )
		if( n % i == 0 ){
			while( n%i == 0 ) n/= i;
			ans -= ans/i; 
		}
	if( n > 1 ) ans -= ans/n;
	return ans;
}
int main()
{
	int n;
	while( sc( n ) == 1 ){
		if( n == 0 ) break;
		printf( "%d\n" , phi( n ) );
	}
}
