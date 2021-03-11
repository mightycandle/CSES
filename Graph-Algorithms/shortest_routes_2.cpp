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
	int n,m,q;
	cin>>n>>m>>q;
	vector<vector<int>> adj(n,vector<int>(n,inf));
	rep(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		adj[a][b]=min(adj[a][b],c);
		adj[b][a]=min(adj[b][a],c);
	}
	vector<vector<int>> qu(q);
	rep(i,q){
		int a,b;cin>>a>>b;
		qu[i]={a-1,b-1};
	}
	rep(i,n)adj[i][i]=0;
	rep(k,n){
		rep(i,n){
			rep(j,n){
				adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
			}
		}
	}
	rep(i,n){
		rep(j,n){
			if(adj[i][j]==inf)adj[i][j]=-1;
		}
	}
	for(auto v:qu){
		cout<<adj[v[0]][v[1]]<<endl;
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
