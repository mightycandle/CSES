#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
int32_t main(){
	mangekyo();
	string s,r;
	cin>>s>>r;
	int n=s.size(),m=r.size();
	if(m>=n){
		cout<<(s==r)<<endl;
		return 0;
	}
	int p=31;
	vector<int> pows(n,1);
	for(int i=1;i<n;i++)
		pows[i]=(pows[i-1]*p)%mod;
	
	vector<int> ref(n+1,0);
	rep(i,n)
		ref[i+1]=(ref[i]+(pows[i]*(s[i]-'a'+1)))%mod;
 
	int hv=0;
	rep(i,m)
		hv=(hv+(r[i]-'a'+1)*(pows[i]))%mod;
 
	int count=0;
	rep(i,n-m+1){
		int cur=(ref[i+m]+mod-ref[i])%mod;
		int curhash=(hv*pows[i])%mod;
		count+=(cur==curhash);
	}
	cout<<count<<endl;
	
	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
}