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

#define N 5005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)
#define B 27

using namespace std;

char S[N];
char T[10][N];
int X[10] , Y[10];
int m , nS , cnt;
int main()
{
	while( scanf( "%s" , S ) == 1 )
	{
		scanf( "%d" , &m );
		REP( i , m )scanf( "%s%d%d" , T[i] , &X[i] , &Y[i] );
		nS = strlen( S );
		vector< pair< int , unsigned int > >V( (nS*(nS+1))/2 );
		cnt = 0;
		for( int i = 0 ; i < nS ; ++i )
		{
			unsigned int H = 0;
			for( int j = i ; j < nS ; ++j )
			{
				H = H*B + S[j] - 'a' + 1;
				V[cnt++] = mp( j - i + 1 , H );
			}
		}
		sort( all(V) );
		int nV = unique( all(V) ) - V.begin();
		V.resize( nV );
		vector< vector< pair< int , unsigned int > > >W( m );
		REP( k , m )
		{
			unsigned int H = 0;
			int t = strlen( T[k] ) ;
			cnt = 0;
			W[k].resize( (t*(t+1))/2 );
			for( int i = 0 ; i < t ; ++i )
			{
				unsigned int H = 0;
				for( int j = i ; j < t ; ++j )
					H = H*B + T[k][j] - 'a' + 1 , W[k][cnt++] = mp( j - i + 1 , H );
			}
			sort( all(W[k]) ); 
		}
		int ans = 0;
		REP( i , nV )
		{
			cnt = 0 ;
			REP( j , m ) 
			{
				int temp = upper_bound( all( W[j] ), V[i] ) - lower_bound( all( W[j] ) , V[i] ) ;
				cnt += ( temp >= X[j] && temp <= Y[j] );
			}
			if( cnt == m )ans++;
		}
		printf( "%d\n" , ans );
	}
}


