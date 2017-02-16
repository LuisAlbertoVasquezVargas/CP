#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)
#define MAXN 100005
#define ALPHA 26
#define cout1(x) cout<<x<<endl

using namespace std;

int trie1[MAXN][ALPHA], trie2[MAXN][ALPHA], node1, node2;
char letra[MAXN];
bool perromer[MAXN];
int frec[26];

void add1(char *s){
	
	int len = strlen(s),  p = 0;
	for(int i = 0; i < len; i++){
		if(!trie1[p][s[i] - 'a']){
			p = trie1[p][s[i] - 'a'] = node1++;
		}
		else p = trie1[p][s[i] - 'a'];
		letra[p] = s[i];
		if(i == 0)perromer[p] = 1;
	}
}


void add2(char *s){
	
	int len = strlen(s), p = 0;
	for(int i = len - 1; i >= 0; i--){
		if(!trie2[p][s[i] - 'a']){
			p = trie2[p][s[i] - 'a'] = node2++;
			frec[s[i] - 'a']++;
		}
		else p = trie2[p][s[i] - 'a'];
	}
}




int main()
{
	int P, S;
	
	while(scanf("%d%d", &P, &S) == 2){
		
		
		if(P == 0 && S == 0)break;
		char pal[1005];
		node1 = node2 = 1;
		memset(frec, 0, sizeof frec);
		memset(trie1, 0, sizeof trie1);
		memset(trie2, 0, sizeof trie2);
		memset(perromer, 0, sizeof perromer);
		
		for(int i = 0; i < P; i++){
			scanf("%s", pal);
			add1(pal);
		}
		
		for(int i = 0; i < S; i++){
			scanf("%s", pal);
			add2(pal);
		}
		for(int i = 0; i < 26; i++){
			if(frec[i] > 0)cout<<i<<"  "<<frec[i]<<endl;
		}
		cout<<node1 << " "<<node2<<endl;
		long long res = (node1 - 1LL)*(node2 - 1LL);
		
		for(int i = 1; i < node1; i++){
			if(!perromer[i])res -= frec[letra[i] - 'a'];
		}
		
		cout1(res);

	}

}


