#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cout << "someName = {";
	//cout << '"';
	bool flag = 0;
	while(getline(cin , s)){
		//s.pop_back();
		cout << (flag ? ',' :' ') << '"' << s << '"';
		//cout << (flag ? " " :"") << s;
		//cout << (flag ? ',' :' ') << s ;
		flag = 1;
	}
	cout << '"';
	cout << "};";
}


