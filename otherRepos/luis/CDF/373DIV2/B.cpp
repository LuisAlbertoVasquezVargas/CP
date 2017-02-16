#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(T,val) memset(T,val,sizeof(T))

#define SZ(v) ((int)v.size())
#define pb push_back
#define all(v) v.begin(),v.end()

#define fi first
#define se second
#define mp make_pair

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

const int N = 1e5;
char S[N + 5];
int get(int n, int start){
	vi cnt(2);
	REP(i,n)
		if( (start ^ (i & 1)) != S[i] ) cnt[S[i]]++;
	return max(cnt[0],cnt[1]);
}
int main(){
	int n;
	while(scanf("%d" , &n) == 1){
		scanf("%s" , S);
		REP(i,n) S[i] = (S[i] == 'b'? 0 : 1);
		int ans = min(get(n , 0) , get(n , 1));
		printf("%d\n" , ans);
	}
}




