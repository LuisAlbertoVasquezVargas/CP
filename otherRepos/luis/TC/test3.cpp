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

string S="()[]";
int main(){
	int n=40;
	//REP(i,n) cout << S[rand()%4];
	REP(i,n/2)cout << "(";
	REP(i,n/2)cout << ")";
	
}
