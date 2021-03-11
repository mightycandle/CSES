
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
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
	int moves=0;
	rep1(i,n){
		if(a[i]>a[i-1])continue;
		moves+=abs(a[i-1]-a[i]);
		a[i]=a[i-1];
	}
	cout<<moves;

	return 0;
}
void mangekyo(){
	srand(time(NULL));

	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}