#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
int32_t main(){
	mangekyo();
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> adj(n+1);
	rep(i,m){
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].pb({y,w});
	}
	vector<int> dist(n+1,inf);
	vector<bool> vis(n+1,0);
	priority_queue<pair<int,int>> pq;
	pq.push({0,1});
	dist[1]=0;
	while(!pq.empty()){
		pair<int,int> p=pq.top();
		pq.pop();
		if(vis[p.second])continue;
		vis[p.second]=1;
		for(auto q:adj[p.second]){
			if(vis[q.first])continue;
			if(dist[q.first]>dist[p.second]+q.second){
				dist[q.first]=dist[p.second]+q.second;
				pq.push({0-dist[q.first],q.first});
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<dist[i]<<' ';
 
	return 0;
}
void mangekyo(){
	srand(time(NULL));
 
	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}