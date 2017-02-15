#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0 ; i < n ; ++i)

#define all(v) v.begin(),v.end()

int main(){
	int n;
	while(scanf("%d" , &n) == 1){
		set<int> SET;
		REP(i , n){
			int x;
			scanf("%d" , &x);
			SET.insert(x);
		}
		if((int)SET.size() == 3){
			vector<int>v(all(SET));
			puts(v[0] + v[2] == 2 * v[1] ? "YES" : "NO");
			continue;
		}
		puts((int)SET.size() <= 3 ? "YES" : "NO");
	}
}


