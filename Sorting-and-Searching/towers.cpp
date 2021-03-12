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
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	multiset<int> m;
	rep(i,n){
		multiset<int>::iterator itr=m.upper_bound(a[i]);
		if(itr!=m.end())m.erase(itr);
		m.insert(a[i]);
	}
	cout<<m.size();

	return 0;
}
void mangekyo(){
	srand(time(NULL));

	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
