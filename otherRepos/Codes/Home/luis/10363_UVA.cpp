#include<iostream>

using namespace std;
string s[3];
int cntO,cntX,fO,fX;
void process()
{
     cntO = cntX = fO = fX = 0;
     for( int i = 0 ; i < 3 ; ++i )
          for( int j = 0 ; j < 3 ; ++j )
               if( s[i][j] == 'X' )
                    cntX++;
               else if( s[i][j] == 'O')
                    cntO++;
     for( int i = 0 ; i < 3 ; ++i )
     {
          int cx = 0;
          int co = 0;
          for( int j  = 0 ; j < 3 ; ++j )
               if( s[i][j] == 'X' )
                    cx++;
               else if( s[i][j] == 'O')  
                    co++;
          if( cx == 3 )
               fX++;
          if( co == 3 )
               fO++;
     }
     for( int j = 0 ; j < 3 ; ++j )
     {
          int cx = 0;
          int co = 0;          
          for( int i = 0 ; i < 3 ; ++i )
               if( s[i][j] == 'X' )
                    cx++;
               else if( s[i][j] == 'O')  
                    co++; 
          if( cx == 3 )
               fX++;
          if( co == 3 )
               fO++;                                            
     }
     if( s[0][0] == 'X' && s[1][1] == 'X' && s[2][2] == 'X' )
          fX++;
     if( s[0][0] == 'O' && s[1][1] == 'O' && s[2][2] == 'O' )
          fO++;
     if( s[0][2] == 'X' && s[1][1] == 'X' && s[2][0] == 'X' )
          fX++;
     if( s[0][2] == 'O' && s[1][1] == 'O' && s[2][0] == 'O' )
          fO++;
}
int main()
{
     int tc;
     cin >> tc;
     while( tc-- )
     {
          cin >> s[0] >> s[1] >> s[2];
          process();
          if( (cntX == cntO &&( (fX == 0 && fO >= 1) || (fX == 0 &&fO == 0) ) )||( (cntX == cntO + 1)&&( (fX == 0 && fO == 0)||(fX >= 1 && fO ==0 ) ) ) )
               cout<<"yes"<<endl;
          else cout<<"no"<<endl;
     }     
}
