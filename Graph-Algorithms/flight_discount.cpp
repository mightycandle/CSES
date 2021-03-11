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
	vector<vector<pair<int,int>>> adj;
	adj.assign(n+1,vector<pair<int,int>>());
	priority_queue<int> wts;
	rep(i,m){
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].pb({y,w});
		wts.push(w);
	}
	bool weird=0,flag=0;
	int bigger=wts.top();wts.pop();
	int big=wts.top();
	weird=((bigger/2)>=big);
	bool vis[n+1];
	memset(vis,false,sizeof(vis));
	vector<int> dist(n+1,inf);
	priority_queue<pair<int,int>> pq;
	pq.push({0,1});
	vector<pair<int,int>> track(n+1);
	dist[1]=0;
	while(!pq.empty()){
		pair<int,int> p=pq.top();
		pq.pop();
		if(vis[p.second])continue;
		vis[p.second]=1;
		for(auto q:adj[p.second]){
			if(vis[q.first])continue;
			if(dist[q.first]>dist[p.second]+q.second){
				if(weird && !flag && q.second==bigger){
					flag=1;
					q.second/=2;
				}
				dist[q.first]=dist[p.second]+q.second;
				pq.push({0-dist[q.first],q.first});
				track[q.first]={p.second,q.second};
			}
		}
	}
	int c=0,mx=0,cur=n;
	while(track[cur].first){
		mx=max(mx,track[cur].second);
		c+=track[cur].second;
		cur=track[cur].first;
	}
	if(!weird || (weird && !flag))
		cout<<c-mx+(mx/2);
	else cout<<c;

	return 0;
}
void mangekyo(){
	srand(time(NULL));

	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
