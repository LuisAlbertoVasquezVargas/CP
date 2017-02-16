#include <bits/stdc++.h>
#define pb push_back
#define EPS (1e-7)

using namespace std;

struct Point {
	double x,y;
	Point(double a,double b){
		x=a,y=b;
	};
	Point(){}
	double mod(){
		return sqrt(x*x+y*y);
	}
};

double dot(Point A,Point B){return A.x*B.x+A.y*B.y;}
Point operator- (Point A,Point B){return Point(A.x-B.x,A.y-B.y);}

Point X[3];
Point Y[3];

double ang(Point A,Point B){
	double cose=dot(A,B)/(A.mod() * B.mod());
	return acos(cose);
}

int main(){
	for(int i=0;i<3;++i){
		cin>>X[i].x>>X[i].y;
	}
	vector<double>v1,v2;
	v1.pb(ang(X[1]-X[0] ,X[2]-X[0]));
	v1.pb(ang(X[0]-X[2] ,X[1]-X[2]));
	v1.pb(ang(X[0]-X[1] ,X[2]-X[1]));
	for(int i=0;i<3;++i){
		cin>>Y[i].x>>Y[i].y;
	}
	v2.pb(ang(Y[1]-Y[0] ,Y[2]-Y[0]));
	v2.pb(ang(Y[0]-Y[2] ,Y[1]-Y[2]));
	v2.pb(ang(Y[0]-Y[1] ,Y[2]-Y[1]));
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	bool vale=1;
	for(int i=0;i<3;++i){
		if( fabs( v1[i]-v2[i] )<EPS ){}
		else vale=0;
	}
	if(vale)puts("YES");
	else puts("NO");
}


