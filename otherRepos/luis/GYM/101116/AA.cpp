#include <bits/stdc++.h>
#define N 105
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()

using namespace std;

vector<int>L[N];
int m, k;

struct node{
	
	vector<int>pos;
	int sum;
	//long long h;
	node(){}
	node(int _sum, vector<int>_pos)	{sum = _sum; pos = _pos; }
};

bool operator <(const node &n1, const node &n2){
	
	//if(n1.sum != n2.sum)
	return n1.sum > n2.sum;
	//return n1.h > n2.h;
}

map<vector<int>, int>mapa;

void Dijkstra(node source){
	
	vector<int>ans;
	mapa.clear();
	
	mapa[source.pos] = 0;
	priority_queue<node>Q;
	
	Q.push(source);
	node best;
	long long nsum;
	
	for(int it = 0; it < k; it++){
		
		best = Q.top();
		Q.pop();
		ans.pb(best.sum);
		
		for(int i = 0; i < m; i++){ //adelante
			
			if(best.pos[i] == L[i].size() - 1)continue;
			nsum = best.sum - L[i][best.pos[i]];
			
			best.pos[i]++;
			nsum += L[i][best.pos[i]];
			
			if(mapa.find(best.pos) == mapa.end() || mapa[best.pos] > nsum){
				
				mapa[best.pos] = nsum;
				Q.push(node(nsum, best.pos));	
			}
			best.pos[i]--;
		}
		
		for(int i = 0; i < m; i++){ //adelante
			
			if(best.pos[i] == 0)continue;
			nsum = best.sum - L[i][best.pos[i]];
			
			best.pos[i]--;
			nsum += L[i][best.pos[i]];
			
			if(mapa.find(best.pos) == mapa.end() || mapa[best.pos] > nsum){
				
				mapa[best.pos] = nsum;
				Q.push(node(nsum, best.pos));	
			}
			best.pos[i]++;
		}
	}
	
	for(int i = 0; i < ans.size(); i++){
		
		if(i)printf(" ");
		printf("%d", ans[i]);		
	}
	puts("");
}

int main(){
	
	int tc = 0;
	scanf("%d", &tc);
	
	while(tc--){
		
		scanf("%d%d", &m, &k);
		
		for(int i = 0; i <= m; i++)L[i].clear();
		
		int n, x;
		for(int i = 0; i < m; i++){
			
			scanf("%d", &n);
			for(int j = 0; j < n; j++){
				
				scanf("%d", &x);
				L[i].pb(x);
			}
			sort(all(L[i]));
		}
		
		node source;
		source.sum = 0;
		
		for(int i = 0; i < m; i++)source.pos.pb(0), source.sum += L[i][0];
		
		//cout << source.sum << endl;
		Dijkstra(source);
	}
}
