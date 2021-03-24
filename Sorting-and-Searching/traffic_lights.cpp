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
	int tot,n;
	cin>>tot>>n;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	set<int> s;
	s.insert(0);
	s.insert(tot);
	multiset<int> lens;
	lens.insert(tot);
	rep(i,n){
		auto high=s.lower_bound(a[i]);
		auto low=high;
		low--;
		lens.erase(lens.find(*high-*low));
		lens.insert(a[i]-*low);
		lens.insert(*high-a[i]);
		cout<<*--lens.end()<<' ';
		s.insert(a[i]);
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
