#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define mp make_pair
#define fi first
#define se second

#define pb push_back
#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef vector< int > vi;

int main(){
	int cases;
	scanf("%d" , &cases);
	REP(tc , cases){
		int L , n;
		scanf("%d%d" , &L , &n);
		int maxi = INT_MIN , mini = INT_MIN;
		REP(i , n){
			int x;
			scanf("%d" , &x);
			mini = max(mini , min(x , L - x));
			maxi = max(maxi , max(x , L - x));
		}
		printf("%d %d\n" , mini , maxi);
	}
}



