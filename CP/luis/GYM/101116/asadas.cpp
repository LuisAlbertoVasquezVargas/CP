#include <bits/stdc++.h>
#define N 405
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()

using namespace std;

vector<int>L[N];
int m, k;

int count(int sum){
	
	int ans = 0;
	for(int i = 0; i < L[0].size(); i++){
		
		if(L[0][i] > sum)break;
		ans += upper_bound(all(L[1]), sum - L[0][i]) - L[1].begin();
	}
	return ans;
}

int getKth(int kth){
	
	int lo = 0, hi = 2000000, me;
	while(lo < hi){
		
		me = lo + (hi - lo)/2;
		if(count(me) < kth)me = lo + 1;
		else hi = me;
	}
	return lo;
}

void solve2(){
	
	for(int i = 0; i < k; i++){
		
		if(i)printf(" ");
		printf("%d", getKth(i + 1));
	}
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
		
		if(m == 1){
			
			for(int i = 0; i < k; i++){
				
				if(i)printf(" ");
				printf("%d", L[0][i]);
			}		
		}
		else{
			
			if(m == 2)solve2();
			else{
				
				
			}
		}
		puts("");
	}
	
}
