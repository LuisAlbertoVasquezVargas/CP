#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
     int h,m,s,c;
     char buffer[10];          
     while(cin.getline(buffer,sizeof(buffer)))
     {
          sscanf(buffer,"%2d%2d%2d%2d",&h,&m,&s,&c);
          printf("%07d\n",(h*360000+m*6000+100*s+c)*125/108);
     }     
}
