#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int main()
{
	int n , m;
	while( scanf( "%d%d" , &n , &m ) ==  2 )
	{
		if( n == 1 )
		{
			if( m == 2 )
			{
				puts( "0" );
				puts( "1 1" );
				puts( "1 2" );
				puts( "1 1" );
			}
			else
			{
				puts( "1" );
				printf( "1 %d 1 1\n" , m );
				for( int j = 1 ; j <= m ; ++j )
					printf( "1 %d\n" , j );
				puts( "1 1" );
			}
		}
		else if( m == 1 )
		{
			if( n == 2 )
			{
				puts( "0" );
				puts( "1 1" );
				puts( "2 1" );
				puts( "1 1" );
			}
			else
			{
				puts( "1" );
				printf( "%d 1 1 1\n" , n );
				for( int i = 1 ; i <= n ; ++i )
					printf( "%d 1\n" , i );
				puts( "1 1" );
			}
		}
		else if( n%2 == 0 )
		{
			puts( "0" );
			for( int j = 1 ; j <= m ; ++j )
				printf( "1 %d\n" , j );
			for( int i = 2 ; i < n ; ++i )
			{
				if( i%2 == 0 )
				{
					for( int j = m ; j >= 2 ; --j )
						printf( "%d %d\n" , i , j );
				}
				else
				{
					for( int j = 2 ; j <= m ; ++j )
						printf( "%d %d\n" , i , j );
				}
			}	
			for( int j = m ; j >= 1 ; --j )
				printf( "%d %d\n" , n , j );
			for( int i = n - 1 ; i >= 1 ; --i )
				printf( "%d 1\n" , i );
		}
		else if( m%2 == 0 )
		{
			puts( "0" );
			puts( "1 1" );
			for( int j = 1 ; j <= m ; ++j )
			{
				if( j%2 == 0 )
				{
					for( int i = n ; i >= 2 ; --i )
						printf( "%d %d\n" , i , j );
				}
				else
				{
					for( int i = 2 ; i <= n ; ++i )
						printf( "%d %d\n" , i , j );		
				}			
			}
			for( int j = m ; j >= 1 ; --j )
				printf( "1 %d\n" , j );
		}
		else
		{
			puts( "1" );
			if( m%2 == 1 )
				printf( "%d %d 1 1\n" , n , m );
			else printf( "1 %d 1 1\n" , m );
			for( int j = 1 ; j <= m ; ++j )
			{
				if( j%2 == 0 )
				{
					for( int i = n ; i >= 1 ; --i )
						printf( "%d %d\n" , i , j );
				}
				else
				{
					for( int i = 1 ; i <= n ; ++i )
						printf( "%d %d\n" , i , j );		
				}			
			}
			puts( "1 1" );
		}
	}
}


