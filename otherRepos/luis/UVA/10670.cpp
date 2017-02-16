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

typedef vector< int > vi;
typedef vector< string > vs;

const int M = 20;
int solve(int from , int to , int A , int B , int cnt){
	REP(k,cnt){
		from /= 2;
		if(from < to) return INT_MAX;
	}
	return cnt * B + (from - to) * A;
}
int solve(int from , int to , int A , int B){
	int ans = INT_MAX;
	REP( k , M )
		ans = min(ans , solve(from , to , A , B , k));
	return ans;
}
int main(){
	int cases;
	cin >> cases;
	REP(tc , cases){
		int from , to , n;
		cin >> from >> to >> n;
		vector<pair<int, string>>vec;
		REP(i , n){
			string s , name;
			int A , B;
			cin >> s;
			REP(j , SZ(s))
				if(s[ j ] == ':' || s[ j ] == ',') s[ j ] = ' ';
			istringstream in(s);
			in >> name >> A >> B;
			int ans = solve(from , to , A , B);
			vec.pb( mp(ans , name) );
		}
		sort(all(vec));
		cout << "Case " << tc + 1 << '\n';
		for(auto x : vec) cout << x.se << " " << x.fi << endl;
	}
}




