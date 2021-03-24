#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
vector<vector<int>> adj;
vector<bool> vis,done;
int tracked=0;
vector<int> path,fin;
void dfs(int u){
	if(vis[u]){
		tracked=u;
		path.pb(u);
		return;
	}
	path.pb(u);
	vis[u]=1;
	done[u]=1;
	for(int v:adj[u]){
		dfs(v);
		if(tracked)return;
		path.pop_back();
	}
	vis[u]=0;
}
int32_t main(){
	mangekyo();
	int n,m;
	cin>>n>>m;
	adj.assign(n+1,vector<int>());
	rep(i,m){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
	}
	done.assign(n+1,0);
	for(int i=1;i<=n;i++){
		if(done[i])continue;
		vis.assign(n+1,0);
		dfs(i);
		if(tracked){
			break;
		}
	}
	if(!tracked || path.size()<2){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	int start=path.back();
	path.pop_back();fin.pb(start);
	while(path.back()!=start){
		fin.pb(path.back());
		path.pop_back();
		if(path.empty())break;
	}
	fin.pb(start);
	reverse(fin.begin(),fin.end());
	cout<<fin.size()<<'\n';
	for(int i:fin)cout<<i<<' ';
	
	return 0;
}
void mangekyo(){
	srand(time(NULL));

	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
