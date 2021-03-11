#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
void fun(){
	int n;
	cin>>n;
	cout<<n<<' ';
	while(n!=1){
		n=(n&1)?(3*n+1):(n/2);
		cout<<n<<' ';
	}
}
int32_t main(){
	mangekyo();
	fun();
	
	return 0;
}
void mangekyo(){
	srand(time(NULL));
 
	// subl();
}