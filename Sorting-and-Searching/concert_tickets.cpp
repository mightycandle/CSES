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
	int n,m;cin>>n>>m;
	vector<int> a(n),b(m);
	rep(i,n)cin>>a[i];
	rep(i,m)cin>>b[i];
	multiset<int,greater<int>> s;
	rep(i,n)s.insert(a[i]);
	rep(i,m){
		auto it=s.lower_bound(b[i]);
		if(it==s.end())cout<<"-1\n";
		else{
			cout<<*it<<'\n';
			s.erase(it);
		}
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
