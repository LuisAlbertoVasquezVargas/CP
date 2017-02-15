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

#define N 7
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int a[10];

int main()
{
	while( cin >> a[0] )
	{
		for( int i = 1 ; i < N ; ++i ) cin >> a[i];
		vi V(N);
		while( 1 )
		{
			//cout << accumulate( all(V) , 0 ) << endl;
			if( accumulate( all(V) , 0 ) >=6 )break;
			if( (a[1] + a[2] + a[3])%2 == a[4] )
				V[1] = V[2] = V[3] = V[4] = 1;
			else if( (a[0] + a[2] + a[3])%2 == a[5] )
				V[0] = V[2] = V[3] = V[5] = 1;
			else if( (a[0] + a[1] + a[3])%2 == a[6] )
				V[0] = V[1] = V[3] = V[6] = 1;	
			else if( (a[4] + a[5] + a[6])%2 == a[3] )
				V[4] = V[5] = V[6] = V[3] = 1;
			else V[3] = 1, a[3]^=1;			
		}
		REP( i , N ) 
			cout << (V[i]^a[i]) << (i+1==N?"\n":" "); 
	}
}


