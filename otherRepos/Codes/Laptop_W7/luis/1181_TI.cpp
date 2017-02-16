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

int n;
int tree[ 2*N + 5 ];

int read(int idx){
     int sum = 0;
     while (idx > 0){
          sum += tree[idx];
          idx -= (idx & -idx);
     }
     return sum;
}
void update(int idx ,int val){
     while (idx <= 2*N ){
          tree[idx] += val;
          idx += (idx & -idx);
     }
}
int f( int k )
{
	int lo = 0 , hi = n - 1;
	if( read( lo + 1 ) == k + 1 )return 0;
	while( hi - lo > 1 )
	{
		int med = ( lo + hi )/2;
		if( read( med + 1 ) < k + 1 )
			lo = med;
		else hi = med;
	}
	return hi;
}
char s[ N ];

int main()
{
	scanf( "%d%s" , &n , s );
	printf( "%d\n" , n - 3 );
	int m = n;
	REP( i , n ) update( i + 1 , 1 );
	while( 1 )
	{
		if( m == 3 )break;
		for( int i = 0 ; i < m ; ++i )
		{
			int x = f(i%m) , y = f((i+1)%m) , z = f((i+2)%m);
			
			char a = s[x];
			char b = s[y];
			char c = s[z];
			if( a != b && a != c && b != c )
			{
				printf( "%d %d\n" , x + 1 , z + 1 );
				update( y + 1 , -1 );
				m--;
				break;
			}
		}
	}
}


