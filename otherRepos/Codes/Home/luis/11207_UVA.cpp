#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )

int main()
{
	int n;
	while( sc( n ) == 1 )
	{
		if( n == 0 ) break;
		int ind = -1 , maxi = 0;
		for( int i = 1 ; i <= n ; ++i )
		{
			int x , y;
			sc( x ) , sc( y );
			if( y > x ) swap( x , y );
			int op1 = min( 4*y , x ) , op2 = 2*y;
			op1 = max( op1 , op2 );
			if( op1 > maxi ) maxi = op1 , ind = i;
		}
		printf( "%d\n" , ind );
	}
}
