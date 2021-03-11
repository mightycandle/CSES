#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
const int mod=1e9+7;
void mangekyo();
/**/
int32_t main(){
	mangekyo();
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char c;cin>>c;
			a[i][j]=(c=='.')?1:0;
		}
	}
	if(!a[0][0] || !a[n-1][n-1]){
		cout<<0<<endl;return 0;
	}
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	rep(i,n){
		rep(j,n){
			if((!a[i][j])||(!i && !j))continue;
			dp[i][j]+=(i?dp[i-1][j]%mod:0)%mod;
			dp[i][j]+=(j?dp[i][j-1]%mod:0)%mod;
		}
	}
	cout<<dp[n-1][n-1]%mod<<endl;
	
 
	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
}