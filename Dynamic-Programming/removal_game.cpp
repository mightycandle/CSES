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
	int n;cin>>n;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	int dp[n][n][2];
	memset(dp,0,sizeof(dp));
	rep(i,n){
		dp[i][i][0]=a[i];
		dp[i][i][1]=0;
	}
	for(int diff=1;diff<n;diff++){
		for(int l=0;l+diff<n;l++){
			int r=l+diff;
			dp[l][r][0]=max(a[l]+dp[l+1][r][1],a[r]+dp[l][r-1][1]);
			dp[l][r][1]=min(dp[l+1][r][0],dp[l][r-1][0]);
		}
	}
	cout<<dp[0][n-1][0];

	return 0;
}
void mangekyo(){
	srand(time(NULL));

	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
