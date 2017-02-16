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
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int MAX_N=(int)1e3;
const int MAX_M=3000;
int id[MAX_N],_rank[MAX_N];
int Find(int x){return id[x]==x?x:Find(id[x]);}
void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	if(pa != pb)
	{
		if(_rank[pa] < _rank[pb]) id[pa] = pb;
		else if(_rank[pa] > _rank[pb]) id[pb] = pa;
		else
		{
			id[pb] = pa;
			_rank[pa]++;
		}
	}
}
void initGraph(int n){
	REP(i,n)id[i]=i,_rank[i]=1;
}
int orig[MAX_M],dest[MAX_M];
int L[MAX_M],R[MAX_M];
bool verify(int n,int m,int x,int y){
	initGraph(n);
	REP(i,m){
		if(L[i]<=x&&y<=R[i])
			Union(orig[i],dest[i]);
		if(Find(0)==Find(n-1))return 1;
	}
	if(Find(0)==Find(n-1))return 1;
	return 0;
}
int findLowToHigh(int x,int y,int n,int m){
	int lo=x,hi=y;
	if(verify(n,m,lo,hi))return hi;
	while(hi-lo>1){
		int med=(lo+hi)>>1;
		if(verify(n,m,x,med))lo=med;
		else hi=med;
	}
	return lo;
}

int findHighToLow(int x,int y,int n,int m){
	int lo=x,hi=y;
	if(verify(n,m,lo,hi))return lo;
	while(hi-lo>1){
		int med=(lo+hi)>>1;
		if(verify(n,m,med,y))hi=med;
		else lo=med;
	}
	return hi;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		REP(i,m){
			scanf("%d%d%d%d",&orig[i],&dest[i],&L[i],&R[i]);
			orig[i]--,dest[i]--;
		}
		int ans=0;
		REP(i,m){
			int x=L[i],y=R[i];
			if(verify(n,m,x,x)){
				ans=max(ans,findLowToHigh(x,y,n,m)-x+1);
			}
			if(verify(n,m,y,y)){
				ans=max(ans,y-findHighToLow(x,y,n,m)+1);
			}
		}
		if(!ans)puts("Nice work, Dima!");
		else printf("%d\n",ans);
	}
}
