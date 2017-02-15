#include<bits/stdc++.h>
#define N 100005
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

using namespace std;


vector <int> KMP(string T, string P)
{
    vector <int> B(P.size() + 1, -1);
    for(int i = 0, j = -1; i < P.size(); i++)
    {
        while(j != -1 && P[i] != P[j]) j = B[j];
        j++;
        B[i + 1] = j;
    }
 
    vector <int> matches;
    for(int i = 0, j = 0; i < T.size(); i++)
    {
        while(j != -1 && T[i] != P[j]) j = B[j];
        j++;
        if(j == P.size()) matches.push_back(i + 1 - j), j = B[j];
    }
    
    return matches;
}
bool isPar( char c ){
  return ( c == '(' || c == ')' );
}

bool isSign( char c ){
  return (c == '*' || c == '+' || c == '-' || c == '/' );
}

string fixed(string s){
  string ret = "";
  for(int i=0; i<s.size(); ++i){
    if( isPar(s[i] ) ){
      ret += s[i];
	}
	else{
	  if( isSign(s[i]) ){
	    ret += '+';
	  }
	  else{
	    ret += 'x';
	  }
	}
	
  }
  return ret;
}

string NormRet(string s){
  int sz = s.size();
  string ret;
  if(isPar(s[0]))s[0] = ' ';
  if(isPar(s[sz-1]))s[sz-1] = ' ';
  for(int i=1;i<s.size(); ++i){
    if(s[i] == 'x' && s[i-1] == 'x')
      s[i-1] = ' ';
  }
  for(int i=0; i<s.size(); ++i)
    if(s[i] != ' ')
      ret += s[i];

  return ret;
}

string a , b;

int main(){
  while( cin>>a>>b ){
    a = NormRet(fixed(a));
    b = NormRet(fixed(b));
    
    cout<<KMP(b,a).size()<<endl;
  }
}

