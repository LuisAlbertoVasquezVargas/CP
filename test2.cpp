#include <bits/stdc++.h>
using namespace std;
int main()
{
	map < char , int > mapa;
	int n=0;
	for( char car = 'a' ; car <= 'z' ; car++)
	{
		mapa[ car ] = n;
		n++;
	}
	map<char,int>::iterator it;
	for(it = mapa.begin() ; it!=mapa.end() ; it++ )
	{
		cout<< it->first <<" ... "<< it->second <<'\n';
	}
}
