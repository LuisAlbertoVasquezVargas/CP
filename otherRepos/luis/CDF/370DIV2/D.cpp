#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAX_K=1000;
const int MAX_T=100;
const int MOD=(int)1e9+7;
const int CTE=MAX_K*MAX_T;
int DP[2][2*CTE+5];
int AC[2*CTE+5];
void update(int pos,int sum,int val){
	DP[pos][CTE+sum]=val;
}
void initAcum(int pos,int lo,int hi){
	AC[CTE+lo]=0;
	for(int k=lo;k<=hi;++k){
		AC[CTE+k+1]=AC[CTE+k]+DP[pos][CTE+k];
		if(AC[CTE+k+1]>=MOD)AC[CTE+k+1]-=MOD;
	}
}
int get(int lo,int hi){
	int ans=AC[CTE+hi+1]-AC[CTE+lo];
	if(ans<0)ans+=MOD;
	return ans;
}
int main(){
	int a,b,K,T;
	while(scanf("%d%d%d%d",&a,&b,&K,&T)==4){
		
		for(int sum=-K*T;sum<=K*T;++sum)
			update(T&1,sum,0);
		update(T&1,0,1);
		
		for(int posT=T-1;posT>=0;--posT){
			initAcum((posT+1)&1,-K*T,K*T);
			for(int sum=-K*T;sum<=K*T;++sum)
				update(posT&1,sum,get(max(-K*T,sum-K),min(sum+K,K*T)));
		}
		initAcum(0,-K*T,K*T);
		
		int ans=0;
		for(int sum1=-K*T;sum1<=K*T;++sum1){
			int sum2=a+sum1-b-1;
			if(sum2>=-K*T)
				ans=(ans+(ll)get(sum1,sum1)*(ll)get(-K*T,min(sum2,K*T)))%MOD;
		}
		printf("%d\n",ans);
	}
}


