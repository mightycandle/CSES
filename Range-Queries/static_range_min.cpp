#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
void mangekyo();
/**/
int res,mod=1e9+7;
vector<int> t;
void build(vector<int>& a,int& n){
	while(n&(n-1)){
		n++;a.pb(0);
	}
	t.assign(2*n,0);
	for(int i=n;i<2*n;i++)t[i]=a[i-n];
	for(int i=n-1;i>0;i--)
		t[i]=min(t[i<<1],t[i<<1|1]);
}
void query(int node,int tl,int tr,int l,int r){
	if(tl>r || tr<l)return;
	if(tl>=l && r>=tr){
		res=min(res,t[node]);
		return;
	}
	int tm=(tl+tr)/2;
	query(node<<1,tl,tm,l,r);
	query(node<<1|1,tm+1,tr,l,r);
	t[node]=min(t[node<<1],t[node<<1|1]);
}
int32_t main(){
	mangekyo();
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	vector<vector<int>> qu(q,vector<int>(2));
	rep(i,q)cin>>qu[i][0]>>qu[i][1];
 
	build(a,n);
	for(vector<int> v:qu){
		int l=v[0]-1,r=v[1]-1;
		res=mod;
		query(1,0,n-1,l,r);
		cout<<res<<'\n';
	}
 
	return 0;
}
void mangekyo(){
	srand(time(NULL));
 
	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}