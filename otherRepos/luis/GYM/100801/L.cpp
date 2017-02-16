#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define pb push_back
#define SZ(v) ((int)v.size())
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

vi dx = {0,0,1,-1};
vi dy = {1,-1,0,0};
bool valid(int x , int y, int n , int m){
	return x >= 0 && x < n && y >= 0 && y < m;
}
int solve(vvi a,int n,int m){
	int ans = 0;
	REP(i,n)REP(j,m){
		int target = a[i][j];
		REP(dir,4){
			bool ok = 1;
			for(int len = 1; len <= max(n,m) ; ++len){
				int nx = i + dx[dir] * len;
				int ny = j + dy[dir] * len;
				if(!valid(nx,ny,n,m)) break;
				if(a[nx][ny] >= target){
					ok = 0;
					break;
				}
			}
			ans += ok;
		}
	}
	return ans;
}
int main(){
	
	freopen("lucky.in", "r", stdin);
	freopen("lucky.out", "w", stdout);
	
	int n , m;
	while(scanf("%d%d",&n,&m) == 2){
		vvi a(n,vi(m));
		REP(i,n)REP(j,m) scanf("%d",&a[i][j]);
		printf("%d\n",solve(a,n,m));
	}
}




