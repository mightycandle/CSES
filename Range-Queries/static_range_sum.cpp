#include<bits/stdc++.h>
#define int long long
#define vvi vector<vector<int>>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
vector<int> t;
int query(int node,int tl,int tr,int l,int r){
	if(tl>r||tr<l)return 0;
	if(l<=tl && tr<=r)return t[node];
	int tm=(tl+tr)>>1;
	int ans=0;
	ans+=query(node<<1,tl,tm,l,r);
	ans+=query(node<<1|1,tm+1,tr,l,r);
	return ans;
}
int32_t main(){
	mangekyo();
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	vvi quer(q,vector<int>(2));
	rep(i,q)cin>>quer[i][0]>>quer[i][1];
	bool flag=n&(n-1);
	while(flag){
		n++;
		a.push_back(0);
		flag=n&(n-1);
	}
	t.assign(n<<1,0);
	for(int i=n;i<(n<<1);i++)
		t[i]=a[i-n];
	for(int i=n-1;i>0;i--)
		t[i]=t[i<<1]+t[i<<1|1];
	rep(i,q){
		int l=quer[i][0]-1,r=quer[i][1]-1;
		cout<<query(1,0,n-1,l,r)<<'\n';
	}
	
	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
}