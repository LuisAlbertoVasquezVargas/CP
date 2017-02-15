#include<bits/stdc++.h>
using namespace std;

int main(){
	int n , m;
	while( cin >> n >> m ){
		puts( !( ( n * m ) & 1 ) ? "[:=[first]": "[second]=:]" );
	}
}
