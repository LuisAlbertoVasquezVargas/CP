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
typedef pair< int , int > pii;
typedef vector< int > vi;

int solve(int cntDiff,int K,vi v){
	priority_queue<int,vi,greater<int>>Q(all(v));
	while(!Q.empty()){
		int val=Q.top();
		Q.pop();
		if(val<=K)K-=val,cntDiff-=2;
	}
	return cntDiff;
}
int main(){
	int n,K;
	while(scanf("%d%d",&n,&K)==2){
		string s;
		REP(i,n){
			int x;
			scanf("%d",&x);
			if(x>=0)s+="1";
			else s+="0";
		}
		if(!count(all(s),'0')){
			puts("0");
			continue;
		}	
		if(K<count(all(s),'0')){
			puts("-1");
			continue;
		}
		K-=count(all(s),'0');
		//DEBUG(s);
		s="1"+s;
		int cntDiff=0;
		REP(i,SZ(s)-1)
			if(s[i]!=s[i+1])
				cntDiff++;
		int pos=s.find('0');
		vi vec;
		for(int i=pos;i<SZ(s);++i){
			int ind;
			for(int j=i;j<SZ(s);++j)
				if(s[j]==s[i])ind=j;
				else break;
			if(s[i]=='1')
				vec.pb(ind-i+1);
			i=ind;
		}
		//DEBUG(cntDiff);
		if(!SZ(vec)){
			printf("%d\n",cntDiff);
			continue;
		}
		if((cntDiff&1)){
			printf("%d\n",solve(cntDiff,K,vec));
		}else{
			//DEBUG(SZ(vec));
			vi nvec=vec;
			int last=nvec.back();
			nvec.pop_back();
			int best=solve(cntDiff,K,nvec);
			if(last<=K)K-=last,cntDiff--;
			best=min(best,solve(cntDiff,K,nvec));
			printf("%d\n",best);
		}
	}
}


