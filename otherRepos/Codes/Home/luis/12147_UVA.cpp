#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cstdio>
 
#define MAXN 1000
 
using namespace std;
 
int n,k,n1,n2;
int memo[MAXN][MAXN][2],memo2[MAXN+1][MAXN+1];
char s1[MAXN+1],s2[MAXN+1];
 
int dp( int pos1 , int pos2 , int full )
{
	if( n1 - pos1 < k || n2 - pos2 < k ) 
	{
		if( full == 0 )
			return 0;
		else memo2[pos1][pos2];
	}
	if( memo[pos1][pos2][full] != -1 )return memo[pos1][pos2][full];
	int cnt = memo2[pos1][pos2];
	int dev = 0;
	if( full )
	{
		if( cnt > 0 )
		{
			dev = max( dev , 1 + dp( pos1 + 1 , pos2 + 1 , 1 ) );
			dev = max( dev , dp( pos1 + 1 , pos2 , 0 ) );
			dev = max( dev , dp( pos1 , pos2 + 1 , 0 ) );
		}
		else 
		{
			dev = max( dev , dp( pos1 + 1 , pos2 , 0 ) );
			dev = max( dev , dp( pos1 , pos2 + 1 , 0 ) );			
		}
	}
	else
	{
		if( cnt < k )
		{
			dev = max( dev , dp( pos1 + 1 , pos2 , 0 ) );
			dev = max( dev , dp( pos1 , pos2 + 1 , 0 ) );		
		}
		else
		{
			dev = max( dev , k + dp( pos1 + k , pos2 + k , 1 ) );
			dev = max( dev , dp( pos1 + 1 , pos2 , 0 ) );
			dev = max( dev , dp( pos1 , pos2 + 1 , 0 ) );						
		}
	}

	return memo[pos1][pos2][full] = dev;
}

void init2()
{
    for( int i = n1 - 1 ; i >= 0 ; --i )
		memo2[i][n2] = 0;    	
    for( int j = n2 - 1 ; j >= 0 ; --j )		
    		memo2[n1][j] = 0;
    for( int i = n1 - 1 ; i >= 0 ; --i )
        for( int j = n2 - 1 ; j >= 0 ; --j )
            if( s1[i] == s2[j] )
                memo2[i][j] = 1 + memo2[i+1][j+1];
            else memo2[i][j] = 0; 
}

int main()
{
    while( scanf("%d",&k) == 1 )    
    {
        if( k == 0 )return 0;
        scanf( "%s%s",s1,s2);
        n1 = strlen(s1);
        n2 = strlen(s2);
        memset( memo , -1 , sizeof(memo) );       
        init2();
        printf( "%d\n", dp(0,0,0) );
    }
}
