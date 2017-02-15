#include<bits/stdc++.h>

using namespace std;

int ceil( int a , int b ){
	if( a == 0 ) return 0;
	return (a - 1) / b + 1;
}
int main(){
  int B , G;
  while( scanf("%d%d",&B, &G) == 2){
  	if( B == -1 && G == -1 ) break;
  	printf( "%d\n" ,  max( ceil( B , G + 1 ) , ceil( G , B + 1 ) ) );
  }
}
