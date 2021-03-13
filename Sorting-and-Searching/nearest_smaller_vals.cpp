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
	int n;cin>>n;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	stack<int> st;
	rep(i,n){
		while(!st.empty() && a[st.top()]>=a[i]){
			st.pop();
		}
		cout<<(st.empty()?0:st.top()+1)<<' ';
		st.push(i);
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
