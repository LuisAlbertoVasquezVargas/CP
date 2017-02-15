#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define pb push_back
#define N 100005
#define Vector Point
#define PI (acos(-1))
#define EPS 1e-4
using namespace std;

struct Point{
	
	long long x, y;
	Point(){}
	Point(long long _x, long long _y){x = _x; y = _y; }	
	double arg(){ return atan2(y, x); }
	long long mod2(){ return x * x + y * y;}
	void read(){ scanf("%lld%lld", &x, &y); }
};

Point operator -(const Point &p1, const Point &p2){ return Point(p1.x - p2.x, p1.y - p2.y); }
double getAngle(Point p1, Point p2, Point p3){
	
	double teta1 = (p2 - p1).arg();
	double teta2 = (p3 - p1).arg();
	double teta = fabs(teta1 - teta2);
	return min(2*PI - teta, teta);
}

Point P[N];
int main(){

	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)P[i].read();
	vector<pair<int, double> >ang;
	ang.pb(make_pair(getAngle(P[0], P[1], P[2]), 0));
	ang.pb(make_pair(getAngle(P[1], P[2], P[0]), 1));
	ang.pb(make_pair(getAngle(P[2], P[1], P[0]), 2));
	
	sort(all(ang));
	pair<long long, long long>rel;
	
	double teta;
	int center;
	long long l1, l2;
	
	if(fabs(ang[0].first - ang[1].first) < EPS){
		
		center = ang[2].second;
		l1 = (P[center] - P[(center + 1)%3]).mod2();
		l2 = (P[center] - P[(center + 2)%3]).mod2();
		rel = make_pair(l1, l2);
	}
	if(fabs(ang[1].first - ang[2].first) < EPS){
		
		center = ang[0].second;
		l1 = (P[center] - P[(center + 1)%3]).mod2();
		l2 = (P[center] - P[(center + 2)%3]).mod2();
		rel = make_pair(l1, l2);	
	}
}


