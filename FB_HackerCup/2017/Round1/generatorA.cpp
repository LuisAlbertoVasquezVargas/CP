#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int main(){
	int cases=100,n=300,m=300,val=1000000;
	cout<<cases<<'\n';
	REP(tc,cases){
		cout<<n<<" "<<m<<'\n';
		REP(i,n){
			REP(j,m)cout<<1+rand()%val<<" ";
			cout<<'\n';
		}
	}
}
