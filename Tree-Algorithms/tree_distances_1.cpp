#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
void mangekyo();
/**/
vector<vi> adj;
vi dist,vis,fin;
int mx,last=-1;
void dfs1(int u,int par){
	if(vis[u])return;
	vis[u]=1;
	for(int v:adj[u]){
		if(vis[v]||v==par)continue;
		dist[v]=dist[u]+1;
		dfs1(v,u);
	}
}
void dfs2(int u){
	if(vis[u])return;
	vis[u]=1;
	for(int v:adj[u]){
		if(vis[v])continue;
		dist[v]=dist[u]+1;
		dfs2(v);
	}
}
int32_t main(){
	mangekyo();
	int n;
	cin>>n;
	adj.assign(n+1,vi());
	rep(i,n-1){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vis.assign(n+1,0);
	dist.assign(n+1,0);
	dfs1(1,0);
	mx=*max_element(dist.begin(),dist.end());
	rep(i,n+1){
		if(dist[i]==mx){
			last=i;
			break;
		}
	}
	vis.assign(n+1,0);
	dist.assign(n+1,0);
	dfs2(last);
	mx=*max_element(dist.begin(),dist.end());
	rep(i,n+1){
		if(dist[i]==mx){
			last=i;
			break;
		}
	}
	vector<int> d1=dist;
	vis.assign(n+1,0);
	dist.assign(n+1,0);
	dfs2(last);
	vector<int> d2=dist;
	vector<int> fin(n+1,0);
	for(int i=1;i<=n;i++)
		fin[i]=(d1[i]+d2[i]==mx)?max(d1[i],d2[i]):-1;
	queue<int> q;q.push(last);
	vis.assign(n+1,0);
	while(!q.empty()){
		int u=q.front();q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int v:adj[u]){
			if(vis[v])continue;
			fin[v]=(fin[v]>0)?fin[v]:fin[u]+1;
			q.push(v);
		}
	}
	for(int i=1;i<=n;i++)cout<<fin[i]<<' ';
	return 0;
}
void mangekyo(){
	srand(time(NULL));
 
	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}