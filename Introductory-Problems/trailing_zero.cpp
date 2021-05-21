#include<bits/stdc++.h>
using namespace std;
/**/
int fun(int n){
	if(n<5)return 0;
	if(n<10)return 1;
	int exp=1,su=0,cur=n;
	while(cur){
		exp=(exp*5);
		cur=n/exp;
		su+=cur;
	}
	return su;
}
int main(){
	int n;
	cin >> n;
	cout << fun(n) << "\n";
	
	return 0;
}
