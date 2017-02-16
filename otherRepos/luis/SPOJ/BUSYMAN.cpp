#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) v.begin(),v.end()

#define fi first
#define se second

typedef pair<int,int>pii;
typedef vector<pii> vpii;
bool cmp(const pii &a,const pii &b){
	return a.se<b.se;
}
int main(){
	int cases;
	scanf("%d",&cases);
	REP(tc,cases){
		int n;
		scanf("%d",&n);
		vpii v;
		REP(i,n){
			int x,y;
			scanf("%d%d",&x,&y);
			v.pb({x,y});
		}
		sort(all(v),cmp);
		int ans=0,tope=-1;
		for(auto I:v)
			if(tope<=I.fi){
				ans++;
				tope=I.se;
			}
		printf("%d\n",ans);
	}
}


