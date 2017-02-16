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

#define test() cerr<<"hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector<pii> vpii;
typedef vector< int > vi;

bool valid(vi &v){
	if(SZ(v)==1)return 1;
	int maxi=*max_element(all(v));
	int mini=*min_element(all(v));
	return maxi!=mini;
}
void makeOP(vi &v, vi &POS,vi &OP,int len){
	/*
	REP(i,SZ(v))DEBUG(v[i]);
	test();
	*/
	while(1){
		if(SZ(v)==1)break;
		int maxi=*max_element(all(v));
		int secondMaxi=0,curPOS=-1,curOP=-1;
		REP(i,SZ(v)){
			if(v[i]!=maxi)continue;
			if(i-1>=0&&v[i-1]!=maxi){
				if(v[i-1]>secondMaxi){
					secondMaxi=v[i-1];
					curPOS=i;
					curOP='L';
				}
			}
			if(i+1<SZ(v)&&v[i+1]!=maxi){
				if(v[i+1]>secondMaxi){
					secondMaxi=v[i+1];
					curPOS=i;
					curOP='R';
				}
			}
		}
		assert(curPOS!=-1);
		if(curOP=='L'){
			v[curPOS]+=v[curPOS-1];
			v.erase(v.begin()+(curPOS-1));
		}else{
			v[curPOS]+=v[curPOS+1];
			v.erase(v.begin()+(curPOS+1));
		}
		POS.pb(curPOS+len);
		OP.pb(curOP);
	}
}
bool Find(int target,deque<int>&a,vi &POS,vi &OP,int buckets){
	int sum=0;
	vi temp;
	while(!a.empty()&&sum+a.front()<=target){
		temp.pb(a.front());
		sum+=a.front();
		a.pop_front();
	}
	if(target!=sum)return 0;
	if(!valid(temp))return 0;
	makeOP(temp,POS,OP,buckets);
	return 1;
}
int main(){
	int n,K;
	while(scanf("%d",&n)==1){
		deque<int> a(n);
		REP(i,n)scanf("%d",&a[i]);
		scanf("%d",&K);
		vi b(K);
		REP(i,K)scanf("%d",&b[i]);
		bool ok=1;
		vi POS,OP;
		REP(j,K){
			if(Find(b[j],a,POS,OP,j))continue;
			ok=0;
			break;
		}
		if(!a.empty())ok=0;
		if(!ok){
			puts("NO");
			continue;
		}
		puts("YES");
		REP(i,SZ(POS))
			printf("%d %c\n",POS[i]+1,OP[i]);
	}
}


