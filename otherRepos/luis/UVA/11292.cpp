#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;

vi read(int n){
	vi x(n);
	REP(i , n) scanf("%d" , &x[i]);
	sort(all(x));
	return x;
}
int main(){
	int heads , knights;
	while(scanf("%d%d" , &heads , &knights) == 2){
		if(heads == 0 && knights == 0) break;
		vi H = read(heads);
		vi K = read(knights);
		int pos = 0 , ans = 0;
		REP(i , heads){
			auto begin = K.begin() + pos;
			auto end = K.end();
			pos = lower_bound(begin , end, H[i]) - K.begin();
			if(pos >= knights){
				ans = -1;
				break;
			}
			ans += K[ pos ];
			pos ++;
		}
		if(ans == -1) puts("Loowater is doomed!");
		else printf("%d\n" , ans);
	}
}


