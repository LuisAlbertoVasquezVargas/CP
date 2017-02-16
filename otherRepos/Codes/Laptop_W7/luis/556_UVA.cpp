#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

int dx[] = { 1 , 0 , -1 , 0 };
int dy[] = { 0 , 1 , 0 , -1 };

int main()
{
	int n , m;
	while( cin >> n >> m )
	{
		if( n == 0 && m == 0 )break;
		vector< string > v( n );
		REP( i , n ) cin >> v[ i ];
		int T[ n + 2 ][ m + 2 ];
		REP( i , n + 2 ) REP( j , m + 2 ) T[ i ][ j ] = 1;
		REP( i , n )REP( j , m ) T[ i + 1 ][ j + 1 ]  = v[ i ][ j ] - '0';
		int vis[ n + 2 ][ m + 2 ];
		REP( i , n + 2 ) REP( j , m + 2 ) vis[ i ][ j ] = 0;
		int X , Y , x , y ;
		x = X = 1 , y = Y = 1;
		int k = 0;
		while( 1 )
		{
			
			cout << x << " " << y << endl;
			int xfront = x + dx[ k ] , yfront = y + dy[ k ];
			int xder = x + dy[ k ] , yder = y - dx[ k ];
			if( T[ xfront ][ yfront ] == 0 && T[ xder ][ yder ] == 1 )
			{
				vis[ x ][ y ]++;
				x = xfront , y = yfront; 
			}
			else if( T[ xfront ][ yfront ] == 0 && T[ xder ][ yder ] == 0 )
			{
				vis[ x ][ y ]++;
				vis[ xfront ][ yfront ]++;
				x = xder , y = yder;
				k = ( k + 1 )%4;
			}
			else k = ( k + 1 )%4;
			if( X == x && Y == y ) break;
		}
		int cnt[ 10 ];
		REP( i , 10 ) cnt[ i ] = 0;
		for( int i = 1 ; i <= n ; ++i )
			for( int j = 1 ; j <= m ; ++j )
				cnt[ vis[ i ][ j ] ]++;
		REP( i , 5 ) printf( "%3d" , cnt[ i ] );
		puts( "" );
	}
}
