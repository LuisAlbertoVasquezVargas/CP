#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<bitset>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define inf (1 << 28)
#define N 2000001
char val[N]; 
int sib[N], son[N], T[N], cnt, seen[N], out[N], memo[N];
vector<int> term[N];   
void reset(){
     clr(sib, -1); clr(son, -1);
     cnt = 1;     
}
int find(int u, char c){
    for(int v = son[u]; v != -1; v = sib[v])
            if(val[v] == c) return v;
    return 0;;
}
char s[N];
void add(int who){
     int u = 0;
     for(int i = 0; s[i]; i++){
             if(find(u, s[i]) == 0){
                         val[cnt] = s[i];
                         sib[cnt] = son[u];
                         son[u] = cnt;
                         cnt++;
             }
             u = find(u, s[i]);
     }     
     term[u].pb(who);
}
void aho(){
     queue<int> q;
     for(int u = son[0]; u != -1; u = sib[u])
             q.push(u), T[u] = 0;
     while(!q.empty()){
                       int u = q.front(); q.pop();
                       for(int v = son[u]; v != -1; v = sib[v]){
                               int x = T[u];
                               while(x && find(x, val[v]) == 0) x = T[x];
                               x = find (x, val[v]);
                               T[v] = x;
                               q.push(v);
                       }                 
     }    
}

char t[N];

void corasick(){
     int u = 0;
     for(int i = 0; t[i]; i++){
             char c = t[i];
             while(u && find(u, c) == 0) u = T[u];
             u = find (u,c);
             seen[u] = true;
     }     
}
int main(){
	int tc;
	scanf( "%d" , &tc );
	while( tc-- )
	{
		scanf("%s", t);
		int n; scanf("%d", &n);
		reset();
		for( int i = 0 ; i < n ; ++i )
		{
			scanf("%s", s);
			add(i);
		}
		aho();
		corasick();
		f(i,1,cnt) if (seen[i]){
		int u = i;
		for (; u && memo[u]==0; u = T[u]) memo[u] = 1;
		}
		f(i, 0, cnt) if(memo[i]) FOR(u, term[i]) out[*u] = true;
		
		f(i, 0, n) if(out[i]) printf("y\n"); else printf("n\n"); 			
	}
}
