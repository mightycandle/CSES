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
	vector<int> a(n+1);
	rep(i,n)cin>>a[i+1];
	int tot=0,tart=1;
	map<int,int> vis;
	for(int i=1;i<=n;i++){
		if(!vis[a[i]] || vis[a[i]]<start){
			vis[a[i]]=i;
		}
		else{
			tot=max(tot,i-start);
			start=vis[a[i]]+1;
			vis[a[i]]=i;
		}
	}
	tot=max(tot,n+1-start);
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
