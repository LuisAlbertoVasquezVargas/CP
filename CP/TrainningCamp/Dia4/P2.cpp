#include<bits/stdc++.h>
#define all(x) x.begin(), x-end()
#define pb(x) push_back(x)
#define N 20

using namespace std;

int solve(string &s1, string &s2){
	
	int ans = 0;
	for(int i = 0; i < s1.size(); i++){
		
		if(s1[i] == s2[i])continue;
		for(int j = i + 1; j < s1.size(); j++){
			if(s1[i] != s1[j]){
				
				ans += j - i, swap(s1[i], s1[j]);
				break;
			}
		}
	}	
	return ans;
}

int f[N];
int main(){
	
	int n, m, x;
	while(scanf("%d%d", &n, &m) == 2){
		
		string s = "", t1 ="" , t2 = "";
		int zeros = 0;
		
		for(int i = 0; i < n; i++){
		
			scanf("%d", &x);
			if(x == 0)zeros++;
			s += char('0' + x);
		}
		
		for(int i = 0; i < m; i++){
			
			scanf("%d", &f[i]);
			if(i&1)for(int j = 0; j < f[i]; j++)t1 += char('0'), t2 += char('1');
			else for(int j = 0; j < f[i]; j++)t1 += char('1'), t2 += char('0');
		}	
		
		int ans = (1<<30), ct = 0;
		
		for(int i = 0; i < n; i++)if(t1[i] == '0')ct++;
		if(ct == zeros)ans = min(ans, solve(s, t1));
		
		ct = 0;
		for(int i = 0; i < n; i++)if(t2[i] == '0')ct++;
		
		if(ct == zeros)ans = min(ans, solve(s, t2));
		printf("%d\n", ans);
	}
	
}
