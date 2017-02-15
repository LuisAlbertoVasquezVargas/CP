#include <bits/stdc++.h>
#define N 405
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define Vector Point

using namespace std;

struct Point{
	
	int x, y;
	Point(){}
	Point(int _x, int _y){x = _x; y = _y; }
	void read(){scanf("%d%d", &x, &y); }
};

int cross(const Vector &v1, const Vector &v2){ return v1.x * v2.y - v1.y * v2.x; }
Point P[N];


int main(){
		
	int tc = 0;
	scanf("%d", &tc);
	
	while(tc--){
		
		int n;
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++)P[i].read();
		int ans = 0;
		
		for(int i = 0; i < n; i++)
			ans += cross(P[i], P[(i + 1)%n]);
			
		if(ans > 0)puts("fight");
		else puts("run");
		
	}
}
