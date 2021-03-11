#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
void mangekyo();
/**/
int32_t main(){
	mangekyo();
	int n;cin>>n;
	vector<int> a(n);
	int su=0;
	rep(i,n){
		cin>>a[i];su+=a[i];
	}
	sort(a.begin(),a.end());
	vector<int> vars={a[n/2]};
	if((n&1)^1)vars.push_back({a[n/2-1]});
	int tot=su;
	for(int v:vars){
		int cur=0;
		rep(i,n)cur+=abs(v-a[i]);
		tot=min(tot,cur);
	}
	cout<<tot<<endl;
	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
}