#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
vector<int> nop={};
void mangekyo();
/**/
vector<int> fun(){
	int n,m;
	cin>>n>>m;
	map<pair<int,int>,bool> mp;
	vector<vector<int>> adj(n);
	rep(i,m){
		int x,y;cin>>x>>y;
		x-=1,y-=1;
		adj[x].push_back(y);adj[y].push_back(x);
	}
	vector<int> ans(n,-1);
	bool fl=1;
	rep(i,n){
		if(ans[i]==-1){
			queue<int> q;
			q.push(i);
			ans[i]=0;
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int v:adj[u]){
					if(ans[u]==ans[v])return nop;
					if(ans[v]==-1){
						ans[v]=ans[u]^1;
						q.push(v);
					}
				}
			}
		}
	}
	rep(i,n)ans[i]=ans[i]?1:2;
	return fl?ans:nop;
}
int32_t main(){
	mangekyo();
	vector<int> ans=fun();
	if(!ans.empty()){
		for(int i:ans)cout<<i<<' ';
	}
	else cout<<"IMPOSSIBLE"<<endl;
 
	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
}