#include <bits/stdc++.h>
using namespace std;

#define all(v)  v.begin() , v.end()
#define pb push_back


#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;

#define N 5002

vector<int>L[N];
int deg[N], D[N], Q[N], P;
bool vis[N];

bool canReach(int forb, int k){
	
	int ct = 0, head = 0, tail = 0, u, v;
	for(int i = 0; i < P; i++){
		
		D[i] = deg[i];
		if(D[i] == 0 && i != forb)Q[tail++] = i;
	}
	
	while(head < tail && ct < k){
		
		u = Q[head++];
		ct++;
		
		for(int i = 0; i < L[u].size(); i++){
			
			v = L[u][i];
			D[v]--;
			if(D[v] == 0 && v != forb)Q[tail++] = v;
		}
	}
	
	return ct < k;
}

int main(){
	
	int A, B, E;
	while(scanf("%d%d%d%d", &A, &B, &E, &P) == 4){
		
		int u, v;
		for(int i = 0; i < P; i++){
			
			scanf("%d%d", &u, &v);
			L[u].pb(v);
			deg[v]++;
		}
		
		int ct1 = 0, ct2 = 0;
		for(int i = 0; i < E; i++)if(canReach(i, A))ct1++;
		for(int i = 0; i < E; i++)if(canReach(i, B))ct1++;
		
		scanf("%d\n%d\n%d\n", ct1, ct2, E - ct2);
		
	}
	
}
