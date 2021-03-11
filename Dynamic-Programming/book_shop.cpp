#include<bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
void mangekyo();
/**/
int main(){
	mangekyo();
	int n,m;
	cin>>n>>m;
	vector<int> price(n),pages(n);
	rep(i,n)cin>>price[i];
	rep(i,n)cin>>pages[i];
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		rep(j,m+1){
			dp[i][j]=dp[i-1][j];
			if(j-price[i-1]>=0){
				dp[i][j]=max(dp[i][j],dp[i-1][j-price[i-1]]+pages[i-1]);
			}
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
