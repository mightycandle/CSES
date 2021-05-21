#include<bits/stdc++.h>
using namespace std;
/**/
vector<vector<int>>  store;
void fun(int n,int a,int b,int c){
	if(n==1){store.push_back({a,c});return;}
	fun(n-1,a,c,b);
	store.push_back({a,c});
	fun(n-1,b,a,c);
}
int main(){
	int n;
	cin >> n;
	
	fun(n,1,2,3);
	cout << store.size() << "\n";
	for(auto x:store){
		for(auto y:x){
			cout << y <<' ';
		}
		cout << endl;
	}
	return 0;
}
