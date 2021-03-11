#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
/**/
int n,m;
vector<string> grid;
bool valid(int i,int j){
	return i>=0 && i<n && j>=0 && j<m && grid[i][j]=='.';
}
map<pair<int,int>,bool> done;
void dfs(int u,int v){
	if(done[{u,v}])return;
	done[{u,v}]=1;
	rep(i,4){
		if(valid(u+dx[i],v+dy[i]))
			dfs(u+dx[i],v+dy[i]);
	}
}
int32_t main(){
	mangekyo();
	cin>>n>>m;
	grid.assign(n,"");
	rep(i,n){
		cin>>grid[i];
	}
	int ct=0;
	rep(i,n){
		rep(j,m){
			if(grid[i][j]=='.' && !done[{i,j}]){
				dfs(i,j);
				ct++;
			}
		}
	}
	cout<<ct;
	return 0;
}
void mangekyo(){
	srand(time(NULL));
 
	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
