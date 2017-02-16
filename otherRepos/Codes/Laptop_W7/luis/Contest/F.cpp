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
#define MAXN 200010
using namespace std;

vector<int>c;
int p[MAXN],cap[MAXN];
int k=0,t;
int x,n,m;

int find(int pos){
	return lower_bound(c.begin(),c.end(),pos-t)-c.begin();	
}

int main()
{
	while(scanf("%d%d%d%d",&n,&m,&k,&t)==4){
		for(int i=0;i<n;i++)
			scanf("%d",&p[i]);
		c.clear();
		for(int i=0;i<m;i++){
			scanf("%d",&x);
			c.push_back(x);
			cap[i]=k;
		}
		sort(p,p+n);
		sort(all(c));
		int ans=0;
		int pt=0;
		for(int i=0;i<n;i++){
			
			pt=max(pt,find(p[i]));
			if(pt>=m)break;
			if(c[pt]-p[i]>t)continue;
			ans++;
			cap[pt]--;
			if(cap[pt]==0)pt++;
			
		}
		cout<<ans<<endl;
	}
}


