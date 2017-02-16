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

vs S = {
"ABCDEFGHI",
"JKLMNOPQR",
"STUVWXYZ"
};
struct letter{
	int value , character , capacity;
	letter(){}
	letter(int value , int character , int capacity) : value(value) , character(character) , capacity(capacity) {}
};
bool operator < (const letter &a , const letter &b){
	if(a.value != b.value) return a.value > b.value;
	if(a.character != b.character) return a.character > b.character;
}
int main(){
	int cases;
	cin >> cases;
	REP(tc , cases){
		int n;
		cin >> n;
		
		vector<priority_queue<letter>> T(2);
		REP(k,3)REP(i , SZ(S[k])){
			char c = S[ k ][ i ];
			if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
				T[0].push(letter(i , c , 21));
			else T[1].push(letter(i , c , 5));
		}
		int turn = 0;
		vs cad(2);
		REP(k , n){
			if(T[turn].empty())break;
			auto cur = T[turn].top();
			T[turn].pop();
			cad[turn].pb(cur.character);
			cur.capacity --;
			if(cur.capacity > 0) T[turn].push(cur);
			turn ^= 1;
		}
		REP(k , 2) sort(all(cad[k]));
		string ans;
		REP(k , SZ(cad[0])){
			ans.pb(cad[0][k]);
			if(k < SZ(cad[1]))ans.pb(cad[1][k]);
		}
		cout << "Case " << tc + 1 << ": " << ans << '\n';
	}
}



