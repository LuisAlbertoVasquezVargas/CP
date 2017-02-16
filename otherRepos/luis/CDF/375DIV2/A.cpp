#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; ++i)
#define SZ(v) ((int)v.size())
#define pb push_back

typedef vector<int> vi;

int main(){
	vi A(3);
	while(cin>>A[0]){
		REP(i,3){
			if(!i)continue;
			cin>>A[i];
		}
		int best=INT_MAX;
		for(int k=1;k<=100;k++){
			int cur=0;
			REP(i,3)cur+=abs(k-A[i]);
			best=min(best,cur);
		}
		cout<<best<<'\n';
	}
}


