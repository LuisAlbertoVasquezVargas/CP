#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define pb push_back
#define SZ(v) ((int)v.size())
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<int> vi;

void safeInsert(set<int> &SET,int x){
	if(x >= 1) SET.insert(x);
}
void safeErase(set<int> &SET,int x){
	if(x >= 1) SET.erase(x);
}
void init(set<int> &SET,set<int> &SET_MOVE,vi &a,int n){
	SET=set<int>(all(a));
	for(auto x : a){
		if(x > 1 && !SET.count(x >> 1))safeInsert(SET_MOVE,x);
	}
}

int main(){
	int n;
	while(scanf("%d",&n) == 1){
		vi A(n);
		REP(i,n) scanf("%d",&A[i]);
		set<int> SET,SET_MOVE;
		init(SET,SET_MOVE,A,n);
		while(1){
			if(SET_MOVE.empty()) break;
			int x = *(SET_MOVE.begin());
			safeErase(SET,x);
			safeInsert(SET,x >> 1);
			
			safeErase(SET_MOVE,x);
			REP(i,2)
				if(SET.count((x << 1) + i)) safeInsert(SET_MOVE,(x << 1) + i);
			if(SET.count(x ^ 1)) safeErase(SET_MOVE,(x ^ 1));
			
			for(auto cur : SET) cout << cur << " ";
			cout << endl;
			for(auto cur : SET_MOVE) cout << cur << " ";
			cout << endl;
			cout << "**\n";
		}
		puts("result");
		A = vi(all(SET));
		REP(k,SZ(A)) printf("%d%c" , A[k] , (k + 1 == SZ(A)? 10 : 32));
	}
}



