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
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n),b(m);
	rep(i,n)cin>>a[i];
	rep(i,m)cin>>b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int c=0,i=0,j=0;
	while(i<n && j<m){
		if(b[j]>=a[i]-k && b[j]<=a[i]+k)
			i++,j++,c++;
		else if(b[j]<a[i]-k)
			j++;
		else
			i++;
	}
	cout<<c;

	return 0;
}
void mangekyo(){
	srand(time(NULL));

	#ifdef mightycandle
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	#endif
}
