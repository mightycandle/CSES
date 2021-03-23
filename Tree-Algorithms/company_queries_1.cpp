#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
vector<int> par;
int n,m;
int32_t main(){
	mangekyo();
	cin>>n>>m;
	par.resize(n+1,-1);
	rep(i,n-1){
		int x;cin>>x;
		par[i+2]=x;
	}
	vector<vector<int>> qr(m);
	rep(i,m){
		int a,b;cin>>a>>b;
		qr[i]={a,b};
	}
	int l=log2(n);
	int dp[n+1][l+1];
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][0]=par[i];
	}
	for(int j=1;j<=l;j++){
		for(int i=1;i<=n;i++){
			if(dp[i][j-1]!=-1){
				dp[i][j]=dp[dp[i][j-1]][j-1];
			}
		}
	}
	for(auto v:qr){
		int u=v[0],k=v[1];
		bitset<20> bts=k;
		for(int i=20;i>=0;i--){
			if(bts[i])u=dp[u][i];
			if(u==-1)break;
		}
		cout<<u<<'\n';
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
