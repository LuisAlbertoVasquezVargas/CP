#include<cstdio>

typedef long long ll ;

int pow( int a , int b , int c ){
    int ans = 1;
    while( b ){
        if( b&1 ) ans = ( ans * a )%c;
        a = ( a*a )%c;
        b >>= 1;
    }	
    return ans;
}

int main()
{
	int a , b , c;
	while( scanf( "%d%d%d" , &a , &b , &c ) == 3 )
		printf( "%d\n" , pow( a%c , b , c ) );
}
