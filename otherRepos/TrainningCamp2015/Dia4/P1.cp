#include<bits/stdc++.h>
#define all(x) x.begin(), x-end()
#define pb(x) push_back(x)
#define N 250005

using namespace std;

struct node{
	
	int id, dis;
	node(){}
	node(int _id, int _dis){ id = _id; dis = _dis; }	
};
vector<int>L[N], W[N];

bool operator <(const node &n1, const node &n2){
	return n1.dis > n2.dis;
}

int D[2][N], n;
int Dijkstra(int source, int id){
	
	memset(D[id], -1, sizeof(int) * n);
	D[id][source] = 0;
	
	priority_queue<node>Q;
	Q.push(node(source, 0));
	
	while(!Q.empty()){
	
		node u = Q.top();
		Q.pop();
		
		for(int i = 0; i < L[u.id].size(); i++){
			
			int v = L[u.id][i];
			int w = W[u.id][i];
			
			if(D[id][v] == -1 || D[id][v] > D[id][u.id] + w){
				
				D[id][v] = D[id][u.id] + w;
				Q.push(node(v, D[id][v]));	
			}
		}
	}
	return D[id][n - 1];
}

pair<int, int> edges[N];
int weight[N], m;

int solve(int dis){
	
	int u, v, w, ans = 0;
	for(int i = 0; i < m; i++){
		
		u = edges[i].first;
		v = edges[i].second;
		w = weight[i];
		
		if(D[0][u] + w + D[1][v] == dis)ans += w;
		else{
			swap(u, v);
			if(D[0][u] + w + D[1][v] == dis)ans += w;
		}
	}
	return 2 * ans;
}
int main(){
	
	while(scanf("%d%d", &n, &m) == 2){
		
		int u, v, w;
		for(int i = 0; i <= n; i++)L[i].clear(), W[i].clear();
		for(int i = 0; i < m; i++){
			
			scanf("%d%d%d", &u, &v, &w);	
			edges[i] = make_pair(u, v);
			
			weight[i] = w;
			L[u].pb(v);
			L[v].pb(u);
			
			W[u].pb(w);
			W[v].pb(w);
		}
		
		int dis = Dijkstra(0, 0);
		Dijkstra(n - 1, 1);
		
		int ans = solve(dis);
		printf("%d\n", ans);
		
		
	}
	
}
