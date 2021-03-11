#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
int32_t main(){
	mangekyo();
	int n;cin>>n;
	int val=1;
	while(n--){
		val=(val*2)%mod;
	}
	cout<<(val%mod);

	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
}