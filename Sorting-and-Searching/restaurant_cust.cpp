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
	int n;
	cin>>n;
	vector<vector<int>> big;
	rep(i,n){
		int x,y;cin>>x>>y;
		big.pb({x,1});
		big.pb({y,-1});
	}
	sort(big.begin(),big.end());
	int tot=0,cur=0;
	for(auto i:big){
		cur+=i[1];
		tot=max(tot,cur);
	}
	cout<<tot;

	return 0;
}
void mangekyo(){
	srand(time(NULL));

	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
