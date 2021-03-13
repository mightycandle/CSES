#include<bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int mod=1e9+7;
void mangekyo();
/**/
int main(){
	mangekyo();
	int n,m;cin>>n>>m;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		rep(j,m+1){
			dp[i][j]=dp[i-1][j];
			if(j-a[i-1]>=0)
				dp[i][j]=(dp[i][j]+dp[i][j-a[i-1]])%mod;
		}
	}
	cout<<dp[n][m];

	return 0;
}
void mangekyo(){
	srand(time(NULL));

	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
