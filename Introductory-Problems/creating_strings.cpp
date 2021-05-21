#include<bits/stdc++.h>
using namespace std;
/**/
int main(){
	string s;
	cin >> s;
	
	int n=s.size();
	vector<int>  v;
	for(int i=0;i<n;i++)
		v.push_back(i);
	vector<vector<int>>  store;
	do{
		store.push_back(v);
	}while (next_permutation(v.begin(),v.begin()+n));
	set<string> tot;
	for(auto vv:store){
		string str="";
		for(auto x:vv){
			str+=s[x];
		}
		tot.insert(str);	
	}
	cout << tot.size() << "\n";
	for(auto it=tot.begin();it!=tot.end();it++){
		cout << *it << ' ';
	}
	cout << "\n";

	return 0;
}
