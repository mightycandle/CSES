#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
void mangekyo();
/**/
int xors;
vector<int> t;
void build(vector<int>& a,int& n){
	while(n&(n-1)){n++;a.pb(0);}
	t.assign(2*n,0);
	for(int i=n;i<2*n;i++)t[i]=a[i-n];
	for(int i=n-1;i>0;i--){
		t[i]=t[i<<1]^t[i<<1|1];
	}
}
void query(int node,int tl,int tr,int l,int r){
	if(tl>=l && tr<=r){
		xors=xors^t[node];
		return;
	}
	if(tl>r || tr<l)return;
	int tm=(tl+tr)/2;
	query(node<<1,tl,tm,l,r);
	query(node<<1|1,tm+1,tr,l,r);
	t[node]=t[node<<1]^t[node<<1|1];
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
 	for(vector<int> vq:qu){
 		xors=0;
 		query(1,0,n-1,vq[0]-1,vq[1]-1);
 		cout<<xors<<'\n';
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