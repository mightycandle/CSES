#include<bits/stdc++.h>
#include<unistd.h>
#define int long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
const int inf=1e18,mod=1e9+7;
/**/
void mangekyo();
int32_t main(){
	mangekyo();
	int n;
	cin>>n;
	vector<int> a(n);
	int su=0;
	rep(i,n){
		cin>>a[i];
		su+=a[i];
	}
	int psize=1ll<<n,idx=su;
	rep(c,psize){
		if(!c)continue;
		int cur=0;
		rep(j,n){
			if(c&(1<<j)){
				cur+=a[j];
			}
		}
		idx=min(idx,max(cur,su-cur)-min(cur,su-cur));
	}	
	cout<<idx;
	return 0;
}
void mangekyo(){
	srand(time(NULL));
 
	// subl();
}