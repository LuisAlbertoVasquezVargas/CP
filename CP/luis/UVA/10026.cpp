#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)

#define SZ(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef long double ld;

struct work{
	int time , fine , index;
	work(){}
	work(int time , int fine , int index) : time(time) , fine(fine) , index(index){}
};
bool operator < (const work &a , const work &b){
	if(a.time * b.fine != b.time * a.fine){
		return a.time * b.fine < b.time * a.fine;
	}
	return a.index < b.index;
}
int main(){
	int cases;
	scanf("%d" , &cases);
	REP(tc , cases){
		int n;
		scanf("%d" , &n);
		vector<work> vec;
		REP(i , n){
			int time , fine;
			scanf("%d%d" , &time , &fine);
			vec.pb(work(time , fine , i));
		}
		sort(all(vec));
		if(tc) puts("");
		REP(i , SZ(vec)) printf("%d%c" , ++vec[i].index , (i + 1== SZ(vec)? 10 : 32));
	}
}



