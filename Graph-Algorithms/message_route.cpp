#include<bits/stdc++.h>
#include<unistd.h>
namespace sash{
	using namespace std;
	#define int long long
	#define double long double
	#define mii map<int,int>
	#define vi vector<int>
	#define vb vector<bool>
	#define pb push_back
	#define pii pair<int,int>
	#define _f first
	#define _s second
	#define pmake make_pair
 
	#define F(i,a,b) for(int i=(int)a;i<(int)b;i++)
	#define B(u,a,b) for(int u=(int)a-1;u>(int)b-1;u--)
	#define rep1(i,n) F(i,1,n)
	#define rep(i,n) F(i,0,n)
	#define bac(i,n) B(i,n,0)
	#define all(v) (v).begin(),(v).end()
	#define each(x,v) for(auto x:v)
	#define revit(s) for(auto it=s.begin();it!=s.end();it++)
	#define R(s) reverse(all(s))
	
	#define tcT template<class T
	#define tcTU template<class T,class U
	#define tcTA template<class T,class ... Args
	#define read(T, ...) T __VA_ARGS__;rd(__VA_ARGS__)
	#define curtime() ((clock()-_c)/CLOCKS_PER_SEC)
	tcT>using v=vector<T>;
	tcT>using vv=vector<v<T>>;
	tcT>using pri=priority_queue<T>;
	tcT>using rpi=priority_queue<T,v<T>,greater<T>>;
	using vc=v<char>;using vs=v<string>;using vd=v<double>;
	using vvi=v<vi>;using vvb=v<vb>;using vvd=v<vd>;
 
	tcT>inline void rd(T& a){cin>>a;}
	tcT>inline void rd(v<T>& a){T x;rep(i,a.size()){cin>>x;a[i]=x;}}
	tcT>inline void rd(vv<T>& a){rep(i,a.size()){rd(a[i]);}}
	tcTU>inline void rd(pair<T,U>& p){cin>>p._f>>p.s;}
	tcTA>inline void rd(T& a,Args&... args){cin>>a;rd(args...);}
 
	tcT>inline void print(T a){cout<<(a)<<endl;}
	tcT>inline void print(v<T> a){each(x,a)cout<<(x)<<' ';cout<<endl;}
	tcT>inline void print(vv<T> a){each(x,a)print(x);}
	tcT>inline void print(set<T> a){revit(a)cout<<(*it)<<' ';cout<<endl;}
	tcTU>inline void print(pair<T,U>& p){cout<<p._f<<' '<<p.s<<endl;}
	tcTA>inline void print(T& a,Args&... args){cout<<a<<' ';print(args...);}
	
	inline int mintwo(int n){return __builtin_ctzll(n);}
	inline int maxtwo(int n){return (int)log2(n);}
	inline int onebits(int n){return __builtin_popcountll(n);}
	inline int ceil(int a,int b){return (a+b-1)/b;}
	inline void mangekyo();
	inline void subl(){
	#ifdef mightycandle
	freopen(".in","r",stdin);freopen(".out","w",stdout);
	#endif
	}double _c=clock();
	using i32=int32_t;
	
	tcT>inline T sum(v<T> a){T s=0;each(x,a)s+=x;return s;}
	tcT>inline T min(v<T> a){return *min_element(all(a));}
	tcT>inline T max(v<T> a){return *max_element(all(a));}
	tcTU>inline double pdiv(T a,U b){return (1.0*(a))/(1.0*(b));}
	tcT>inline void chxor(T& a,T b){a=a^b;}
	tcTU>inline void chmax(T& a,U b){if(a<b)a=b;}
	tcTU>inline void chmin(T& a,U b){if(a>b)a=b;}
	tcTU>inline T max(T a,U b){return a>b?a:b;}
	tcTU>inline T min(T a,U b){return a<b?a:b;}
 
	tcT>v<T> pre_sum(v<T> a){rep1(i,a.size())a[i]+=a[i-1];return a;}
	tcT>v<T> suf_sum(v<T> a){bac(i,a.size()-1)a[i]+=a[i+1];return a;}
	tcTU>T POW(T x,T y,U m){T a=1;while(y){if(y&1)a=(a*x)%m;x=(x*x)%m;y>>=1;}return a;}
	inline bool tle(){bool b=(curtime()>3);if(b)print("TLE");return b;}
	inline void yes(){print("YES");}
	inline void no(){print("NO");}
	
	#define INV(x) POW(x,mod-2,mod)
	#define gcd(a,b) __gcd(a,b)
	#define lcm(a,b) ((a*b)/__gcd(a,b))
	#define itos to_string
	#define ctoi(c) (c-'0')
	#define bit bitset<maxn>
 
	tcT>
	class Queue{
		queue<T> q;public:
		void push(T x){q.push(x);}
		void pop(){q.pop();}
		void clear(){while(!q.empty()){q.pop();}}
		bool empty(){return q.empty();}
		T top(){return q.front();}
		T back(){return q.back();}
		T size(){return q.size();}
		T out(){int u=q.front();q.pop();return u;}
	};
	tcT>
	class Stack{
		stack<T> s;public:
		void push(T x){s.push(x);}
		void pop(){s.pop();}
		void clear(){while(!s.empty()){s.pop();}}
		bool empty(){return s.empty();}
		T top(){return s.top();}
		T size(){return s.size();}
		T out(){int u=s.top();s.pop();return u;}
	};
 
	#define nex cout<<endl;
	#define cnex cerr<<endl;
	#define debug(x) cerr<<"cerr: "<<#x<<" is "<<x<<endl;
	#define debug2(x,y) debug(x)debug(y)
	#define TIME cerr<<"Time: "<<curtime();
	
	#define run() read(int,_t);rep1(_,_t+1)
	#define srun() int _t=1;rep1(_,_t+1)
	#define cases()  cout<<"Case #"<<_<<": ";
	#define test() cerr<<"Test #"<<_<<": "<<endl;
	#define nitro ios_base::sync_with_stdio(false);cin.tie(NULL);
}
using namespace sash;
const int inf=1e18,mod=1e9+7,maxn=30;
/**/
i32 main(){
	mangekyo();
	read(int,n,m);
	vvi adj(n);
	rep(i,m){
		read(int,x,y);
		x-=1,y-=1;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	vb vis(n);vi dist(n);
	vi path;path.pb(1);
	vvi track(n);
	Queue<int> q;q.push(0);
	while(!q.empty()){
		int u=q.out();
		vis[u]=1;
		each(v,adj[u]){
			if(vis[v])continue;
			vis[v]=1;
			dist[v]=dist[u]+1;
			q.push(v);path.pb(v+1);
			track[v].pb(u);
		}
	}
	if(!dist[n-1]){print("IMPOSSIBLE");return 0;}
 
	vi buff;
	int cur=n-1;
	buff.pb(cur);
	while(cur!=0){
		int u=track[cur].back();
		buff.pb(u);
		cur=u;
	}
	R(buff);
	print(buff.size());
	each(x,buff)cout<<x+1<<' ';
 
 
	
	TIME;
	return 0;
}
void sash::mangekyo(){
	nitro;
	srand(time(NULL));
 
	// subl();
}