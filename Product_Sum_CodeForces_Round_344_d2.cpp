/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
** Problem -> https://codeforces.com/problemset/problem/631/E
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
const li oo = 1e15; // don't use for long long
const double inf = 1.0/0.0;

struct Line {
    mutable li k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(li x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const li inf = LLONG_MAX;
    li div(li a, li b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(li k, li m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    li query(li x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    // read("rr.txt");
    int n; cin>>n; vl v(n+1,0), c(n+1,0), s(n+1,0), cc(n+1,0), ss(n+1,0); 
    FOR(i,1,n+1) cin>>v[i], s[i] = s[i-1]+v[i], c[i] = c[i-1]+i*v[i];
    LineContainer lon;
    li ma = c[n]; lon.add(v[1],s[1]-v[1]);
    FOR(i,2,n+1) {
        li ans = lon.query(i);
        ma = max(ma,ans+c[n]-s[i]);
        lon.add(v[i],s[i]-v[i]*i);
    }
    LineContainer ll2;
    ll2.add(v[n],s[n-1]-n*v[n]);
    FOR(i,n,1) {
        li ans = ll2.query(i);
        ma = max(ma,ans+c[n]-s[i-1]);
        ll2.add(v[i],s[i-1]-i*v[i]);
    }
    cout<<ma<<"\n";
    return 0;
}
