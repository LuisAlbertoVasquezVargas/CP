#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define pb push_back
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())

#define fi first
#define se second
#define mp make_pair

typedef vector<int> vi;
typedef long long ll;

int main(){
	srand(time(NULL));
	ll r=(ll)1e18;
	r--;
	cout << 2+(rand()%r)<<'\n';
}
