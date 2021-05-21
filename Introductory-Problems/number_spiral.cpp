#include<bits/stdc++.h>
using namespace std;
/**/
int fun(){
	int x;
	int y;
	cin >> x >> y;
	
	if(x==y)return (x*x)-x+1;
	if(x>y){
		if(x&1){
			return (x-1)*1ll*(x-1)+y;
		}
		return x*1ll*x-y+1;
	}
	if(y&1){
		return y*1ll*y-x+1;
	}
	return (y-1)*1ll*(y-1)+x;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cout << fun() << "\n";
			
	}
	
	return 0;
}
