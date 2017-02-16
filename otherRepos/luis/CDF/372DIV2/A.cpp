#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define clr(T,val) memset(T,val,sizeof(T))

#define SZ(v) ((int)v.size())
#define pb push_back
#define all(v) v.begin(),v.end()

#define fi first
#define se second
#define mp make_pair

typedef vector<int> vi;
typedef long long ll;

int main(){
	int n,C;
	while(scanf("%d%d",&n,&C) == 2){
		int last = -1 , cnt = 0;
		REP(i , n){
			int x;
			scanf("%d",&x);
			if(last == -1) last = x , cnt = 1;
			else{
				if(x - last<= C){
					last = x;
					cnt ++;
				}else{
					last = x;
					cnt = 1;
				}
			}
		}
		printf("%d\n",cnt);
	}
}



