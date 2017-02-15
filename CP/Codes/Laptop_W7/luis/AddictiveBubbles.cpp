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

int n,m,c,C[12];
int T[12][12];
int main()
{
	freopen("addictive.in", "r", stdin);
	freopen("addictive.out", "w", stdout);
	scanf("%d%d%d",&n,&m,&c);
	for(int i=0;i<c;i++)
		scanf("%d",&C[i]);
	int k=0;
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(!C[k]){
				T[i][j]=++k;
				C[k]--;
			}
			else{
				T[i][j]=k;
				C[k]--;		
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			printf("%d",T[i][j]+1);
		puts("");
	}
}


