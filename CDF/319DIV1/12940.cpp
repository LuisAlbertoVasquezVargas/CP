
#include<bits/stdc++.h>
#define N 100005
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

using namespace std;

int n;
string d;

bool isPalindrome(string &s){
  int sz = s.size();
  for(int i=0; i<s.size(); ++i){
    if( s[i] != s[sz-i])return false;
  }
  return true;
}

bool higher(string &a,string &b){
  if( a.size() == b.size()){
    for(int i=0; i<a.size(); ++i){
      if(a[i] > b[i])return true;
      if(a[i] < b[i])return false;
	}
    return false;
  }
  return a.size() > b.size();
}


string next(string s , int posa, int posb, int sz){
  string ans = "";
  
    if(s[posa] < '9'){
      s[posa]++;
      if(posa != posb)s[posb]++;
      return s;
	}
	else{
	  if(posa==0){
        s = "1";
        for(int i= 0; i<sz-1;++i)
          s += "0";
        s +="1";
        return s;
        int nsz = sz + 1;
        return next(s,nsz/2-1,nsz/2,nsz);
	  }
	  else{
	  	for(int i=posa;i<=posb;++i)
	  	  s[i] = '0';
	    return next(s,posa-1,posb+1,sz);
	  }
	}
  
 
  
}

int main(){
	ios_base :: sync_with_stdio(0);
  while( cin>>n>>d){
    string s = "1";
	for(int i=0; i<n; ++i){
      while(higher(d,s) || d == s){
      	int sz = s.size();
      	//cout<<s<<" "<<higher(d,s)<<" "<<d<<" "<<s<<" "<<d.size()<<" "<<s.size()<<endl;
        s = next(s,sz/2-(sz%2==0),sz/2,s.size());
	  }
	  cout<<s<<endl;
	  int sz = s.size();
	  s = next(s,sz/2-(sz%2==0),sz/2,s.size());
	}
  }
}
  
