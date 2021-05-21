#include<bits/stdc++.h>
using namespace std;
/**/
int main(){
	string s;
	cin>>s;
	int cur=1,n=s.size(),fin=1;
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1]){
			fin=max(fin,cur);
			cur=1;
		}
		else cur++;
	}
	cout << max(fin,cur) << "\n";
	
	return 0;
}
