#include<bits/stdc++.h>
using namespace std;
/**/
int main(){
	int n;
	cin >> n;
	int tot=(n*(n+1))/2;
	if(tot&1){
		cout << "NO" << "\n";
		
		return 0;
	}
	cout << "YES" << "\n";
	vector<int> v;
	int curs=0,req=tot/2,sub=0;
	while(curs<req){
		v.push_back(n-sub);
		curs+=n-sub;
		sub++;
	}
	if(curs>req){
		curs-=v.back();
		v.pop_back();
		v.push_back(req-curs);
	}
	map<int,int>  mp;
	for(auto x:v){
		mp[x]=1;
	}
	vector<int>  aux;
	for(int i=1;i<n+1;i++){
		if(!mp[i])
			aux.push_back(i);
	}
	cout << aux.size() << "\n";
	for(auto it=aux.begin();it!=aux.end();it++){
		cout << *it << ' ';
	}
	cout << "\n";
	cout << v.size() << "\n";
	for(auto it=v.begin();it!=v.end();it++){
		cout << *it << ' ';
	}
	cout << "\n";
	return 0;
}
