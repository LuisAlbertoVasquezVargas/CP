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
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;

int main()
{
	sync
	while( cin >> n )
	{
		vll V( n );
		REP( i , n ) cin >> V[i];
		sort( all( V ) );
		n = unique( all( V ) ) - V.begin();
		V.resize( n );
		if( n == 2 )
		{
			ll i = V[0] , j = V[1] ;
			if( i > j )swap( i , j );
			double ans;
			if( i > 0 && j > 0 )ans = 1.0*j/i;
			else if( i < 0 && j < 0 )ans = 1.0*i/j;
			else ans = -1.0*min( abs(i) , abs(j) )/max( abs(i) , abs(j) );
			printf( "%.10lf\n" , ans );
			continue;
		}
		if( V[0]*V[n-1] < 0 )
		{
			puts("0");
			continue;
		}
		if( V[0] < 0 )reverse( all(V) );
		vll A( n , 1 ) , B( n , 1 );
		ll a = 0 , b = 0 ;
		for( int i = 1 ; i < n ; ++i )
		{
			ll g = __gcd( V[i] , V[0] );
			//cout << " g :" << g << endl;
			A[i] = V[i]/g;
			B[i] = V[0]/g;
			a = __gcd( A[i] , a );
			b = __gcd( B[i] , b );
		}
		//REP( i , n )cout << A[i] << " " << B[i] << endl;
		//cout << a << " " << b << endl;
		double loga = log( 1.0*a/b );
		bool solve = 1;
		for( int i = 1 ; i < n ; ++i )
		{
			double t = log( 1.0*A[i]/B[i] )/loga;
			if( abs( (ll)(t + EPS) - t) > EPS )solve = 0;
		}
		if( solve )
			printf( "%.10lf\n" , 1.0*a/b );
		else puts( "0" );
	}
}


