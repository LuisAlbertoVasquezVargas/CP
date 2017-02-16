#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define INF (1LL<<62)

using namespace std;

int main(){
	
	long long n, r, p;
	while(scanf("%lld%lld%lld", &n, &r, &p) == 3){
		
		int po = 0, cur = 1;
		while(cur < n)cur *= 2, po++;
		
		long long ans = INF;
		if(n == 1)ans = 0;
		
		for(int i = 1; i <= po; i++){
		
			if((1LL<<i) >= n)ans = min(ans, i * (r + p));
			else{
				
				ans = min(ans, ((n - 1)/(1LL<<(i - 1))) * p + (i - 1) * (p + r) + r);
			}
		}
		
		for(int i = 1; i <= po; i++){
		
			for(int j = )
			if((1LL<<i) >= n)ans = min(ans, i * (r + p));
			else{
				
				ans = min(ans, ((n - 1)/(1LL<<(i - 1))) * p + (i - 1) * (p + r) + r);
			}
		}
		
		printf("%lld\n", ans);
	}
	
}
