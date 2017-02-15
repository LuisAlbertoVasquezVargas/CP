#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
int main()
{
	int cases;
	cin >> cases;
	while( cases -- )
	{
		ld r , u , v , w , a , b , c ;
		cin >> r ;
		cin >> a >> b ;
		u = a/b;
		cin >> a >> b ;
		v = a/b;
		cin >> a >> b ;
		w = a/b;
		a = r*sqrt( ( 1 + w + w*v )/( w*w*v) );
		b = a*w*v;
		c = a*w;
		printf( "%.4f\n" , double( ( a + b + c )*r ) );
	}
}
