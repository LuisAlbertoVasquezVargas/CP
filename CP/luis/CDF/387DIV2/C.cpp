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

struct event{
	int timer,type,pos;
	vi vec;
	event(int timer,int type,int pos,vi vec):timer(timer),type(type),pos(pos),vec(vec){}
};
bool operator <(const event &e1,const event &e2){
	if(e1.timer!=e2.timer)return e1.timer<e2.timer;
	if(e1.type!=e2.type)return e1.type<e2.type;
	return e1.pos<e2.pos;
}
int getFirstFrom(int len,vi &I,vi &taken){
	int sum=0;
	vi newI;
	REP(k,SZ(I)){
		if(k<len)sum+=I[k],taken.pb(I[k]);
		else{
			newI.pb(I[k]);
		}
	}
	I=newI;
	return sum;
}
int main(){
	int machines,n;
	while(scanf("%d%d",&machines,&n)==2){
		multiset<event>mySet;
		vi T(n),K(n),D(n);
		REP(i,n){
			scanf("%d%d%d",&T[i],&K[i],&D[i]);
			mySet.insert(event(T[i],1,i,vi()));
		}
		vi I(machines);
		REP(i,machines)I[i]=i+1;
		vi ans(n,-1);
		while(!mySet.empty()){
			auto e=*mySet.begin();
			mySet.erase(mySet.begin());
			int timer=e.timer;
			int type=e.type;
			int pos=e.pos;
			vi vec=e.vec;
			if(type==0){
				for(auto x:vec)I.pb(x);
				sort(all(I));
			}else{
				if(K[pos]<=SZ(I)){
					vi taken;
					ans[pos]=getFirstFrom(K[pos],I,taken);
					mySet.insert(event(T[pos]+D[pos],0,K[pos],taken));
				}else{
					continue;
				}
			}
		}
		REP(i,n)printf("%d\n",ans[i]);
	}
}


