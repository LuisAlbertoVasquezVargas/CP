#include <bits/stdc++.h>
using namespace std;
int busca(string s1,string s2){
	for(int i=0;i<s1.length();i++){
		if(s1[i]!=s2[i])return i;
	}
	return -1;
}
string opera(string s,int pos){
	string s2=s;
	int aux=pos;
	for(int i=s.length()-1;aux<s.length();i--){
		if(s[i]=='b'){
			s2[aux]='d';
		//	cout<<"auxb "<<aux<<endl;
			aux++;
			continue;
		}
		if(s[i]=='p'){
			s2[aux]='q';
		//	cout<<"auxp "<<aux<<endl;
			aux++;
			continue;
		}
		if(s[i]=='d'){
			s2[aux]='b';
		//	cout<<"auxd "<<aux<<endl;
			aux++;
			continue;
		}
		if(s[i]=='q'){
			s2[aux]='p';
		//	cout<<"auxq "<<aux<<endl;
			aux++;
			continue;
		}
		s2[aux]=s[i];
		//cout<<"aux "<<aux<<endl;
		aux++;
		
	}
	return s2;
}
int main(){
	int N;
	cin>>N;
	string s1,s2;
	cin>>s1>>s2;
	int cont=0,t=-1;
	while(busca(s1,s2)!=-1){
		int x=busca(s1,s2);
		if(x>t){
			t=x;

		}else{
	
			cout<<-1;
			return 0;
		}

		s1=opera(s1,t);

		cont++;
	}
	cout<<cont;
}
