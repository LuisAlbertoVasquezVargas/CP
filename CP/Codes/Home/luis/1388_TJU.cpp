#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<sstream>

using namespace std;

map<string,double>M;
map<string,double>::iterator it;
int main()
{
     int t = 1;
     string s;
     for( int i = 0 ; i < t ; i++ )
     {
          double tot = 0;
          M.clear();
          while(1)
          {
               getline(cin,s);
               if(s == "" )break;
               M[s]++;   
               tot++;            
          }
          if(i!=0)puts("");
          for( it = M.begin() ; it != M.end() ; ++it)
          {
               cout<<(*it).first<<" ";
               printf("%.4lf\n",100*(*it).second/tot);
          }               
     }          
}
