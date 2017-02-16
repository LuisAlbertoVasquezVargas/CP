#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
	int cases;
	scanf("%d" , &cases);
	REP(tc , cases){
		int n;
		scanf("%d" , &n);
		vi v(n);
		REP(i , n)scanf("%d" , &v[i]);
		sort(all(v));
		reverse(all(v));
		int ans = 0;
		REP(i , n){
			if(i + 2 < n)ans += v[i + 2];
			i += 2;
		}
		printf("%d\n" , ans);
	}
}



