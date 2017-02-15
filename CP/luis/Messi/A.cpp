#include<bits/stdc++.h>
using namespace std;

string getLCS(string a,string b){
	//fill DP table
	int n=(int)a.size(),m=(int)b.size();
	int DP[n+1][m+1];//create a table
	memset(DP,0,sizeof(DP));//setting DP table to 0
	for(int lenN=1;lenN<=n;++lenN)
		for(int lenM=1;lenM<=m;++lenM){
			DP[lenN][lenM]=max(DP[lenN-1][lenM],DP[lenN][lenM-1]);
			if(a[lenN-1]==b[lenM-1])
				DP[lenN][lenM]=max(DP[lenN][lenM],1+DP[lenN-1][lenM-1]);
		}
	string ans;
	int x=n,y=m;
	while(1){
		if(x==0&&y==0)break;
		if(x-1>=0&&DP[x][y]==DP[x-1][y]){
			x=x-1;
			continue;
		}
		if(y-1>=0&&DP[x][y]==DP[x][y-1]){
			y=y-1;
			continue;
		}
		ans+=a[x-1];
		x=x-1;
		y=y-1;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
struct person{
	vector<string> firstName;
	vector<string> lastName;
	person(vector<string> firstName,vector<string> lastName):firstName(firstName),lastName(lastName){}
};
bool comparator(const person &a,const person &b){
	if(a.firstName!=b.firstName)return a.firstName<b.firstName;
	return a.lastName<b.lastName;
}
vector<string> read(int n){
	vector<string>ans;
	for(int i=0;i<n;++i)cin>>ans[i];
	return ans;
}
vector<string> checkItems(string group){
	istringstream buffer(group);
	string str;
	vector<string>myVec;
	while(buffer>>str)
		myVec.push_back(str);
	return myVec;
}
void process(vector<person>&DB,string name,vector<string>&dictFirstNames,vector<string>&dictLastNames){
	int pos=(int)name.find(',');
	if(pos==-1){
		//assert(0);
		return;
	}
	string lastNames=name.substr(0,pos);
	string firstNames=name.substr(pos+1);
	
	vector<string>lastNamesR=checkItems(lastNames);//Reagruped
	vector<string>firstNamesR=checkItems(firstNames);//Reagruped
	
	if((int)lastNamesR.size()==2){
		for(auto item:firstNamesR)
			dictFirstNames.push_back(item);
		for(auto item:lastNamesR)
			dictLastNames.push_back(item);
	}else{
		cout<<name<<" has a rare format"<<'\n';
	}
}
bool isHere(vector<string>&dict,string &name){
	return binary_search(dict.begin(),dict.end(),name);
}
bool isAllHere(vector<string>&dict,vector<string>&group){
	for(auto item:group)
		if(!isHere(dict,item))return 0;
	return 1;
}
void fix(vector<string>&vec){
	sort(vec.begin(),vec.end());
	vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}
void impr(vector<string> &vec){
	for(auto item:vec)cout<<item<<'\n';
}
void search(vector<string>&dict1,vector<string>&dict2,string str,int &total,int &matched,vector<string> &ans){
	string best,pattern;
	for(auto dict:{dict1,dict2})
		for(auto item:dict){
			string lcs=getLCS(item,str);
			if((int)lcs.size()>(int)best.size())
				best=lcs,pattern=item;
		}
	ans.push_back(pattern);
	total+=(int)str.size();
	matched+=(int)best.size();
}
void doIt(vector<string>&dictFirstNames,vector<string>&dictLastNames,string name){
	int pos=(int)name.find(',');
	if(pos==-1){
		//assert(0);
		return;
	}
	string groupLeft=name.substr(0,pos);
	string groupRight=name.substr(pos+1);
	
	vector<string>groupLeftR=checkItems(groupLeft);//Reagruped
	vector<string>groupRightR=checkItems(groupRight);//Reagruped
	
	if(groupLeftR.empty()||groupRightR.empty())return;
	
	if(isAllHere(dictFirstNames,groupLeftR)&&isAllHere(dictLastNames,groupRightR)){
		cout<<"Result : All correct 100%\n";
		cout<<"firstNames : ";
		for(auto item:groupLeftR)
			cout<<item<<" ";
		cout<<"\n";
		cout<<"lastNames : ";
		for(auto item:groupRightR)
			cout<<item<<" ";
		cout<<"\n";
		return;
	}
	
	if(isAllHere(dictFirstNames,groupRightR)&&isAllHere(dictLastNames,groupLeftR)){
		cout<<"Result : All correct 100%\n";
		cout<<"firstNames : ";
		for(auto item:groupRightR)
			cout<<item<<" ";
		cout<<"\n";
		cout<<"lastNames : ";
		for(auto item:groupLeftR)
			cout<<item<<" ";
		cout<<"\n";
		return;
	}
	int total=0,matched=0;
	vector<string> ans;
	for(auto item:groupLeftR)search(dictFirstNames,dictLastNames,item,total,matched,ans);
	for(auto item:groupRightR)search(dictFirstNames,dictLastNames,item,total,matched,ans);
	cout<<"Result : Correct at "<<(double)matched/total<<"%\n";
	cout<<"Best result :";
	for(auto item:ans)cout<<item<<" ";
	cout<<'\n';
}
int main(){
	int n;
	cin>>n;
	string dummy;
	getline(cin,dummy);
	vector<person> DB;
	vector<string>dictFirstNames,dictLastNames;
	for(int i=0;i<n;++i){
		string name;
		getline(cin,name);
		process(DB,name,dictFirstNames,dictLastNames);
	}
	fix(dictFirstNames);
	fix(dictLastNames);
	cout<<"DictFirstNames"<<" "<<(int)dictFirstNames.size()<<" "<<"\n";
	impr(dictFirstNames);
	cout<<"DictLastNames"<<" "<<(int)dictLastNames.size()<<" "<<"\n";
	impr(dictLastNames);
	
	int Q;
	cin>>Q;
	getline(cin,dummy);
	for(int i=0;i<Q;i++){
		string str;
		getline(cin,str);
		cout<<str<<'\n';
		doIt(dictFirstNames,dictLastNames,str);
	}
}


