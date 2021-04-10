#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
#define make(a,b,c) a.assign(b,c)
const int mod=1e9+7;
void mangekyo();
/**/
int n;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> order;
void dfs2(int u){
	if(vis[u])return;
	vis[u]=1;
	for(auto v:adj[u])
		dfs2(v);
	order.push_back(u);
}
vector<int> color,parent;
int cys=-1,cye=-1;
bool dfs(int u){
	color[u]=1;
	for(int v:adj[u]){
		if(color[v]==0){
			parent[v]=u;
			if(dfs(v))return 1;
		}
		else if(color[v]==1){
			cys=v;
			cye=u;
			return 1;
		}
	}
	color[u]=2;
	return 0;
}
bool cyclic(){
	make(color,n+1,0);
	make(parent,n+1,0);
	for(int i=1;i<=n;i++){
		if(color[i]==0 && dfs(i))
			break;
	}
	return (cys!=-1);
}
int32_t main(){
	mangekyo();
	int m;
	cin>>n>>m;
	make(adj,n+1,vector<int>());
	rep(i,m){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	if(cyclic()){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	order.clear();
	make(vis,n+1,0);
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		dfs2(i);
	}
	reverse(order.begin(),order.end());
	for(int i:order)cout<<i<<' ';
	
	return 0;
}
void mangekyo(){
	srand(time(NULL));
 
	#ifdef local
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}