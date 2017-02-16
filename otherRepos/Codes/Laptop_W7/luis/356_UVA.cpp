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

using namespace std;

int main()
{
	int n;
	bool ok = 0;
	while( sc( n ) == 1 )
	{
		if( ok )puts( "" );
		else ok = 1;
		int ct1 = 0 , ct2 = 0;
		//int R2 = (2*n - 1)/2;
		for( int i = -n ; i < n ; ++i )
			for( int j = -n ; j < n ; ++j )
			{
				int D1 = i*i + j*j;
				int D2 = (i+1)*(i+1) + j*j;
				int D3 = i*i + (j+1)*(j+1);
				int D4 = (i+1)*(i+1) + (j+1)*(j+1);
				int P[ 4 ] = { D1 , D2 , D3 , D4 };
				sort( P , P + 4 );
				if( n*n - n + 0.25 > P[3] )ct2++;
				if( n*n - n + 0.25 < P[3] && n*n - n + 0.25 > P[0] )ct1++;
			}
		printf( "In the case n = %d, %d cells contain segments of the circle.\n" , n , ct1 ); 
		printf( "There are %d cells completely contained in the circle.\n" , ct2 );
	}
}


