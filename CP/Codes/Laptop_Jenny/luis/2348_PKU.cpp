//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;

int G( int a , int b ){
	if( a > b )swap( a , b );
	if( b == 0 ) return 0;
	if( b % a == 0 ) return 1;
	int g = G( b % a , a );
	int q = b/a;
	if( g == 0 ) return q;
	if( g >= q ) return q - 1;
	return q;
}
/*
int g( int a , int b ){
	if( a > b ) swap( a , b );
	if( a == b ) return 0;
	if( b % a == 0 ) return b/a - 1;
	int G = g( b%a , a );
	if( G >= b/a ) return b/a - 1;
	return b/a;
}
*/
int main(){
	int n , m;
	while( cin >> n >> m ){
		if( !n ) break;
		puts( G( n , m ) ? "Stan wins":"Ollie wins" );
	}
}
