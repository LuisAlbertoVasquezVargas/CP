#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define pb push_back
#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef vector< int > vi;
typedef vector< string > vs;

vs read(int n , vi &v , map<string , int> &mapa){
	vs vec(n);
	REP(i , n) {
		getline(cin , vec[i]);
		if(!mapa.count(vec[i])) mapa[vec[i]] = SZ(mapa) - 1;
		v[ i ] = mapa[vec[i]];
	}
	return vec;
}
int main(){
	ios_base :: sync_with_stdio(0);
	int cases;
	cin >> cases;
	REP(tc , cases){
		int n;
		cin >> n;
		string dummy;
		getline(cin , dummy);
		vi a(n) , b(n);
		map<string , int> mapa;
		vs A = read(n , a , mapa);
		vs B = read(n , b , mapa);

		vi ans;
		REP(L , n + 1){
			vi orderList;
			deque<int> temp(all(a));
			for(int i = L - 1 ; i >= 0 ; --i){
				auto target = b[ i ];
				orderList.pb(target);
				int pos = find(all(temp) , target) - temp.begin();
				temp.erase(temp.begin() + pos);
				temp.push_front(target);
			}
			vi image(all(temp));
			if(image == b){
				ans = orderList;
				break;
			}
		}
		for(auto x : ans) cout << A[ x ] << '\n';
		cout << '\n';
	}
}


