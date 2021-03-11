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
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	vector<int> pre=a;
	for(int i=1;i<n;i++){
		pre[i]+=pre[i-1];
	}
	int c=0,j=0;
	rep(i,n){
		if(pre[i]>m){
			while(j<i){
				int cur=pre[i]-pre[j];
				if(cur==m){
					c++;
					break;
				}
				if(cur<m)break;
				j++;
			}
		}
		c+=(pre[i]==m);
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
