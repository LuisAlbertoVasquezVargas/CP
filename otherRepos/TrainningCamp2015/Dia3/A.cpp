#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define N 202
#define M 100002
#define MOD 1000000007

using namespace std;

int k[N], n;
int memo[2][M];
/*
int DP(int pos, int sum1, int sum2){
	
	if(pos == n)return 1;
	int &ret = memo[pos][sum1];
	
	if(ret != -1)return ret;
	int ans = 0;
	
	if(sum1 >= k[pos])ans += DP(pos + 1, sum1 - k[pos], sum2);

	if(sum2 >= k[pos])ans += DP(pos + 1, sum1, sum2 - k[pos]);
	if(ans >= MOD)ans -= MOD;
	
	if((k[pos]&1) == 0 && sum1 >= k[pos]/2 && sum2 >= k[pos]/2)ans += DP(pos + 1, sum1 - k[pos]/2, sum2 - k[pos]/2);
	
	if(ans >= MOD)ans -= MOD;
	return ret =ans;	
}
*/

int main(){
	
	int s1, s2;
	while(scanf("%d%d", &s1, &s2) == 2){
		
		if(s1 > s2)swap(s1, s2);
		scanf("%d", &n);
		
		for(int i = 1; i <= n; i++)scanf("%d", &k[i]);	
		
		memo[0][0] = 1;
		int ac = 0;
		
		for(int i = 1; i <= n; i++){
			
			ac += k[i];
			for(int j = 0, l; j <= min(ac, s1); j++){
				
				l = ac - j;
				memo[i&1][j] = 0;
				if(j >= k[i])memo[i&1][j] += memo[(i - 1)&1][j - k[i]];
				
				if(l >= k[i])memo[i&1][j] += memo[(i - 1)&1][j];
				if(memo[i&1][j] >= MOD)memo[i&1][j] -= MOD;
				
				if((k[i]&1) == 0 && j >= k[i]/2 && l >= k[i]/2)memo[i&1][j] += memo[(i - 1)&1][j - k[i]/2];
				if(memo[i&1][j] >= MOD)memo[i&1][j] -= MOD;
				
			}
		}
	
		printf("%d\n", memo[n&1][s1]);
		
	}
	
	
	
}

