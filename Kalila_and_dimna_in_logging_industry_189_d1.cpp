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

struct LineContainer_sorted {
    int pos; vl M, B; // y = M[i]x+B[i]
    LineContainer_sorted() { pos = 0; }
    li divi( li a, li b ) { return a/b - (a^b && a%b); }
    bool is_bad() {
        int l = M.size()-1;
        //return (B[l-2]-B[l])*(M[l-1]-M[l-2]) <= (B[l-2]-B[l-1])*(M[l]-M[l-2]);
        return (B[l-2]-B[l])*1.0/(M[l]-M[l-2])*1.0 <= (B[l-2]-B[l-1])*1.0/(M[l-1]-M[l-2])*1.0;
    }
    void add( li slope, li intercept_y ) {
        M.push_back(slope); B.push_back(intercept_y);
        while( M.size() >= 3 && is_bad() ) M.erase(M.end()-2), B.erase(B.end()-2);
    }
    li query_non_dec_x( li x_val ) {
        int M_sz = M.size();
        if( pos >= M_sz ) pos = M_sz-1;
        while( pos < M_sz-1 && M[pos]*x_val+B[pos] > M[pos+1]*x_val+B[pos+1] ) pos++;
        return M[pos]*x_val+B[pos];
    }
    li bin_search_ans( li x_val ) {
        int M_sz = M.size(), l = 0, r = M_sz;
        while( l != r ) {
            int m = (l+r)/2;
            if( m+1 < M_sz && x_val*(M[m+1]-M[m]) >= B[m]-B[m+1] ) l = m+1;
            else r = m;
        }
        return M[l]*x_val+B[l];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    // read("rr.txt");
    int n; cin>>n; vl a(n+1,0), b(n+1,0), dp(n+1,0); FOR(i,1,n+1) cin>>a[i]; FOR(i,1,n+1) cin>>b[i];
    dp[1] = 0;
    LineContainer_sorted lon;
    FOR(i,2,n+1) {
        lon.add(b[i-1],dp[i-1]);
        dp[i] = lon.query_non_dec_x(a[i]);
    }
    cout<<dp[n]<<"\n";
    return 0;
}
