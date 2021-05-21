#include<bits/stdc++.h>
#include<unistd.h>
	using namespace std;
	#define rep1(i,n) for(int i=1;i<(int)n;i++)
	
	#define tcT template<class T
	#define tcTU template<class T,class U
	#define tcTA template<class T,class ... Args
	#define each(x,a) for(auto x:a)
	tcT> using v=vector<T>;
	tcT>inline void print(T a){cout<<(a)<<endl;}
	tcT>inline void print(v<T> a){each(x,a)cout<<(x)<<' ';cout<<endl;}
	tcTA>inline void print(T& a,Args&... args){cout<<a<<' ';print(args...);}

/**/
int main(){
	int n;
	cin >> n;
	if(n==1){print(1);return 0;}
	if(n<4){print("NO SOLUTION");return 0;}
	if(n==4){print("2 4 1 3");return 0;}
	rep1(i,n+1)if(i&1)cout<<i<<' ';
	rep1(i,n+1)if((i&1)^1)cout<<i<<' ';
	cout<<endl;
	
	return 0;
}
