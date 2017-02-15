#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < (n); ++i)

#define all(v) v.begin(),v.end()

const int N = 1e5;
char S[N + 5];

int main(){
	while(scanf("%s" , S) == 1){
		int n = strlen(S);
		if(n & 1){
			puts("-1");
			continue;
		}
		vector<int>F(256);
		REP(i,n)F[S[i]]++;
		
		int ans = 0;
		ans += abs(F['U'] - F['D']);
		ans += abs(F['L'] - F['R']);
		
		printf("%d\n",ans >> 1);
	}	
}


