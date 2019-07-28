/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
** Problem Link -> https://codeforces.com/contest/380/problem/C
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

struct ut {
    int len, a, b;
};  

class segtree { // left and right inclusive
    private:
        ve<ut> v, tree; int n;
    public:
        segtree() {};
        void pp( ve<ut> & vf, char c ) { int l = (c=='('?1:0); vf.pb({0,l,1-l}); }
        segtree( st & arr ) { n = arr.length(); SEL(x,arr) pp(v,x); tree.assign(4*n+4,{0,0,0}); build(1,0,n-1); }
        bool ni( ut y ) { return (!y.len && !y.a && !y.b); }
        ut func( ut x, ut y ) { if(ni(x)) return y; if(ni(y)) return x; return {x.len+y.len+min(x.a,y.b),y.a+max(0,x.a-y.b),x.b+max(0,y.b-x.a)}; } // any associative function
        void build( int node, int l, int r ) {
            if( l == r ) tree[node] = {v[l].len,v[l].a,v[l].b};
            else { int m = (l+r)/2, le = 2*node, ri = 2*node+1; build(le,l,m); build(ri,m+1,r); tree[node] = func(tree[le],tree[ri]); }
        }
        ut query( int node, int l, int r, int ql, int qr ) {
            if( ql > qr ) return {0,0,0};
            else if( l == ql && r == qr ) return tree[node];
            else { int m = (l+r)/2; return func(query(2*node,l,m,ql,min(qr,m)),query(2*node+1,m+1,r,max(m+1,ql),qr)); }
        }
        // void update( int node, int l, int r, int index, int newval ) {
        //     if( l == r ) tree[node] = newval;
        //     else { int m = (l+r)/2; ( m<index ? update(2*node+1,m+1,r,index,newval):update(2*node,l,m,index,newval)); }
        // }
        int query(int l, int r) { return 2*query(1,0,n-1,l,r).len; } 
        // void update(int index, int newval) { update(1,0,n-1,index,newval); } 
        void pr(int index) { cout<<index<<" : {"<<tree[index].len<<","<<tree[index].a<<","<<tree[index].b<<"}\n"; }
};

int main() {
    ios_base::sync_with_stdio(0);
    // read("rr.txt");
    st s;cin>>s;
    // cout<<s;nl;
    segtree tr(s);
    // tr.pr(1);
    int q; cin>>q;
    FOR(i,0,q) {
        int x,y; cin>>x>>y; cout<<tr.query(x-1,y-1);nl;
    }
    return 0;
}
