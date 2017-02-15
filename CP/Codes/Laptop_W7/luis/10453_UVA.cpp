#include<bits/stdc++.h>
using namespace std;

#define clr( t ,  val ) memset( t , val , sizeof( t ) )

#define N 1005

int ns;
char s[ N ];
int memo[ N ][ N ];
int dp( int I , int J ){
	if( I == J ) return 0;
	if( I + 1 == J ) return s[ I ] != s[ J ];
	int &dev = memo[ I ][ J ];
	if( dev == -1 ){
		dev = min( 1 + dp( I + 1 , J ) , 1 + dp( I , J - 1 ) );
		if( s[ I ] == s[ J ] )
			dev = min( dev , dp( I + 1 , J - 1 ) );
	}
	return dev; 
}
string rec( int I , int J ){
	if( I == J ) return string( 1 , s[ I ] );
	if( I + 1 == J ){
		if( s[ I ] == s[ J ] ) return string( 2 , s[ I ] );
		return string( 1 , s[ I ] ) + string( 1 , s[ J ] ) + string( 1 , s[ I ] );
	}
	if( dp( I , J ) == 1 + dp( I + 1 , J ) ) return string( 1 , s[ I ] ) + rec( I + 1 , J ) + string( 1 , s[ I ] );
	if( dp( I , J ) == 1 + dp( I , J - 1 ) ) return string( 1 , s[ J ] ) + rec( I , J - 1 ) + string( 1 , s[ J ] );
	if( s[ I ] == s[ J ] ) return string( 1 , s[ I ] ) + rec( I + 1 , J - 1 ) + string( 1 , s[ J ] );
}

int main()
{
	while( scanf( "%s" , s ) == 1 )
	{
		ns = strlen( s );
		clr( memo , -1 );
		printf( "%d " , dp( 0 , ns - 1 ) );
		string S = rec( 0 , ns - 1 );
		cout << S << '\n';
	}
}
