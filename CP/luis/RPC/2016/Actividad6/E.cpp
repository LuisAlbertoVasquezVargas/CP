#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define N 105

using namespace std;

long long cur[N], add[N];
vector<int>L[N];

int main(){

	int n, m, s, t ,u, v;
	while(scanf("%d%d%d%d", &n, &m, &s, &t) == 4){
	
		for(int i = 0; i <= n; i++)L[i].clear();
		
		for(int i = 0; i < m; i++){
			
			scanf("%d%d", &u, &v);
			L[u].pb(v);
			L[v].pb(u);
		}
		
		memset(cur, 0, sizeof cur);
		cur[s] = 1;
		
		long long last = 0;
		for(int i = 0; i < t; i++){
		
			memset(add, 0, sizeof add);
			last = 0;
			
			for(int j = 0; j < n; j++){
				for(int k = 0; k < L[j].size(); k++){
					
					add[L[j][k]] += cur[j];
				}
			}
			for(int j = 0; j < n; j++){
				cur[j] = add[j];
				last += add[j];
			}
		}
		
		//long long ans = 0;
		//for(int i = 0; i < n; i++)ans += cur[i];
		printf("%lld\n", last);
	
	}

}



