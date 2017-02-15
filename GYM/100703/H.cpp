
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

vector<int>L[N];
int des[N], childs[N], low[N], maxi[N], timer, n;
bool p[N];

void DFS(int u, int pd){
	
	low[u] = des[u] = timer++;
	int sons = 0; childs[u] = 1;
	maxi[u] = 0;
	
	for(int i = 0; i < L[u].size(); i++){
		
		int v = L[u][i];
		if(v == pd)continue;
		
		if(des[v] == -1){
			
			DFS(v, u);
			childs[u] += childs[v]; sons++;
			maxi[u] = max(maxi[u], childs[v]);
			
			low[u] = min(low[u], low[v]);
			if(low[v] >= des[u])p[u] = true;
		}
		else low[u] = min(low[u], des[v]);
	}
	
	if(pd == -1 && sons <= 1)p[u] = false;
	maxi[u] = max(maxi[u], n - childs[u]);
	
}


int main(){

	int m;
	while(cin>>n>>m){
		
		for(int i = 0; i < n; i++)L[i].clear(), childs[i] = 0;
		int u, v;
		
		for(int i = 0; i < m; i++){
		
			scanf("%d%d", &u, &v);
			u--, v--;
			
			L[u].pb(v);
			L[v].pb(u);
		}	
		
		for(int i = 0; i < n; i++)des[i] = -1, p[i] = false;
		timer = 0;
		
		DFS(0, -1);
		int node = 0, cant = n; //mojados
		
		for(int i = 0; i < n; i++){
			
			if(!p[i])continue;
			if(maxi[i] < cant){
				
				cant = maxi[i];
				node = i;
				
			}	
		}
		
		printf("%d\n", node + 1);
		
	}


}

