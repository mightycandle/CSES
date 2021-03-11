#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
void mangekyo();
/**/
void fun(){
	int n,x;cin>>n>>x;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	map<int,int> fre;
	rep(i,n)fre[a[i]]++;
	map<int,vector<int>> idx;
	rep(i,n)idx[a[i]].push_back(i);
	rep(i,n){
		int cur=a[i];
		int req=x-a[i];
		if(!fre[cur] || !fre[req])continue;
		if(cur==req){
			if(idx[cur].size()>=2){
				cout<<idx[cur][0]+1<<' '<<idx[cur][1]+1<<endl;
				return;
			}
		}
		else{
			cout<<idx[cur][0]+1<<' '<<idx[req][0]+1<<endl;
			return;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
	return;
}
int32_t main(){
	mangekyo();
	fun();
 
	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
}