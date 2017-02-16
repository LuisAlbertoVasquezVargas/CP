#include<bits/stdc++.h>
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )

#define N 1005
#define PI acos( -1.0 )
#define INF 1e100
#define EPS (1e-8)

typedef long double ld;

ld A[ N ] , B[ N ];
ld AA[ N ] , BB[ N ];

int main()
{
	int n;
	while( cin >> n )
	{
		REP( i , n )
		{
			cin >> AA[ i ] >> BB[ i ];
			A[ i ] = AA[ i ]*( PI/180 ) , B[ i ] = BB[ i ]*( PI/180 );
		}
		ld mini = INF;
		int ind = -1;
		REP( i , n )
		{
			ld maxi = -INF ;
			REP( j , n )
			{
				ld cost = sin( A[ i ] )*sin( A[ j ] ) + cos( A[ i ] )*cos( A[ j ] )*cos( B[ i ] - B[ j ] );
				ld dist = acos( cost );
				maxi = max( maxi  , dist );
			}
			if( maxi <= mini + EPS ) mini = maxi , ind = i;
		}
		printf( "%.2f %.2f\n" , ( double )AA[ ind ] , ( double )BB[ ind ] );
	}
}
