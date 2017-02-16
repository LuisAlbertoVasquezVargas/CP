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

#define N 1005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int target[12] , memo[ 12 ][ 2 ][ 305*305 ];
int K , n;

int dp( int pos ,int menor , int mod )
{
	if( pos == n )return mod == 0;
	int &dev = memo[ pos ][ menor ][ mod ];
	if( dev == -1 )
	{
		dev = 0;
		if( menor )
		{
			for( int i = 0 ; i <= 9 ; ++i )
				dev += dp( pos + 1 , 1 , (mod*10 + i)%K );
		}
		else
		{
			for( int i = 0 ; i <= target[ pos ] ; ++i )
				dev += dp( pos + 1 , i < target[ pos ] , (mod*10 + i)%K );
		}
	}
	return dev;
}
int memo2[ 2 ][ 305*305 ];
map< int , int >id;

int f( int x , int k )
{
	if( x == 0 )return 1;
	if( memo2[id[x]][k] != -1 )return memo2[id[x]][k];
	K = k , n = 0;
	while( x > 0 )
	{
		target[ n++ ] = x%10;
		x /= 10;
	}
	reverse( target , target + n );
	REP( i , 12 )REP( j , 2 )REP( u , k ) memo[i][j][u] = -1;
	return memo2[id[x]][k] = dp( 0 , 0 , 0 );
}
bool Prime[ N + 5 ];

int main()
{
	clock_t t = clock();
	clr( Prime , 1 );
	clr( memo2 , -1 );
	for( int i = 2 ; i*i <= N ; ++i )
		if( Prime[i] )
			for( int j = i*i ; j <= N ; j += i )
				Prime[ j ] = false;
	int a , b ,k;
	scanf( "%d%d%d" , &a , &b , &k );
	id[a] = 0 , id[b] = 1;
	int ans = 0 ;
	for( int i = 2 ; i <= k + 1 ; ++i )
	{
		if( !Prime[i] )continue;
		int F = f( a + b , i ) , I = f( a , i );
		//cout << i << " " << F - I << endl;
		if( i == 2 )
			ans += F - I;
		else
		{
			ans += F - I;
			for( int j = i - 1 ; j >= 2 ; --j )
				if( Prime[j] )
				{
					F = f( a + b , j*i ) , I = f( a , j*i );
					ans -= F - I;
				}
		}
	}
	t = clock() - t;
  	printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
	printf( "%d\n" , b - ans );
}


