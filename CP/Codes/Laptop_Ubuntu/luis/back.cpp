#include<bits/stdc++.h>
using namespace std;

const int limit = 10000000;
void f( int n ){
	cout << n << '\n';
	if( n * 10 + 7 <= limit ) f( n * 10 + 7 );
	if( n * 10 + 4 <= limit ) f( n * 10 + 4 );
}
int main(){
	f( 0 );
	
}
