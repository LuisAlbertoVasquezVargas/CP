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
typedef vector<ll> vll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int N=2500;
const int M=7500;
const int EDG=2*7500;

int le[ N + 5 ], ri[ M + 5 ] , distx[ N + 5 ] , disty[ M + 5 ];
int to[ EDG + 5 ], head[ N + 5 ] , Next[ EDG + 5 ] , edg;
int sign[EDG+5];
int mySign[N+5];
void reset(int n,int m){
	edg = 0;
	REP( i , n ) head[ i ] = -1;
	REP( i , n ) le[ i ] = -1;
	REP( i , m ) ri[ i ] = -1;
}
void add(int u, int v,char c,set<pii>&mySet){
	if(mySet.count(mp(u,v)))return;
	//DEBUG3(u,v,c);
    to[edg] = v; Next[edg] = head[u]; head[u] = edg++;
    sign[edg]=c;
    mySet.insert(mp(u,v));
}
bool bfs(int n,int m){
    bool flag = false;
    REP(i, n) distx[i] = 0;
    REP(i, m) disty[i] = 0;
    
	queue< int >q;
    REP(i, n) if(le[i] == -1) q.push( i );
    while( !q.empty() ){
        int u = q.front(); q.pop();
        for(int e = head[u]; e != -1; e = Next[e]){
            int v = to[e];
            if(!disty[v]){
                disty[v] = distx[u] + 1;
                if(ri[v] == -1) flag = true;
                else distx[ri[v]] = disty[v] + 1, q.push( ri[v] );
            }
        }
    }
    return flag;
}
bool dfs(int u){
    for(int e = head[u]; e != -1; e = Next[e]){
        int v = to[e];
        if(disty[v] == distx[u] + 1){
            disty[v] = 0;
            if(ri[v] == -1 || dfs(ri[v])){
                le[u] = v;
                ri[v] = u;
                mySign[u]=sign[e];
                return true;
            }
        }
    }
    return false;
}

int match(int n,int m){
    int res = 0;
    while(bfs(n,m))
        REP( i , n )
            if(le[i] == -1 && dfs(i)) res++;
    return res;
}

int getId(ll x,map<ll,int>&myMap,vll &values){
	if(myMap.count(x))return myMap[x];
	int len=SZ(myMap);
	values.pb(x);
	return myMap[x]=len;
}
char getOper(int a,int b,ll result){
	if((ll)a*(ll)b==result)return '*';
	if((ll)a-(ll)b==result)return '-';
	if((ll)a+(ll)b==result)return '+';
	assert(0);
}	
int main(){
	int n;
	while(scanf("%d",&n)==1){
		vi X,Y;
		map<ll,int>myMap;
		vll values;
		REP(i,n){
			int a,b;
			scanf("%d%d",&a,&b);
			X.pb(a);
			Y.pb(b);
			getId((ll)a*(ll)b,myMap,values);
			getId((ll)a-(ll)b,myMap,values);
			getId((ll)a+(ll)b,myMap,values);
		}
		set<pii>mySet;
		int m=SZ(myMap);
		reset(n,m);
		REP(i,n){
			int a=X[i];
			int b=Y[i];
			int id=getId((ll)a*(ll)b,myMap,values);
			add(i,id,'*',mySet);
			id=getId((ll)a-(ll)b,myMap,values);
			add(i,id,'-',mySet);
			id=getId((ll)a+(ll)b,myMap,values);
			add(i,id,'+',mySet);
		}
		int bpm=match(n,m);
		//DEBUG(bpm);
		if(bpm!=n){
			puts("impossible");
			continue;
		}
		REP(i,n){
			int j=le[i];
			ll result=values[j];
			int a=X[i],b=Y[i];
			printf("%d %c %d = %lld\n",a,getOper(a,b,result),b,result);
		}
	}
}




