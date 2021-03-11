#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
int n,m;
vector<vector<char>> a;
string dirs="RULD";
vector<int> dx={0,-1,0,1};
vector<int> dy={1,0,-1,0};
bool valid(pair<int,int> p){
	int x=p.first,y=p.second;
	return x>=0 && x<n && y>=0 && y<m && a[x][y]!='#';
}
int32_t main(){
	mangekyo();
	cin>>n>>m;
	a.assign(n,vector<char>(m));
	pair<int,int> b,e;
	rep(i,n){
		rep(j,m){
			cin>>a[i][j];
			if(a[i][j]=='A')
				b={i,j};
			else if(a[i][j]=='B')
				e={i,j};
		}
	}
	bool fl=0;
	bool vis[n][m];
	memset(vis,0,sizeof(vis));
	int track[n][m];
	memset(track,0,sizeof(track));
	queue<pair<int,int>> q;
	q.push(b);
	while(!q.empty()){
		pair<int,int> p=q.front();
		q.pop();
		if(vis[p.first][p.second])continue;
		vis[p.first][p.second]=1;
		if(p==e){
			fl=1;
			break;
		}
		rep(i,4){
			pair<int,int> next={p.first+dx[i],p.second+dy[i]};
			if(vis[next.first][next.second])continue;
			if(valid(next)){
				q.push(next);
				track[next.first][next.second]=i;
			}
		}
	}
	if(!fl){
		cout<<"NO\n";return 0;
	}
	pair<int,int> cur=e;
	string s="";
	while(cur!=b){
		int idx=track[cur.first][cur.second];
		s+=dirs[idx];
		cur.first-=dx[idx];
		cur.second-=dy[idx];
	}
	reverse(s.begin(),s.end());
	cout<<"YES\n"<<s.size()<<'\n'<<s;
 
	return 0;
}
void mangekyo(){
	srand(time(NULL));

}
