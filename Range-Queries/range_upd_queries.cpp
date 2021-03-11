#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
vector<int> t,upd;
vector<bool> lazy;
void build(vector<int>& a,int& n){
	while(n&(n-1)){
		n++;
		a.pb(0);
	}
	t.assign(n<<1,0);
	for(int i=n;i<(n<<1);i++)t[i]=a[i-n];
	for(int i=n-1;i>0;i--)
		t[i]=t[i<<1]+t[i<<1|1];
}
void apply(int v,int tl,int tr,int val){
	t[v]+=val*(tr-tl+1);
	if(tr==tl)return;
	upd[v]+=val;
	lazy[v]=1;
}
void pushdown(int v,int tl,int tr){
	if(!lazy[v])return;
	lazy[v]=false;
	int tm=(tl+tr)>>1;
	apply(v<<1,tl,tm,upd[v]);
	apply(v<<1|1,tm+1,tr,upd[v]);
	t[v]=t[v<<1]+t[v<<1|1];
	upd[v]=0;
}
void update(int v,int tl,int tr,int l,int r,int val){
	if(tl>r || tr<l)return;
	if(l<=tl && tr<=r){
		apply(v,tl,tr,val);
		return;
	}
	pushdown(v,tl,tr);
	int tm=(tl+tr)>>1;
	update(v<<1,tl,tm,l,r,val);
	update(v<<1|1,tm+1,tr,l,r,val);
	t[v]=t[v<<1]+t[v<<1|1];
}
int query(int v,int tl,int tr,int idx){
	if(tl>idx || tr<idx)return 0;
	if(idx==tl && tr==idx){
		return t[v];
	}
	pushdown(v,tl,tr);
	int tm=(tl+tr)/2;
	int ans=0;
	ans+=query(v<<1,tl,tm,idx);
	ans+=query(v<<1|1,tm+1,tr,idx);
	t[v]=t[v<<1]+t[v<<1|1];
	return ans;
}
int32_t main(){
	mangekyo();
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	vector<vector<int>> qu(m);
	rep(i,m){
		int t;cin>>t;
		qu[i].pb(t);
		if(t==1){
			int a,b,u;
			cin>>a>>b>>u;
			qu[i].pb(a-1);
			qu[i].pb(b-1);
			qu[i].pb(u);
		}
		else{
			int k;cin>>k;
			qu[i].pb(k-1);
		}
	}
	build(a,n);
	lazy.assign(n<<1,0);
	upd.assign(n<<1,0);
	for(vector<int> vq:qu){
 		if(vq[0]&1)
 			update(1,0,n-1,vq[1],vq[2],vq[3]);
 		else
 			cout<<query(1,0,n-1,vq[1])<<'\n';
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
