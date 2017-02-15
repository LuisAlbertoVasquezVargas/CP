#include <bits/stdc++.h>
using namespace std;

#define all(v)  v.begin() , v.end()
#define pb push_back


#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl

#define N 5002

vector<int>L[N], G[N];
int deg[N], D[N], E;

bool canReach(int forb, int k){
	
	int ct = 0, u, v;
	queue<int>Q;
	
	for(int i = 0; i < E; i++){
		
		D[i] = deg[i];
		if(D[i] == 0 && i != forb)Q.push(i);
	}
	
	while(!Q.empty()){
		
		u = Q.front();
		Q.pop();
		
		ct++;
		if(ct == k)return false;
		
		for(int i = 0; i < L[u].size(); i++){
			
			v = L[u][i];
			if(D[v] == 0 || v == forb)continue;
			
			D[v]--;
			if(D[v] == 0)Q.push(v);
		}
	}
	
	return true;
}

bool vis[N];
int pila[N], top = 0;

void DFS(int u){
	
	if(vis[u])return;
	
	vis[u] = true;
	pila[top++] = u;
	
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(vis[v])continue;
		DFS(v);
	}
}

int main(){
	
	int A, B, P;
	while(scanf("%d%d%d%d", &A, &B, &E, &P) == 4){
		
		int u, v;
		for(int i = 0; i < E; i++)L[i].clear(), deg[i] = 0, G[i].clear();
		for(int i = 0; i < P; i++){
			
			scanf("%d%d", &u, &v);
			L[u].pb(v);
			G[v].pb(u);
			deg[v]++;
		}
		
		int ct1 = 0, ct2 = 0, ct3 = 0;
		for(int i = 0; i < E; i++)if(canReach(i, A))ct1++;
		for(int i = 0; i < E; i++)if(canReach(i, B))ct2++;
		
		for(int i = 0; i < E; i++){
			
			for(int j = 0; j < top; j++)vis[pila[j]] = false;
			top = 0;
			DFS(i);
			//DEBUG2(i, top);
			if(top > B)ct3++;		
		}
		printf("%d\n%d\n%d\n", ct1, ct2, ct3);
		
	}
	
}
