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

#define N 6
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int A[10];
int P[] = { 10, 50, 100, 500, 1000, 5000 };

int main()
{
	while( cin >> A[0] )
	{
		for( int i = 1 ; i < N ; ++i ) cin >> A[i];
		int ind = -1 , C;
		cin >> C;
		REP( i , N )
			if( A[i] )
			{
				ind = i;
				break;
			}
		int sum = 0;
		REP( i , N )sum+= P[i]*A[i];
		int y = sum/C , x = ( sum - P[ind] + C )/C;
		cout << y - x + 1 << endl;
		for( int i = x ;  i <= y ; ++i )
			cout << i << (i==y?"\n":" ");
	}
}


