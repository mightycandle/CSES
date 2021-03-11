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
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	vector<vector<int>> big;
	rep(i,n){
		cin>>a[i];
		big.pb({a[i],i});
	}
	if(n==3){
		if(a[0]+a[1]+a[2]==k)cout<<"1 2 3";
		else cout<<"IMPOSSIBLE";
		return 0;
	}
	sort(big.begin(),big.end());
	rep(i,n){
		int l=0,r=n-1,req=k-a[i];
		while(l<r){
			if(big[l][1]==i)l++;
			else if(big[r][1]==i)r--;
			else if(big[l][0]+big[r][0]>req)r--;
			else if(big[l][0]+big[r][0]<req)l++;
			else{
				cout<<i+1<<' '<<big[l][1]+1<<' '<<big[r][1]+1;
				return 0;
			}
		}
	}
	cout<<"IMPOSSIBLE";

	return 0;
}
void mangekyo(){
	srand(time(NULL));

	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
