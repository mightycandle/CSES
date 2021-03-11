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
	rep(i,n)cin>>a[i];
	int tot=0,neg=0,cur=0;
	rep(i,n){
		cur+=a[i];
		tot=max(tot,cur);
		if(a[i]<0)neg++;
		if(cur<0){
			cur=0;
		}
	}
	if(neg==n)cout<<*max_element(a.begin(),a.end());
	else cout<<tot<<endl;
	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
	#ifdef mightycandle
		freopen("/home/sashank/Downloads/input.txt","r",stdin);
		freopen(".out","w",stdout);
	#endif
}