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

int main(){
	int cases;
	scanf("%d" , &cases);
	REP(tc , cases){
		int n , T , m;
		scanf("%d%d%d" , &n , &T , &m);
		vi X(m);
		REP(i , m) scanf("%d" , &X[i]);
		int timer = 0 , travels = 0;
		REP(i , m){
			int cur = n , ind = -1;
			for(int j = i ; j < m ; ++j){
				if(!cur) break;
				if(X[ j ] <= timer){
					cur --;
					ind = j;
				}
			}
			i = ind + 1;
			ind = -1;
			for(int j = i ; j < m ; ++j){
				if(!cur) break;
				cur --;
				ind = j;
				timer = X[ j ];
			}
			timer += 2 * T;
			travels ++;
			if(ind == -1) i --;
		}
		printf("%d %d\n" , timer , travels );
	}
}


