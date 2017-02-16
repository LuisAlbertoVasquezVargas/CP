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
typedef long double ld;
typedef vector<int> vi;

int main(){
	int n , L , v1 , v2 , K;
	while(cin >> n >> L >> v1 >> v2 >> K){
		ld g = (n - 1)/K + 1;
		ld t = (ld)L/(v1 * (g - 1) + v2);
		printf("%.3f\n" , (double)t );
		ld ans = t + (ld)(L - (ld)t * v2) / v1;
		printf("%.15f\n" , (double)ans );
	}
}


