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
	int w,h;
	cin>>w>>h;
	int dp[w+1][h+1];
	memset(dp,0,sizeof(dp));
	rep(i,w+1){
		rep(j,h+1){
			if(i^j)dp[i][j]=inf;
			for(int k=1;k<i;k++)
				dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
			for(int k=1;k<j;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
		}
	}
	cout<<dp[w][h];
 
	return 0;
}
void mangekyo(){
	srand(time(NULL));
 
	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
