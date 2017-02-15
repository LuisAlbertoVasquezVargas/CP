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

typedef pair<int , int> pii;
typedef vector<pii> vpii;
typedef vector< int > vi;
typedef vector<vi> vvi;
typedef vector< string > vs;

const int N = (int)1e6 + 5;
int F[ N + 5 ];
bool f(int L , vpii vec , int tope , vvi &ans){
	priority_queue<pii>Q(all(vec));
	vvi T;
	while(!Q.empty()){
		vi v;
		vpii temp;
		REP(k,L){
			if(Q.empty())break;
			pii x = Q.top();
			Q.pop();
			v.pb(x.se);
			if(x.fi > 1)
				temp.pb(mp(x.fi - 1,x.se));
		}
		for(auto p : temp) Q.push(p);
		T.pb(v);
	}
	ans = T;
	return SZ(T) == tope;
}
void impr(vi &v){
	REP( i , SZ( v ) ) printf("%d%c" , v[ i ] , (i + 1 == SZ(v)? 10 : 32));
}
int main(){
	int n;
	while(scanf("%d" , &n) == 1){
		if(!n) break;
		clr(F , 0);
		int maxFreq = 0;
		REP(i , n){
			int x;
			scanf("%d" , &x);
			F[ x ]++;
			maxFreq = max(maxFreq , F[ x ]);
		}
		vpii vec;
		REP(i , N)
			if(F[ i ]) vec.pb( mp(F[ i ] , i) );
		int lo = 1 , hi = SZ(vec);
		vvi ans;
		if( f(lo , vec , maxFreq , ans) ){
			printf("%d\n" , maxFreq);
			continue;
		}
		while(hi - lo > 1){
			int med = (lo + hi) >> 1;
			if( f(med , vec , maxFreq , ans) ) hi = med;
			else lo = med;
		}
		f(hi, vec , maxFreq ,ans);
		printf("%d\n" , maxFreq);
		for(auto v : ans) impr(v);
	}
}




