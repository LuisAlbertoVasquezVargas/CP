#include<iostream>
#include<string>

using namespace std;

string s;
string f(string &s)
{
     int n = s.size();
     int pos = s.find(".");
     bool minus = (s[0]=='-');
     bool point =  (pos!=-1);
     string t;
     if( !minus && !point )
     {
          int j = 0;
          for( int i = n - 1 ; i >= 0 ; --i )
          {
               if(j!=0&&j%3==0)
                    t=','+t;
               t = s[i]+t;
               j++;
          }
          return "$"+t+".00";
     }else if( minus && !point )
     {
          int j = 0;
          for( int i = n - 1 ; i > 0 ; --i )
          {
               if(j!=0&&j%3==0)
                    t=','+t;
               t = s[i]+t;
               j++;
          }
          return "($"+t+".00)";          
     }else if( !minus && point )
     {
          int j = 0;
          for( int i = pos - 1 ; i >= 0 ; --i )
          {
               if(j!=0&&j%3==0)
                    t=','+t;
               t = s[i]+t;
               j++;
          }
          int k = 2;
          while(pos < n && k-- >= 0)
               t+=s[pos++];
          while(k-->=0)
               t+='0';
          return "$"+t;                    
     }else if( minus && point )
     {
          int j = 0;
          for( int i = pos - 1 ; i > 0 ; --i )
          {
               if(j!=0&&j%3==0)
                    t=','+t;
               t = s[i]+t;
               j++;
          }
          int k = 2;
          while(pos < n && k-- >= 0)
               t+=s[pos++];
          while(k-->=0)
               t+='0';
          return "($"+t+")";           
     }
}
int main()
{
     while( cin >> s )
          cout<<f(s)<<endl;     
}
