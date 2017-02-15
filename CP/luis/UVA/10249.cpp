#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define mp make_pair
#define fi first
#define se second

#define pb push_back
#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

vpii read(int n){
	vpii A(n);
	REP(i , n){
		scanf("%d" , &A[ i ].fi);
		A[ i ].se = i;
	}
	sort(all(A));
	return A;
}
bool solve(vpii &teams , int &n , vpii &tables , int &m , vvi &TE){
	priority_queue<pii> TABLES(all(tables));	
	priority_queue<pii> TEAMS(all(teams));	
	TE = vvi(n);
	while(!TABLES.empty()){
		if(TEAMS.empty()) return 1;
		pii cur = TEAMS.top();
		TEAMS.pop();
		int cntTeams , idTeam;
		tie(cntTeams , idTeam) = cur;
		vpii vec;
		REP(i , cntTeams){
			if(TABLES.empty()) return 0;
			pii temp = TABLES.top();
			int cntTables , idTable;
			tie(cntTables , idTable) = temp;
			TABLES.pop();
			TE[idTeam].pb(idTable);
			cntTables --;
			if(cntTables)vec.pb(mp(cntTables , idTable));
		}
		for(auto x : vec)TABLES.push(x);
	}
	return TEAMS.empty();
}
void impr(vi &v){
	REP(i , SZ(v)) printf("%d%c" , v[ i ] + 1 , (i + 1 == SZ(v) ? 10 : 32));
}
int main(){
	int n , m;
	while(scanf("%d%d" , &n , &m) == 2){
		if(!n && !m) break;
		vpii teams = read(n);
		vpii tables = read(m);
		vvi TE;
		if(!solve(teams , n , tables , m , TE)){
			puts("0");
			continue;
		}
		puts("1");
		for(auto x : TE) impr(x);
	}
}


