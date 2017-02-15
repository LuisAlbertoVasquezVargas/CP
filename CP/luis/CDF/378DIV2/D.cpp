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
typedef vector< int > vi;

int min(int a,int b,int c){
	return min(a,min(b,c));
}
void relax(int a,int b, int c,int pos,map<pii,pii> &myMap,int &best,pii &ind){
	if(a>b)swap(a,b);
	if(!myMap.count(mp(a,b)))return;
	pii key=myMap[mp(a,b)];
	if(min(a,b,c+key.fi)>best){
		best=min(a,b,c+key.fi);
		ind=mp(key.se,pos);
	}
}
void update(int a,int b, int c,int pos,map<pii,pii> &myMap){
	if(a>b)swap(a,b);
	if(myMap.count(mp(a,b)))
		myMap[mp(a,b)]=max(myMap[mp(a,b)],mp(c,pos));
	else myMap[mp(a,b)]=mp(c,pos);
}

int main(){
	int n;
	while(scanf("%d",&n)==1){
		map<pii,pii>myMap;
		int best=0;
		pii ind;
		REP(i,n){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(min(a,b,c)>best){
				best=min(a,b,c);
				ind=mp(i,-1);
			}
			relax(a,b,c,i,myMap,best,ind);
			relax(a,c,b,i,myMap,best,ind);
			relax(b,c,a,i,myMap,best,ind);
			
			update(a,b,c,i,myMap);
			update(a,c,b,i,myMap);
			update(c,b,a,i,myMap);
		}
		if(ind.se==-1){
			puts("1");
			printf("%d\n",ind.fi+1);
			continue;
		}
		puts("2");
		printf("%d %d\n",ind.fi+1,ind.se+1);
	}
}


