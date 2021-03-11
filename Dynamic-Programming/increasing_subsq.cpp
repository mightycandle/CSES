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
	vector<int> a(n);
	rep(i,n)cin>>a[i];
 
	vector<int> d(n+1,inf);
	d[0]=-inf;
	rep(i,n){
		int j=upper_bound(d.begin(),d.end(),a[i])-d.begin();
		if(d[j-1]<a[i] && a[i]<d[j])
			d[j]=a[i];
	}
	int ans=0;
	rep(i,n+1)ans=(d[i]<inf)?i:ans;
	cout<<ans;
	return 0;
}
void mangekyo(){
	srand(time(NULL));
 
	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
