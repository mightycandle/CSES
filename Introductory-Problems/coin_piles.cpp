#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
bool fun(){
	int a,b;cin>>a>>b;
	if(a==b && a==0)return 1;
	int x=2*a-b,y=2*b-a;
	if(x<0 || y<0 || x%3 || y%3)return 0;
	return 1;
}
int32_t main(){
	mangekyo();
	int t;
	cin>>t;
	while(t--){
		fun()?cout<<"YES\n":cout<<"NO\n";
	}

	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
}