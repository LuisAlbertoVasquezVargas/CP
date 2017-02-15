#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 1005

string s , t;
short DP[ N ][ N ];
int main()
{
	ios_base :: sync_with_stdio( 0 );
	while( getline( cin , s ) )
	{
		getline( cin , t );
		int nt = t.size() , ns = s.size();
		REP( i , ns + 1 ) DP[ i ][ nt ] = 0;
		REP( j , nt + 1 ) DP[ ns ][ j ] = 0;
		for( int i = ns - 1 ; i >= 0 ; --i )
			for( int j = nt - 1 ; j >= 0 ; --j )
			{
				short &dev = DP[ i ][ j ] ;
				DP[ i ][ j ] = max( DP[ i + 1 ][ j ] , DP[ i ][ j + 1 ] );
				if( s[ i ] == t[ j ] ) dev = max( dev , short( 1 + DP[ i + 1 ][ j + 1 ] ) );
			}
		printf( "%d\n" , DP[ 0 ][ 0 ] );
	}
}
