#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
void mangekyo();
int inf=LLONG_MAX;
/**/
vector<vector<int>> adj,euler;
vector<bool> vis;
vector<int> dist,t;
void dfs1(int u,int par){
	if(vis[u])return;
	vis[u]=1;
	for(auto v:adj[u]){
		if(par^v){
			dist[v]=dist[u]+1;
			dfs1(v,u);
		}
	}
}
void dfs2(int u,int par){
	euler.push_back({u,dist[u]});
	for(auto v : adj[u]){
		if(par^v){
			dfs2(v,u);
			euler.push_back({u,dist[u]});
		}
	}
}
int res;
void build(vector<int>& a,int& n){
	while(n&(n-1)){
		n++;
		a.pb(0);
	}
	t.assign(2*n,0);
	for(int i=n;i<2*n;i++)t[i]=a[i-n];
	for(int i=n-1;i>0;i--)
		t[i]=min(t[i<<1],t[i<<1|1]);
}
void query(int v,int tl,int tr,int l,int r){
	if(tl>=l && tr<=r){
		res=min(res,t[v]);
		return;
	}
	if(tl>r || tr<l)return;
	int tm=(tl+tr)>>1;
	query(v<<1,tl,tm,l,r);
	query(v<<1|1,tm+1,tr,l,r);
	t[v]=min(t[v<<1],t[v<<1|1]);
}
int32_t main(){
	mangekyo();
	int n,q;
	cin>>n>>q;
	adj.resize(n+1,vector<int>());
	rep(i,n-1){
		int x,y;cin>>x>>y;
		adj[x].pb(y);adj[y].pb(x);
	}
	vector<vector<int>> qu;
	rep(i,q){int x,y;cin>>x>>y;qu.pb({x,y});}
	vis.assign(n+1,0);
	dist.assign(n+1,0);
	dfs1(1,0);
	dfs2(1,0);
	vector<int> jidx,jdist;
	for(auto v:euler){
		jidx.pb(v[0]);
		jdist.pb(v[1]);
	}
	vector<int> ridx(n+1);
	rep(i,jdist.size()){
		ridx[jidx[i]]=i;
	}
	int sz=jdist.size();
	build(jdist,sz);
	for(auto vec:qu){
		int u=vec[0],v=vec[1];
		if(u==v)cout<<0<<'\n';
		else if(u==1 || v==1)cout<<dist[max(u,v)]<<'\n';
		else{
			res=inf;
			int l=ridx[u],r=ridx[v];
			if(l>r)swap(l,r);
			query(1,0,sz-1,l,r);
			cout<<dist[u]+dist[v]-2*res<<'\n';
		}
	}
 
	return 0;
}
void mangekyo(){
	srand(time(NULL));
 
	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
