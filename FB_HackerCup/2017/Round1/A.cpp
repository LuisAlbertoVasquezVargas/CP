#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vi get(vi &v,int n){
	vi AC(n+1);
	sort(all(v));
	REP(i,n)AC[i+1]=AC[i]+v[i];
	return AC;
}
const int MAXN=300,MAXM=300;
const int INF=INT_MAX/2;
int n,m;
bool used[MAXN+1][MAXM+1];
ll memo[MAXN+1][MAXM+1];
vvi T;
ll dp(int pos,int cur){
	if(pos==n)return 0;
	if(used[pos][cur])return memo[pos][cur];
	used[pos][cur]=1;
	ll &ans=memo[pos][cur]=INF;
	REP(k,m+1){
		if(cur+k>=1)
			ans=min(ans,(ll)T[pos][k]+(ll)k*k+dp(pos+1,min(cur-1+k,n)));
	}
	return ans;
}
void init(){
	T.clear();
	clr(used,0);
}
int main(){
	int cases;
	scanf("%d",&cases);
	REP(tc,cases){
		scanf("%d%d",&n,&m);
		init();
		REP(i,n){
			vi v(m);
			REP(j,m)scanf("%d",&v[j]);
			T.pb(get(v,m));
		}
		cout<<"Case #"<<tc+1<<": "<<dp(0,0)<<'\n';
	}
}

