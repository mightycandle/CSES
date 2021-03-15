#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
int32_t main(){
	mangekyo();
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	vector<vector<int>> dp(n,vector<int>(m+1));
	dp[0][a[0]]=1;
	if(!a[0]){
		fill(dp[0].begin(),dp[0].end(),1);
	}
	for(int i=1;i<n;i++){
		int x=a[i];
		if(a[i]){
			for(int k:{a[i]-1,a[i],a[i]+1}){
				if(k>=1 && k<=m)
				dp[i][x]=(dp[i][x]+dp[i-1][k])%mod;
			}
		}
		else{
			for(int j=1;j<=m;j++){
				for(int k:{j-1,j,j+1}){
					if(k>=1 && k<=m)
					dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<+m;i++){
		ans=(ans+dp[n-1][i+1])%mod;
	}
	cout<<ans;

	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
}
