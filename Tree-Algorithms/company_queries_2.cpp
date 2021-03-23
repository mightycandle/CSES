#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
vector<vector<int>> a,adj;
vector<int> path,dist;
vector<bool> vis;
void dfs(int u,int par){
	if(vis[u])return;
	vis[u]=1;
	path.pb(u);
	for(int v:adj[u]){
		if(v==par)continue;
		dist[v]=dist[u]+1;
		dfs(v,u);
		path.pb(u);
	}
}
int sz=0,res=inf,idx=-1;
vector<vector<int>> t;
void merge(int i){
	t[i][0]=min(t[i<<1][0],t[i<<1|1][0]);
	if(t[i][0]==t[i<<1][0])
		t[i][1]=t[i<<1][1];
	else
		t[i][1]=t[i<<1|1][1];
}
void build(){
	while(sz&(sz-1)){
		a.pb({0,0});
		sz++;
	}
	t.assign(sz<<1,vector<int>(2));
	rep(i,sz){
		t[i+sz]=a[i];
	}
	for(int i=sz-1;i>0;i--)
		merge(i);
}
void query(int v,int tl,int tr,int l,int r){
	if(tr<l || tl>r)return;
	if(l<=tl && tr<=r){
		if(t[v][0]<res){
			res=t[v][0];
			idx=t[v][1];
		}
		return;
	}
	int tm=(tl+tr)>>1;
	query(v<<1,tl,tm,l,r);
	query(v<<1|1,tm+1,tr,l,r);
}
int32_t main(){
	mangekyo();
	int n,m;
	cin>>n>>m;
	adj.resize(n+1,vector<int>());
	rep(i,n-1){
		int x;cin>>x;
		adj[x].pb(i+2);
	}
	vector<vector<int>> qr(m);
	rep(i,m){
		int a,b;cin>>a>>b;
		qr[i]={a,b};
	}
	dist.assign(n+1,0);
	vis.assign(n+1,false);
	dfs(1,0);
	vector<int> vec=path;
	for(int& i:vec){
		i=dist[i];
	}
	vector<int> occur(n+1,-1);
	rep(i,path.size()){
		int cur=path[i];
		if(occur[cur]>=0)continue;
		occur[cur]=i;
	}
	rep(i,path.size()){
		a.pb({vec[i],path[i]});
	}
	sz=a.size();
	build();
	for(auto v:qr){
		int l=occur[v[0]],r=occur[v[1]];
		if(l>r)swap(l,r);
		res=inf,idx=-1;
		query(1,0,sz-1,l,r);
		cout<<idx<<'\n';
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
