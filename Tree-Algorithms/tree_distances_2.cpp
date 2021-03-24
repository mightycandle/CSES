#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
int n;
vector<vector<int>> adj;
vector<int> subs,cache,ans;
vector<bool> vis;
void dfs(int u=1,int par=0){
	if(vis[u])return;
	vis[u]=1;
	subs[u]=1;
	for(int v:adj[u]){
		if(v==par)continue;
		dfs(v,u);
		subs[u]+=subs[v];
		cache[u]+=cache[v]+subs[v];
	}
}
void dfs2(int u=1,int par=0){
	if(vis[u])return;
	vis[u]=1;
	for(int v:adj[u]){
		if(v==par)continue;
		ans[v]=ans[u]+n-2*subs[v];
		dfs2(v,u);
	}
}
int32_t main(){
	mangekyo();
	cin>>n;
	adj.assign(n+1,vector<int>());
	rep(i,n-1){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	cache.assign(n+1,0);
	vis.assign(n+1,0);
	subs.assign(n+1,0);
	ans.assign(n+1,0);
	dfs();
	vis.assign(n+1,0);
	ans[1]=cache[1];
	dfs2();
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';

	return 0;
}
void mangekyo(){
	srand(time(NULL));

	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
