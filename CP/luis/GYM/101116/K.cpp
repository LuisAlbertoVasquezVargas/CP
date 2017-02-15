#include <bits/stdc++.h>
#define N 100005
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define INF (1<<20)

using namespace std;

vector<int>L[N];
int deg[N];

int memo[N], leaf[N];
map<string, int>mapa;

int DP(int u){
	
	if(leaf[u])return 1;
	
	int &ret = memo[u];
	if(ret != -1)return ret;
	
	int ans = INF, v;
	vector<int>vec;
	
	for(int i = 0; i < L[u].size(); i++){
		
		v = L[u][i];
		vec.pb(DP(v));
	}
	
	sort(all(vec));
	int maxi = vec.back();
	int quedan = max(0, maxi - 1), add = 0, _quedan;
	
	for(int i = vec.size() - 2; i >= 0; i--){
		
		if(quedan >= vec[i])quedan--;
		else{
			
			_quedan = quedan;
			_quedan += vec[i] - quedan;
			maxi += vec[i] - quedan;
			quedan = _quedan;
			quedan--;
		}
	}
	
	if(quedan == 0)maxi++;
	return ret = maxi;
}

int main(){
	
	int mix;
	scanf("%d", &mix);
	
	string pd, s;
	int u, v, m, id = 0;
	
	for(int i = 0; i < mix; i++){
		
		cin >> pd;
		cin >> m;	
		
		if(mapa.find(pd) == mapa.end())mapa[pd] = id++;
		u = mapa[pd];
		
		for(int j = 0; j < m; j++){
			
			cin >> s;
			if(s[0] >= 'a' && s[0] <= 'z')continue;
				
			if(mapa.find(s) == mapa.end())mapa[s] = id++;
			v = mapa[s];
			
			L[u].pb(v);
			deg[v]++;
		}
	}
	
	memset(memo, -1, sizeof memo);
	
	int root;
	for(int i = 0; i < id; i++)if(L[i].size() == 0)leaf[i] = true;
	
	for(int i = 0; i < id; i++)if(deg[i] == 0)root = i;
	int ans = DP(root);

	cout << ans << endl;
}


