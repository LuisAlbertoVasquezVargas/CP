#include <bits/stdc++.h>

#define ll long long
#define REP(i,n) for(int i=0;i<(n);i++)

#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )

#define N 1000005

using namespace std;

int prime[ N + 1 ];
ll A[N+1];

int main()
{
	clr( prime , -1 );
	for( int i = 2 ; i*i <= N ; ++i	)
		if( prime[i] == -1 )
			for( int j = i*i ; j <= N ; j += i )
				prime[j] = i;

	for( int i = 2 ; i <= N ; ++i )
	{
		int p = i;
		if( prime[p] == -1 )
		{
			A[i] = A[i-1] + 1;
			continue;
		}
		ll ans = 1 , temp ;
		while( prime[p] != -1 )
		{
			temp = 1;
			int d = prime[p] , cnt = 0;
			while( p%d == 0 )
				temp*=d , p/= d,cnt++;
			temp*=d; temp--;
			temp/=(d-1);
			ans *= temp; 
		}
		if( p != 1 ) ans *= (p+1);
		A[i] = A[i-1] + ans - i;
	}
	int tc , n;
	sc( tc );
	REP( t , tc )
	{
		sc( n );
		printf( "%lld\n" , A[n] );
	}
}



