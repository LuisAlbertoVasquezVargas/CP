#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define N 1340

using namespace std;

double p[N];
bool vis[N][N];
long double memo[N][N];

long double DP(int pos, int goods){
	
	if(goods > pos)return 0;
	if(pos == 0)return 1;
	
	long double &ret = memo[pos][goods];
	
	if(vis[pos][goods])return ret;
	vis[pos][goods] = true;
	
	ret = (1 - p[pos]) * DP(pos - 1, goods);
	if(goods > 0)ret += p[pos] * DP(pos - 1, goods - 1);
	
	return ret;
}


int main(){

	int n;
	while(scanf("%d", &n) == 1){
	
		for(int i = 1; i <= n; i++){
		
			scanf("%lf", &p[i]);
			p[i] /= 100.0;
		}
		
		sort(p + 1, p + n + 1);
		reverse(p + 1, p + n + 1);
		
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)vis[i][j] = false;
			
		long double ans = 0, aux;
		for(int i = 1; i <= n; i += 2){
			
			aux = 0;
			for(int j = (i + 1)/2; j <= i; j++)aux += DP(i, j);
			if(ans < aux)ans = aux;
		}
		printf("%.5lf\n", double(ans));
	}

}
