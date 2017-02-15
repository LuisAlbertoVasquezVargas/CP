#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int MOD=(int)1e9+7;																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																								
const int MAXN=6																																																																																			*(int)1e8+7;
int F[MAXN+1];
void init(){
	F[0]=1;
	for(int i=1;i<=MAXN;++i)
		F[i]=((ll)i*F[i-1])%MOD;
}
int main(){
	init();
	int cases;
	scanf("%d",&cases);
	REP(tc,cases){
		int n,m;
		scanf("%d%d",&n,&m);
		vi A(n);
		REP(i,n)scanf("%d",&A[i]);
		
	}
}

