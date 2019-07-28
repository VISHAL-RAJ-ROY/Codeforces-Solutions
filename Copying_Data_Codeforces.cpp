/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define posLSB(X) __builtin_ctz(X)
#define num1bit(X) __builtin_popcount(X)
#define numlead0(X) __builtin_clz(X)
#define gcd(X,Y) __gcd(X,Y)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define ifpresent(CON,VAL) (CON.find(VAL) != CON.end())
#define all(x) x.begin(),x.end()
#define at(X,N) get<N>(X)
#define ins insert
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define count_ones __builtin_popcountl
#define nl cout<<"\n";
#define name(X) (#X)
#define watch(X) cout << (#X) << " is " << (X) << "\n"
#define sqr(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mem(x,val) memset((x),(val),sizeof(x))
#define rite(X) freopen(X,"w",stdout)
#define read(X) freopen(X,"r",stdin)
//FOR(i,1,10) gives 1,2,3,....,9 and FOR(i,10,1) gives 9,8,....,1 also FOR(it, end(v), begin(v)) and FOR(it, begin(v), end(v))
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define SEL(X,C) for( auto & X : C )
#define ima INT_MAX
#define imi INT_MIN
#define lma LLONG_MAX
#define lmi LLONG_MIN
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define tk(args...) take(args);

void err(istream_iterator<string> it) {} template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cout << *it << " = " << a << "\n"; err(++it, args...);}
void take() {} template<typename T, typename... Args> void take( T & a, Args & ... args ) { cin>>a; take(args...); }
template <class T> struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } T operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);} T operator()(tuple<uint64_t,uint64_t> x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(get<0>(x) + FIXED_RANDOM)^(splitmix64(get<1>(x) + FIXED_RANDOM) >> 1); } }; // T operator()(pair<uint64_t,uint64_t> x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1); } }; 
template <class L, class R> ostream & operator<<(ostream &os, pair<L,R> P) { return os << "(" << P.xx << "," << P.yy << ")"; } template<class L, class R> ostream &operator<<(ostream &os, tuple<L,R> P) {return os << "(" << get<0>(P) << "," << get<1>(P) <<")"; } template<class L, class R, class S> ostream &operator<<(ostream &os, tuple<L,R,S> P) { return os << "(" << get<0>(P) << "," << get<1>(P) << ","<< get<2>(P) <<")"; } template<class T, class A> ostream &operator<<(ostream& os, vector<T,A> V) {os /*<< name(V)<< " is "*/ << "\n"; FOR(i,0,sz(V)) os <<"  "<< name(V) << "["<<i<<"] = "<< V[i] << "\n"; return os; /*<<"\n";*/ } template<class T, class H, class P, class A> ostream &operator<<(ostream& os, unordered_set<T,H,P,A> S) { os /*name(S) << " is"*/<<" ["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class S, class T, class H, class P, class A> ostream &operator<<(ostream& os, unordered_map<S,T,H,P,A> M) { os /*name(S) << " is"*/<<"\n"; for( auto ELE : M ) os <<"  "<< name(M) << "["<<ELE.xx<<"] = "<< ELE.yy << "\n"; return os; /*<<"\n";*/ } template<class T, class C, class A> ostream &operator<<(ostream& os, multiset<T,C,A> S) { os /*name(S) << " is"*/<<"["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class T, class R> ostream &operator<<(ostream& os, gp_hash_table<T,null_type,custom_hash<R>> S) { os /*name(S) << " is"*/<<" ["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class T, class Z, class R> ostream &operator<<(ostream& os, gp_hash_table<T,Z,custom_hash<R>> M) { os /*name(S) << " is"*/<<"\n"; for( auto ELE : M ) os <<"  "<< name(M) << "["<<ELE.xx<<"] = "<< ELE.yy << "\n"; return os; /*<<"\n";*/ } template<class T, class R> ostream &operator<<(ostream& os, cc_hash_table<T,null_type,custom_hash<R>> S) { os /*name(S) << " is"*/<<" ["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class T, class Z, class R> ostream &operator<<(ostream& os, cc_hash_table<T,Z,custom_hash<R>> M) { os /*name(S) << " is"*/<<"\n"; for( auto ELE : M ) os <<"  "<< name(M) << "["<<ELE.xx<<"] = "<< ELE.yy << "\n"; return os; /*<<"\n";*/ }

using st = string; typedef long long int li; typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef tuple<int,int> i2; typedef tuple<int,int,int> i3; typedef vector<int> vi; typedef vector<ii> vii; typedef vector<i2> vi2; typedef vector<i3> vi3; typedef vector<iii> viii; typedef vector<vi> vvi; typedef vector<vvi> vvvi; typedef pair<li, li> ll; typedef pair<li, ll> lll; typedef tuple<li,li> l2; typedef tuple<li,li,li> l3; typedef vector<li> vl; typedef vector<ll> vll; typedef vector<l2> vl2; typedef vector<l3> vl3; typedef vector<lll> vlll; typedef vector<vl> vvl; typedef vector<vvl> vvvl; typedef double db; typedef complex<db> cd; typedef vector<cd> vcd; template <class S> using ve = vector<S>; template <class S> using gr = greater<S>; template <class S> using le = less<S>; template <class S, class T = le<S>> using ms =  multiset<S,T>; template <class S,class T = null_type, class R = size_t> using gp =  gp_hash_table<S,T,custom_hash<R>>; template <class S,class T = null_type, class R = size_t> using cc =  cc_hash_table<S,T,custom_hash<R>>; template <class S,class T, class R = size_t> using um =  unordered_map<S,T,custom_hash<R>>; template <class S, class R = size_t> using us =  unordered_set<S,custom_hash<R>>;

/*
Welcome to VISHAL RAJ ROY's template library :) the following are here to serve you>>
v_ = vector of '_'                   |    li = long long int      |   For fast insertion/deletion ->
vl = vector of long                  |    db = double             |               gp<T,S,R>
vi = vector of int                   |    st = string             |   For fast read/write -> cc<T,S,R>
supported:                           |    ii = pair<int,int>      |   For slow everything ->
1) vi, vvi, vvvi   4) vl, vvl, vvvl  |    iii = pair<int,ii>      |        um<T,S,R> .. R = ( size_t or uint64_t )
2) vii, viii       5) vll, vlll      |    i2 = tuple<int,int>     |        and us<T,R> .. R = ( size_t or uint64_t )
3) vi2, vi3        6) vl2, vl3       |    cdb = complex double    |   supported :
7) vcd                               |    i3 = tuple<int,int,int> |   int/li/pair -> int/li/string/pair...pair<int/li,int/li>
watch(X) is the WATCH DOG, it can print anything and everything, COULD'NT believe? just try it>> 
error(a,b,c,......) takes many parameters and shows you their true face>> 
tk(a,b,c,..) just sucks the variable from the stdin, pure black magic isn't it!>
*/

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0/0.0;

vi a;

class segtree_lazy { // left and right inclusive
    private:
        vi v; vii tree; int n; 
    public:
        segtree_lazy() {};
        segtree_lazy( vi & arr ) { n = sz(arr); SEL(x,arr) v.eb(x); tree.assign(4*n+4,{-1,-1}); }
        inline void upd_lazy( int node, ii val ) { tree[node] = val;  }
        inline void shift( int node ) { // shift may or may not require l and r depending on the query function
            if( tree[node].xx != -1 ) {    
                int le = (node<<1), ri = le+1; ii val = tree[node];
                int mm = (val.xx+val.yy)/2;
                upd_lazy(le,{val.xx,mm}); upd_lazy(ri,{mm+1,val.yy}); 
                tree[node] = {-1,-1};
            }
        }
        void query( int node, int l, int r, int index) {
            if( l == r ) { if(tree[node].xx != -1) {v[index] = a[tree[node].xx]; tree[node] = {-1,-1};} }
            else { 
                int m = (l+r)/2, le = (node<<1), ri = le+1; shift(node);
                if(index <= m) query(le,l,m,index); else query(ri,m+1,r,index); 
            }
        }
        void update( int node, int l, int r, int ul, int ur, int al, int ar ) {
            if( ul > ur ) return;
            else if( l == ul && r == ur ) upd_lazy(node,{al,ar}); 
            else {
                shift(node); int m = (l+r)/2, le = (node<<1), ri = le+1;
                update(le,l,m,ul,min(m,ur),al,min(m+al-ul,ar)); update(ri,m+1,r,max(ul,m+1),ur,max(al,m+al-ul+1),ar);
            }
        }
        int query(int index) { query(1,0,n-1,index); return v[index]; } 
        void update( int l, int r, int al, int ar ) { update(1,0,n-1,l,r,al,ar); }
};

int main() {
    ios_base::sync_with_stdio(0);
    // read("rr.txt");
    int n,m; cin>>n>>m; vi b(n,0); a.assign(n,0); FOR(i,0,n) cin>>a[i]; FOR(i,0,n) cin>>b[i]; segtree_lazy tr(b);
    FOR(i,0,m) {
        int ti; cin>>ti;
        if( ti == 1 ) { int x,y,k; cin>>x>>y>>k; x--;y--; tr.update(y,y+k-1,x,x+k-1); }
        else { int x; cin>>x; x--; cout<<tr.query(x)<<"\n"; }
    }     
    return 0;
}
