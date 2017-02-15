#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
	int n;
	while(scanf("%d" , &n) == 1){
		if(!n) break;
		vi v;
		REP(i , n){
			int x;
			scanf("%d" , &x);
			if(x > 0) v.pb(x);
		}
		if(!SZ(v)) v.pb(0);
		REP(i , SZ(v)) printf("%d%c" , v[ i ] , (i + 1 == SZ(v)? 10 : 32));
	}
}





