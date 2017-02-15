#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define REP(i, a, b) \
for(int i = int(a); i < int(b); i++)
#define pb(v,e) v.push_back(e)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
int main(){
	int n,m;
	while(scanf("%d %d",&m,&n)==2){
		int cont=0;
		for(int x=0;x<=m;x++){
			for(int y=x;y<=m;y++){
				for(int z=y;z<=m;z++){
					if(x*x+y*y==z*z){
						
						cont++;
						}
				}
			}
		}
		cont=cont+(n-2)*(m+1);
		printf("%d\n",cont);
	}
	
	
	
	return 0;
}

