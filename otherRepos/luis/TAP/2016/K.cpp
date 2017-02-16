#include <bits/stdc++.h>


#define all(v)  v.begin() , v.end()
#define pb push_back

#define N 100005
#define INF (1LL<<62)

using namespace std;

vector<int>L[N];
bool vis[N], found = false;

void getPath(int u, int pd, int target, vector<int>&path){
	
	if(vis[u] || found)return;
	vis[u] = true;
	
	path.pb(u);
	if(u == target){
		
		found = true;
		return;
	}
	
	int v;
	for(int i = 0; i < L[u].size(); i++){
		
		v = L[u][i];
		if(vis[v])continue;
		
		getPath(v, u, target, path);
		if(found)return;
	}
	
	path.pop_back();
}

long long maxi1[N], maxi2[N], res1[N], res2[N], C[N];

long long DFS(int u){
	
	vis[u] = true;
	long long ans = 0, v;
		
	for(int i = 0; i < L[u].size(); i++){
		
		v = L[u][i];
		if(vis[v] || C[v] == 0)continue;
		
		ans = max(C[v] + DFS(v), ans);
	}
	return ans;
}

int main(){
		
	int n, m, p;
	while(scanf("%d%d%d", &n, &m, &p) == 3){
		
		m--; p--;
		int u, v;
		
		for(int i = 0; i <= n; i++)L[i].clear();
		for(int i = 0; i < n; i++)scanf("%lld", &C[i]);
		
		for(int i = 0; i < n - 1; i++){
		
			scanf("%d%d", &u, &v);
			u--; v--;
			
			L[u].pb(v);
			L[v].pb(u);	
		}
		
		found = false;
		vector<int>path;
		for(int i = 0; i < n; i++)vis[i] = false;
		
		getPath(m, m, p, path);
		vector<long long>val, tree;

		for(int i = 0; i < n; i++)vis[i] = false;
		for(int i = 0; i < path.size(); i++)vis[path[i]] = true;
		
		for(int i = 0; i < path.size(); i++){
			
			u = path[i];
			tree.pb(DFS(u));
			val.pb(C[u]);
			
		}

		int len = path.size();
		long long ac = 0;
		bool emp = false;
		
		for(int i = 0; i < len; i++){
			
			if(emp){ maxi1[i] = maxi1[i - 1]; res1[i] = 0; continue; }
			if(val[i] == 0){
				
				maxi1[i] = maxi1[i - 1];
				res1[i] = 0;
				emp = true;
			}
			else{
				ac += val[i];
				res1[i] = ac + tree[i];
				if(i == 0)maxi1[i] = ac + tree[i];
				else maxi1[i] = max(maxi1[i - 1], ac + tree[i]); 	
			}
		}
		
		ac = 0;
		emp = false;
		
		for(int i = len - 1; i >= 0; i--){
			
			if(emp){ maxi2[i] = maxi2[i + 1]; res2[i] = 0; continue; }
			if(val[i] == 0){
				
				res2[i] = 0;
				maxi2[i] = maxi2[i + 1];
				emp = true;
			}
			else{
				
				ac += val[i];
				res2[i] = ac + tree[i];
				if(i == len - 1)maxi2[i] = ac + tree[i];
				else maxi2[i] = max(maxi2[i + 1], ac + tree[i]); 
			}
		}
		
		long long ans = -INF;

		for(int i = 0; i < (len + 1)/2; i++)
			ans = max(res1[i] - maxi2[i + 1], ans);
			
		for(int i = len - 1; i >= (len + 1)/2; i--)
			ans = min(maxi1[i - 1] - res2[i], ans);
			
		printf("%lld\n", ans);
		
		
	}
	
}
