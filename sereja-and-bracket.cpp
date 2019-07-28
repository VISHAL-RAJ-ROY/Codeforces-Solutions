/*
Question -> http://codeforces.com/contest/380/problem/C
Submission by Tanuj Khattar -> http://codeforces.com/contest/380/submission/10520750 (Treap)
Submission by Tanuj Khattar -> http://codeforces.com/contest/380/submission/10520784 (Seg Tree)
 */
//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef unsigned long long int ULL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//Works for forward as well as backward iteration

#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
// #define sll(n) scanf("%lld",&n)
// #define lldout(n) printf("%lld\n",n)

#define DRT() int t; si(t); while(t--)

#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

typedef struct node{
	char val;
	int prior,size;
	int ans,cnt1,cnt2;
	struct node *l,*r;
}node;
typedef node* pnode;

int sz(pnode t)
{
	return t?t->size:0;
}
void upd_sz(pnode t)
{
	if(t)
		t->size = sz(t->l) + 1 + sz(t->r);
}


void reset(pnode t)
{
	t->cnt1 = (t->val==')'?1:0);
	t->cnt2 = (t->val=='('?1:0);
	t->ans = 0;
}


void combine(pnode &t,pnode l,pnode r)	//assuming t and l and r exists
{
	t->ans = l->ans + r->ans + min(l->cnt2,r->cnt1);
	t->cnt1 = l->cnt1;
	t->cnt2 = r->cnt2;
	if(l->cnt2 > r->cnt1)
		t->cnt2 += l->cnt2 - r->cnt1;
	else
		t->cnt1 += r->cnt1 - l->cnt2;
}



void operation(pnode t)
{
	if(!t) return ;

	pnode l = t->l, r = t->r;
	if(!l)
	{
		l = new node;
		l->cnt1 = l->cnt2 = l->ans = 0;	//we only need these 3 fields for the operation function
	}
	if(!r)
	{
		r = new node;
		r->cnt1 = r->cnt2 = r->ans = 0;
	}
	reset(t);
	pnode temp = new node;
	combine(temp,l,t);
	combine(t,temp,r);
	delete temp;
}

void split(pnode t,pnode &l,pnode &r,int pos,int add = 0 )
{
	if(!t)
		return void(l = r = NULL);
	
	int curr_key = add + sz(t->l);
	if(curr_key <= pos)	//stores the element at pos in left subtree.
		split(t->r,t->r,r,pos,curr_key + 1) , l = t;
	else 
		split(t->l,l,t->l,pos,add) , r = t;
	upd_sz(t);
	operation(t);
}

void merge(pnode &t,pnode l,pnode r)
{
	if(!l || !r)
		t = l?l:r;
	else if(l->prior > r->prior)
		merge(l->r,l->r,r) , t = l;
	else
		merge(r->l,l,r->l) , t = r;
	upd_sz(t);
	operation(t);
}

void init(pnode &t,char c)
{
	t->prior = rand();
	t->size = 1;
	t->cnt1 = (c==')'?1:0);
	t->cnt2 = (c=='('?1:0);
	t->ans = 0;
	t->l = t->r = NULL;
	t->val = c;
}

void print(pnode t)
{
	if(!t)
		return;
	print(t->l);
	cout<<t->val;
	print(t->r);
}

pnode Treap;

int main()
{
	string s;
	cin>>s;
	for(int i=0;i<SZ(s);i++)
	{
		pnode it = new node;
		init(it,s[i]);
		if(i == 0)
			Treap = it;
		else
			merge(Treap,Treap,it);
	}
	int q;
	si(q);
	while(q--)
	{
		int l,r;
		si(l);si(r);
		l--;r--;
		pnode left,mid,right;
		
		split(Treap,left,mid,l-1);
		split(mid,Treap,right,r - l);
		
		dout(2*Treap->ans);
		//trace5(l,r,Treap->size,Treap->cnt1,Treap->cnt2);
		//print(Treap);
		//cout<<endl;
		
		merge(mid,left,Treap);
		merge(Treap,mid,right);
	
	}
	return 0;
}