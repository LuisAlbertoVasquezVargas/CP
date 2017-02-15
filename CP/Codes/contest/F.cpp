#include<bits/stdc++.h>
#define pb push_back
#define N 23
using namespace std;

vector<int>adj[N];
int T[N],n,t,A[N],caso=1;
//int memo[N][(1<<N)+5];
int  DP[ N ][ (1<<N) + 5 ];
void genera(){
	// j representa j+1
	for(int i=0;i<(1<<n);++i){
		int sum=0;
		for(int j=0;j<n;++j){
			if( (i>>j)&1)sum+=(j+1);
		}
		if(sum<=22 && T[sum]!=-1)adj[sum].pb(i);
	}
}

/*
int f(int pos,int mask){
	if(pos==t)return 0;
	int &ret=memo[pos][mask];
	int b1=__builtin_popcount(mask);
	if(ret!=-1)return ret;
	ret=0;
	//adj de A[pos]
	for(int i=0;i<adj[A[pos]].size();++i){
		int mask2=adj[ A[pos] ][i];
		int b2=__builtin_popcount(mask2);
		int mask3=mask ^ mask2;
		int b3=__builtin_popcount(mask3);
		if(b3==b1+b2){
			ret=max(ret,b2+f(pos+1,mask3));
		}
	}
	return ret;
}
*/

int main(){
	while(scanf("%d%d",&n,&t)==2){
		if(!n && !t)break;
		memset(T,-1,sizeof(T));
		for(int i=0;i<=22;++i)adj[i].clear();
		//memset(memo,-1,sizeof(memo));
		for(int i=0;i<t;++i){
			scanf("%d",&A[i]);
			T[A[i]]=1;
		}
		genera();
		//printf("Game %d: %d\n",caso++,f(0,0));
		for( int i = 0 ; i < ( 1 << n ) ; ++i ) DP[ t ][ i ] = 0;
		int it = 0;
		for( int pos = t - 1 ; pos >= 0 ; --pos ){
			
			for( int mask = ( 1 << n ) - 1 ; mask >= 0 ; --mask ){
				int b1=__builtin_popcount(mask);
				int &dev = DP[ pos ][ mask ] = 0;
				//cout << pos << " " << mask << " " << it ++ <<endl;
				//cout << it++ << " "  << adj[ A[ pos ] ].size() << endl;
				for( int i = 0 ; i < adj[ A[ pos ] ].size() ; ++i ){
					//cout << i << endl;
					it++;
					int mask2 = adj[ A[pos] ][ i ];
					int b2 =__builtin_popcount( mask2 );
					int mask3 =mask ^ mask2;
					int b3 = __builtin_popcount( mask3 );
					if( b3 == b1 + b2 ){
						dev = max( dev , b2 + DP[ pos + 1 ][ mask3 ] );
					}
				}	
			}
		}
		cout << it << endl;
		printf("Game %d: %d\n",caso++, DP[ 0 ][ 0 ] );
	}
}
