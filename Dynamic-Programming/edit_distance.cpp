#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
void mangekyo();
/**/
int32_t main(){
	mangekyo();
	string a,b;cin>>a>>b;
 
	int n=a.size(),m=b.size();
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	rep(i,n+1)dp[i][0]=i;
	rep(i,m+1)dp[0][i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=min(1+dp[i-1][j],1+dp[i][j-1]);
			dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(a[i-1]!=b[j-1]));
		}
	}
	cout<<dp[n][m]<<endl;
	
 
	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
}