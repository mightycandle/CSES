#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
const int maxn=100001;
void mangekyo();
/**/
int32_t main(){
	mangekyo();
	int n;cin>>n;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	int su=accumulate(a.begin(),a.end(),0);
	bitset<maxn> dp;dp.set(0);
	rep(i,n)dp|=dp<<a[i];dp[0]=0;
	cout<<dp.count()<<endl;
	rep(i,su+1)if(dp[i])cout<<i<<' ';
	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
}