/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define um(A,B) unordered_map <A, B>
#define us(A) unordered_set <A>
#define ms(A) multiset <A>
#define ifpresent(CON,VAL) (CON.find(VAL) != CON.end())
#define all(x) x.begin(),x.end()
#define ins insert
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define count_ones __builtin_popcountl
#define name(X) cout<<endl<< (#X) << endl
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sqr(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mem(x,val) memset((x),(val),sizeof(x))
#define rite(X) freopen(X,"w",stdout)
#define read(X) freopen(X,"r",stdin)
#define FOR(i,A,B) for( auto (i) = (A); (i) < (B); (i)++ )
#define FORN(i,A,B) for( auto (i) = (B); (i) >= (A); (i)-- )
#define ima INT_MAX
#define imi INT_MIN
#define lma LLONG_MAX
#define lmi LLONG_MIN
#define pv(X) name(X); FOR(i,0,sz(X)) { cout<<"  "<< (#X) <<"["<<i<<"] = "<<X[i]<<endl; }
#define pvv(X) name(X); FOR(j,0,sz(X)) { cout<<endl; cout<<"  "<< (#X) <<"["<<j<<"]"<<endl; FOR(i,0,sz(X[j])) { cout<<"    "<< (#X) <<"["<<j<<"]["<<i<<"] = "<<X[j][i]<<endl; } }
#define pus(X) name(X); for( auto t : X )  cout<<"  "<<t; cout<<endl;
#define pum(X) name(X); for( auto t : X ) cout<<"  "<< (#X) <<"["<<t.first<<"] = "<<t.second<<endl;

typedef double db;
typedef complex<db> cd;
typedef vector<cd> vcd;
typedef long long int li;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef unordered_map<int,int> umii;
typedef unordered_map<string,int> umsi;
typedef unordered_set<string> uss;
typedef unordered_set<int> usi;
typedef unordered_set<int, usi> usii;
typedef multiset<int> msi;
typedef multiset<string> mss;
typedef pair<li, li> ll;
typedef pair<li, ll> lll;
typedef vector<li> vl;
typedef vector<ll> vll;
typedef vector<lll> vlll;
typedef vector<vl> vvl;
typedef unordered_map<li,li> umll;
typedef unordered_map<string,li> umsl;
typedef unordered_set<string> uss;
typedef unordered_set<li> usl;
typedef unordered_set<li, usl> usll;
typedef multiset<li> msl;
typedef multiset<string> mss;

const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0/0.0;

struct Tree {
    int v;
     Tree * l;
     Tree * r;
    Tree() {}
    Tree( int val ) : v(val), l(NULL), r(NULL) {}
};
typedef Tree * tree;

void init( tree & root, int val ) {
    root = new Tree(val);
}

void pbt( tree & root, int tab = 2, char desig = 'T' ) {
    if( desig == 'T' ) name(root);
    if(!root) return;
    FOR(i,0,tab)cout<<" "; cout<<desig<<" : "; cout<<root->v; cout<<endl;
    pbt(root->l, tab+2, 'L');
    pbt(root->r, tab+2, 'R');
}

void initbt( vi & info, tree & root, int index ) {
    root = new Tree(info[index]);
    if( 2*index+1 >= info.size() ) return;
    int l = info[2*index+1]; if( l != -1 ) initbt(info, root->l, 2*index+1);
    if( 2*index+2 >= info.size() ) return;
    int r = info[index*2+2]; if( r != -1 ) initbt(info, root->r, 2*index+2); 
}

void split (tree t, int v, tree & l, tree & r) {
    if (!t)
        l = r = NULL;
    else if (v <= t->v)
        split (t->l, v, l, t->l),  r = t;
    else
        split (t->r, v, t->r, r),  l = t;
}

int main(int argc, char const *argv[])
{
    // tree root; 
    // init(root, 2);
    // init(root->l, 3); init(root->r, 4); 
    // init(root->l->l, 5); init(root->l->r,6); 
    // init(root->l->r->l,9);
    // pbt(root);
    vi g{15};//{1,4,6,7,8,9,10,11,15,17,25,26,29,30,31,60};
    FOR(i,0,sz(g)) {
        tree root2;
        cout<<"\n\n";
        watch(g[i]);
        vi v{15,7,30,3,9,25,60,-1,5,8,10,-1,29};
        //vi v{1,2,3};
        initbt(v,root2,0);
        //pbt(root2);
        tree l,r; split(root2,g[i],l,r);
        pbt(root2); pbt(l); pbt(r);
    }
    return 0;
}