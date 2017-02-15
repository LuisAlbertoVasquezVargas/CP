#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

#define N 25

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

#define MOD 9999991

int memo[N][N];
int DP(int ct1, int ct2){
	
	if(ct1 == 0 || ct2 == 0)return 1;
	int &ret = memo[ct1][ct2];
	
	if(ret != -1)return ret;
	int ans = DP(ct1 - 1, ct2) + DP(ct1, ct2 - 1); 
	if(ans >= MOD)ans -= MOD;
	
	return ret = ans;
		
}

int L[N], R[N], sons[N];

int solve(int cur){
		
	if(cur == 0)return 1;
	int u = L[cur], v = R[cur];
	
	long long ans1 = solve(u);
	long long ans2 = solve(v);
	
	sons[cur] = 1 + sons[u] + sons[v];
	long long ans = solve(u) * solve(v);
	
	if(ans >= MOD)ans %= MOD;
	ans = ans * DP(sons[u], sons[v]);
	
	if(ans >= MOD)ans %= MOD;
	return ans;
}

void add(int cur, int x){
	
	if(x < cur){
		
		if(L[cur] == 0){
			
			L[cur] = x;
			return;
		}
		else return add(L[cur], x);
	}
	else{
		
		if(R[cur] == 0){
			
			R[cur] = x;
			return;
		}
		else return add(R[cur], x);
	}
}

int p[N];
int main(){
	
	int tc = 0;
	scanf("%d", &tc);
	
	memset(memo, -1, sizeof memo);
	
	while(tc--){
		
		int n;
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++)scanf("%d", &p[i]);
		for(int i = 0; i <= n; i++)sons[i] = 0, L[i] = R[i] = 0;
		
		for(int i = 1; i < n; i++)add(p[0], p[i]);
		int ans = solve(p[0]);
		
		printf("%d\n", ans);
			
	}
}



