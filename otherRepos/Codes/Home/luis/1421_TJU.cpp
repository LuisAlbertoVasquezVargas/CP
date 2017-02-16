#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#define MAXN 12
using namespace std;

bool vis[MAXN];
string M[MAXN] = {"C*D*E*F*G*A*B*C*","C#D#F*F#G#A#C*C#","D*E*F#G*A*B*C#D*","D#F*G*G#A#C*D*D#","E*F#G#A*B*C#D#E*","F*G*A*A#C*D*E*F*","F#G#A#B*C#D#F*F#","G*A*B*C*D*E*F#G*","G#A#C*C#D#F*G*G#","A*B*C#D*E*F#G#A*","A#C*D*D#F*G*A*A#","B*C#D#E*F#G#A#B"};
string N[MAXN] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
string s,t;

void clean()
{
     memset(vis,1,sizeof(vis));
}
void doit(string st)
{
     if(st.size() == 1 )
          st.push_back('*');
     for( int i = 0 ; i < MAXN ; ++i )
     {
          if( !vis[i] )continue;
          if( M[i].find(st) == -1 )
               vis[i] = 0;
     }
}
int main()
{
     bool ok;
     while( getline(cin,s) )
     {
          if( s == "END" )break;
          ok = 0;
          clean();
          istringstream in(s);
          while( in >> t)
               doit(t);
          for( int i = 0 ; i < MAXN ; ++i )
               if(vis[i])
                    if( !ok )
                    {
                         ok = !ok;
                         cout<<N[i];
                    }else cout<<" "<<N[i];
          cout<<endl;
     }
}
