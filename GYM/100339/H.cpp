
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 10005
#define M 15000005

using namespace std;

int last_pos[M], nodes;
char C[M], car[M], val[M];

int NEXT[M], last[M];
char s[N];

void addEdge(int u, char c){
	
	car[nodes] = c, NEXT[nodes] = last[u], last[u] = nodes++;
}

void add(int pos, int &ans){
	
	int cur = 0;
	for(int i = pos, e; i >= 0; i--){
		
		for(e = last[cur]; e != -1; e = NEXT[e])
			if(car[e] == s[i])break;
		
		if(e == -1)addEdge(cur, s[i]), e = nodes - 1;
		cur = e;
		
		C[cur]++;
		if(C[cur] == 2)ans++;
		
		if(C[cur] >= 2 && val[cur] != -1 && last_pos[cur] >= i)val[cur] = -1, ans--;
		last_pos[cur] = pos;
	}
	
}


int main(){
	freopen( "seti.in" , "r" , stdin );
	freopen( "seti.out" , "w" , stdout );
	scanf("%s", s);
	int n = strlen(s), ans = 0;

	memset(last, -1, sizeof last);
	nodes = 1;
	
	for(int i = 0; i < n; i++)add(i, ans);
	printf("%d\n", ans);
	
}

