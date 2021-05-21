#include<bits/stdc++.h>
using namespace std;
/**/
void init();
vector<int> dp(10001);
int main(){
	init();
	int n;
	cin >> n;
	
	for(int i=1;i<n+1;i++){
		cout << dp[i] << "\n";	
	}
	return 0;
}
void init(){
	dp[0]=dp[1]=0;
	dp[2]=6;
	dp[3]=28;
	dp[4]=96;
	dp[5]=252;
	dp[6]=550;
	for(int i=7;i<10001;i++){
		dp[i]=5*dp[i-1]-10*dp[i-2]+10*dp[i-3]-5*dp[i-4]+dp[i-5];
	}
}
