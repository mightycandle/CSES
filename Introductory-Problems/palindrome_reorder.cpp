#include<bits/stdc++.h>
using namespace std;
/**/
int main(){
	string s;
	cin>>s;
	sort(s.begin(),s.end());	
	set<char> uni;
	map<char,int> mp;
	for(auto x:s){
		uni.insert(x);
		mp[x]++;
	}
	vector<int>  cts;
	for(auto it=uni.begin();it!=uni.end();it++){
		cts.push_back(mp[*it]);
	}
	int fl=0;
	for(int i=0;i<(int)cts.size();i++){
		if(cts[i]&1)
			fl++;
	}
	if(fl>1){
		cout << "NO SOLUTION" << "\n";
		return 0;
	}
	string str="";
	char spl='$';
	for(auto it=uni.begin();it!=uni.end();it++){
		int oc=mp[*it];
		for(int i=0;i<oc/2;i++){
			str+=(*it);
		}
		if(mp[*it]&1)
			spl=(*it);

	}
	string rev=str;
	reverse(rev.begin(),rev.end());
	string fin=str;
	if(spl!='$')fin+=spl;
	fin+=rev;
	cout << fin << "\n";
	
	return 0;
}
