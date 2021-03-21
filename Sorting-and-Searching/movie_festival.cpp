#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
bool cmp(vector<int> a,vector<int> b){
	return a[1]<b[1];
}
int32_t main(){
	mangekyo();
	int n;
	cin>>n;
	vector<vector<int>> big(n);
	rep(i,n){
		int x,y;cin>>x>>y;
		big[i]={x,y};
	}
	sort(big.begin(),big.end(),cmp);
	int t=0,c=0;
	rep(i,n){
		if(t<=big[i][0]){
			t=big[i][1];
			c++;
		}
	}
	cout<<c;

	return 0;
}
void mangekyo(){
	srand(time(NULL));

	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
