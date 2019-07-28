/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
*/

#include <bits/stdc++.h>

using namespace std;

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
using st = string; typedef long long int li; typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef tuple<int,int> i2; typedef tuple<int,int,int> i3; typedef vector<int> vi; typedef vector<ii> vii; typedef vector<i2> vi2; typedef vector<i3> vi3; typedef vector<iii> viii; typedef vector<vi> vvi; typedef vector<vvi> vvvi; typedef pair<li, li> ll; typedef pair<li, ll> lll; typedef tuple<li,li> l2; typedef tuple<li,li,li> l3; typedef vector<li> vl; typedef vector<ll> vll; typedef vector<l2> vl2; typedef vector<l3> vl3; typedef vector<lll> vlll; typedef vector<vl> vvl; typedef vector<vvl> vvvl; typedef double db; typedef complex<db> cd; typedef vector<cd> vcd; template <class S> using ve = vector<S>; template <class S> using gr = greater<S>; template <class S> using le = less<S>;

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0/0.0;


class segtree { // left and right inclusive
    private:
        vii tree; int n;
    public:
        segtree() {};
        segtree( int N ) { n = N; tree.assign(4*n+4,{ima,0}); }
        void update( int node, int l, int r, int ql, int qr, ii data ) {
            if( ql > qr ) return;
            else if( l == ql && r == qr ) tree[node] = data;
            else { int m = (l+r)/2, le = (node<<1), ri = le+1; update(le,l,m,ql,min(qr,m),data);update(ri,m+1,r,max(m+1,ql),qr,data); }
        }
        void query( int node, int l, int r, int index, ii & mi ) {
            if( l == r ) { int llk = tree[node].xx; if(llk<mi.xx) mi = tree[node]; }
            else { 
                int m = (l+r)/2, le = (node<<1), ri = le+1; 
                int llk = tree[node].xx; if(llk<mi.xx) mi = tree[node];
                ( m<index ? query(ri,m+1,r,index,mi):query(le,l,m,index,mi)); 
            }
        }
        int query(int index) { ii mi = {ima,0}; query(1,0,n-1,index,mi); return mi.yy; } 
        void update(int l, int r, ii data) { update(1,0,n-1,l,r,data); } 
};

int main() {
    ios_base::sync_with_stdio(0);
    // read("rr.txt");
    int n, m; cin>>n>>m; vi3 Q; segtree tr(n); 
    FOR(i,0,m) {
        int l,r,x; cin>>l>>r>>x; Q.eb(l,r,x);
    }    
    FOR(i,m,0) {
        int l,r,x; tie(l,r,x) = Q[i]; l--; r--; 
        tr.update(l,x-2,{i,x}); tr.update(x,r,{i,x});
    }
    FOR(i,0,n) 
        {if(i>0)cout<<" ";cout<<tr.query(i);} cout<<"\n";
    return 0;
}
