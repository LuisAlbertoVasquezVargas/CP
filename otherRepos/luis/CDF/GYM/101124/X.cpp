#include<bits/stdc++.h>
#define N 100005
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()

using namespace std;

vector<int>L[N], G[N];
bool vis[N];

int DFS(int u){
	
	if(vis[u])return 0;
	vis[u] = true;
	
	int v, ans = 1;
	for(int i = 0; i < L[u].size(); i++){
		
		v = L[u][i];
		if(vis[v])continue;
		
		G[u].pb(v);
		G[v].pb(u);
		ans += DFS(v);
	}
	
	return ans;
}

int sons[N], Q[N];
map<pair<int, int>, int >mapa;
#define cout2(x, y) cout << x << " " << y << endl

int main(){
	
	int n, m;
	scanf("%d%d", &n, &m);
	
	int u, v;
	for(int i = 0; i < m; i++){
		
		scanf("%d%d", &u, &v);
		u--; v--;
		
		L[u].pb(v);
		L[v].pb(u);
	}
	
	bool ok = true;
	for(int i = 0; i < n && ok; i++){
			
		if(vis[i])continue;
		if(DFS(i)&1)ok = false;
	}
	
	int head = 0, tail = 0;
	memset(vis, false, sizeof vis);
	
	for(int i = 0; i < n; i++){
		
		if(G[i].size() == 1){
			
			Q[tail++] = i;
			sons[i] = 0;
			//cout << i << endl;
		}
	}
	
	int pd;
	while(head < tail){
		
		u = Q[head++];
		if(vis[u])continue;
		
		vis[u] = true;
		for(int i = 0; i < G[u].size(); i++){
			
			v = G[u][i];
			if(vis[v])continue;
			
			pd = v;	
			sons[v]++;
			Q[tail++] = v;
		}
		
		if(sons[u]&1){
			
			mapa[make_pair(min(u, pd), max(u, pd))] = true;
			sons[pd]--;
		}
		
	}
		
	vector<pair<int, int> >ans;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < G[i].size(); j++){
			
			u = min(i, G[i][j]);
			v = max(i, G[i][j]);
			if(mapa.find(make_pair(u, v)) != mapa.end())continue;
			mapa[make_pair(u, v)] = true;
			ans.pb(make_pair(u, v));
		}
	}
	
	if(!ok)puts("-1");
	else{
		
		int len = ans.size();
		printf("%d\n", len);
		
		for(int i = 0; i < ans.size(); i++)	
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}
	
}
