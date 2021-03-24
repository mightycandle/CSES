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
pair<int,int> man;
bool isend(int i,int j){
	return (i==0 || i==n-1 || j==0 || j==m-1)&& (a[i][j]=='.' || a[i][j]=='A');
}
bool valid(int i,int j){
	return i>-1 && j>-1 && i<n && j<m && a[i][j]!='#';
}
vector<pair<int,int>> mons;
string moves="RULD";
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
int32_t main(){
	mangekyo();
	cin>>n>>m;
	a.assign(n,vector<char>(m));
	rep(i,n){
		rep(j,m){
			cin>>a[i][j];
			if(a[i][j]=='A'){
				man={i,j};
			}
			else if(a[i][j]=='M'){
				mons.pb({i,j});
			}
		}
	}
	if(isend(man.first,man.second)){
		cout<<"YES\n0";
		return 0;
	}
	int grid[n][m];
	rep(i,n)rep(j,m)grid[i][j]=inf;
	queue<pair<int,int>> q;
	for(auto p:mons){
		grid[p.first][p.second]=0;
		q.push(p);
	}
	bool vis[n][m];
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		pair<int,int> p=q.front();q.pop();
		if(vis[p.first][p.second])continue;
		vis[p.first][p.second]=1;
		rep(i,4){
			int nx=p.first+dx[i],ny=p.second+dy[i];
			if(!valid(nx,ny))continue;
			grid[nx][ny]=min(grid[nx][ny],grid[p.first][p.second]+1);
			q.push({nx,ny});
		}
	}
	q.push(man);
	memset(vis,0,sizeof(vis));
	grid[man.first][man.second]=0;
	int track[n][m];
	memset(track,-1,sizeof(track));
	pair<int,int> finish={-1,-1};
	bool found=0;
	while(!q.empty()){
		pair<int,int> p=q.front();q.pop();
		if(vis[p.first][p.second])continue;
		vis[p.first][p.second]=1;
		int x=p.first,y=p.second;
		if(isend(x,y)){
			finish={x,y};
			found=1;
			break;
		}
		rep(i,4){
			int nx=x+dx[i],ny=y+dy[i];
			if(!valid(nx,ny))continue;
			if(grid[nx][ny]<=grid[x][y]+1)continue;
			q.push({nx,ny});
			grid[nx][ny]=grid[x][y]+1;
			track[nx][ny]=i;
		}
	}
	if(!found){
		cout<<"NO\n";
		return 0;
	}
	string s="";
	pair<int,int> cur=finish;
	while(cur!=man){
		int i=track[cur.first][cur.second];
		s+=moves[i];
		cur.first-=dx[i];
		cur.second-=dy[i];
	}
	reverse(s.begin(),s.end());
	cout<<"YES\n"<<s.size()<<'\n'<<s;
}


void mangekyo(){
	srand(time(NULL));

	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
