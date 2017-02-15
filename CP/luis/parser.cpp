#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline( cin , s );
	//cout << s << endl;
	while( 1 ){
		int pos = (int)s.find( "\\n" );
		//cout << pos << endl;
		if( pos == -1 ) break;
		s.replace( pos , 2 , "" );
	}
	cout << s << '\n';
}
