#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define bit bitset<16>
using namespace std;
int inf=1e18,mod=1e9+7;
void mangekyo();
/**/
int32_t main(){
	mangekyo();
	int n;cin>>n;
	vector<bit> store;
	int ct=0,reach=(1<<n);
	bit bts=reach-1;
	map<int,bool> done;
	while(ct<reach){
		ct++;
		store.push_back(bts);
		int val=bts.to_ulong();
		done[val]=1;
		rep(i,n){
			int cur=val^(1<<i);
			bit xo=cur;
			if(done[cur])continue;
			bts=xo;
			break;
		}
	}
	for(bit b:store){
		rep(i,n)cout<<b[i];
		cout<<endl;
	}

	return 0;
}
void mangekyo(){
	srand(time(NULL));
	
}