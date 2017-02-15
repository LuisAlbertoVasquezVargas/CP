
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define N 500002
#define MOD 1000000007

using namespace std;

vector<int>L[N];
int memo[N][2], P[N][2];

int solve(int u, int id){
	
	if(memo[u][id] != -1)return memo[u][id];
	int ans = 0;
	
	if(id == 0){
		
		ans = 1;
		for(int i = 0; i < L[u].size(); i++){
			
			int v = L[u][i];
			ans += solve(v, 1);	
		}
	}
	else{
		
		int leaf = -1, maxi = 0, cand, aux;
		for(int i = 0; i < L[u].size(); i++){
		
			int v = L[u][i];
			ans += solve(v, 1);
			
			if(L[v].size() == 0)leaf = v;
			aux = solve(v, 0) - solve(v, 1);
			
			if(maxi < aux){
				
				maxi = aux;
				cand = v;
			}
		}
		
		if(leaf != -1)ans++;
		else{
			
			if(maxi > 0)ans += maxi, P[u][id] = cand;	
		}
	}
	return ans;
	
}


void rec(int u, int id, int flag){
	
	if(id == 0){

		if(flag)printf("%d", u);
		else printf(" %d", u);
		
		for(int i = 0; i < L[u].size(); i++){
			
			int v = L[u][i];
			rec(v, 1, 0);	
		}
	}
	else{
		
		int leaf = -1;
		for(int i = 0; i < L[u].size(); i++){
		
			int v = L[u][i];
			if(P[u][id] != v)rec(v, 1, 0);
			
			if(L[v].size() == 0)leaf = v;
		}
		
		if(leaf != -1)printf(" %d", leaf); //res[top++] = leaf;
		else{
			
			if(P[u][id] > 0){
				
			  printf(" %d", P[u][id]);	
	          rec(P[u][id], 0, 0);
			
			}
		}
	}
}
int main(){

	int tc = 0;
	scanf("%d", &tc);
	
	bool flag = false;
	while(tc--){
		
		if(flag)puts("");
		flag = true;
		
		int n, u;
		scanf("%d", &n);
		
		for(int i = 0; i <= n; i++)L[i].clear(), P[i][0] = P[i][1] = 0;
		for(int i = 2; i <= n; i++){
			
			scanf("%d", &u);
			L[u].pb(i);	
		}
		
		for(int i = 0; i <= n; i++)memo[i][0] = memo[i][1] = -1;
		
		int ans = solve(1, 0);
		
		
		printf("%d\n", ans * 1000);
		rec(1, 0, 1);

		puts("");
	}
	
	
}

