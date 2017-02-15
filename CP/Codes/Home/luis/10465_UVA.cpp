#include<bits/stdc++.h>
using namespace std;

#define clr( t , val ) memset( t , val , sizeof( t ) )

#define mp make_pair
#define fi first
#define se second

#define N 10005
#define INF (1<<25)

typedef pair< int , int > pii;

int a , b , t;

int main()
{
	while( scanf( "%d%d%d" , &a , &b , &t ) == 3 ){
		int r = INF , maxi = 0;
		for( int i = 0 ; i * a <= t ; ++i ){
			int money = t - i*a;
			int res = money%b;
			if( res < r ){
				r = res;
				maxi = i + money/b;
			}
			else if( res == r ){
				maxi = max( maxi , i + money/b );
			}
		}
		if( r == 0 ) printf( "%d\n" , maxi );
		else printf( "%d %d\n" , maxi , r );

	}
}
