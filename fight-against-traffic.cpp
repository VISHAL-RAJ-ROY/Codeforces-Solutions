/*
PS - https://codeforces.com/problemset/problem/954/D
tut - https://codeforces.com/blog/entry/58519#comment-522033
code - https://codeforces.com/contest/954/submission/36535484
 */
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
vector<int> dist1;
vector<int> dist2;
vector<int> c;
vector<int> pre;
//int dist1[2000];
//int dist2[2000];
//int c[2000];
//int pre[2000];

int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    G.resize(n+2);
    dist1.resize(n+2,n);
    dist2.resize(n+2,n);
    pre.resize(n+2,0);
    c.resize(n+2,0);
    for(int i=0;i<m;i++)
    {
        int k,l;
        cin>>k>>l;
        G[k].push_back(l);
        G[l].push_back(k);
    }

    queue<int> q;
    q.push(s);
//    cout<<'\n';
    dist1[s]=dist2[t]=0;
    while(!q.empty())
    {
        int v = q.front();
//        cout<<v<<' '<<dist1[v]<<'\n';
        q.pop();
        for(int i=0;i<G[v].size();i++)
        {
            int u = G[v][i];
            if(dist1[u]<=dist1[v]+1) continue;
            q.push(u);
            dist1[u] = dist1[v]+1;
        }
    }

    q.push(t);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i=0;i<G[v].size();i++)
        {
            int u = G[v][i];
            if(dist2[u]<=dist2[v]+1) continue;
            q.push(u);
            dist2[u] = dist2[v]+1;
        }
    }

    for(int i=1;i<=n;i++)
    {
        c[dist1[i]]++;
    }

    pre[0]=1;
    for(int i=1;i<n;i++)
    {
        pre[i] = pre[i-1]+c[i];
    }

//    cout<<dist1[1]<<' '<<dist2[t]<<'\n';
    long long bad,tot;
    bad = 0;
    tot = n*(n-1)>>1;
    for(int i=1;i<=n;i++)
    {
        int k = dist1[t] - dist2[i] - 2;
        if(k<0) continue;
        bad += pre[k];
//        cout<<i<<" . "<<bad<<'\n';
        for(int j=0;j<G[i].size();j++)
        {
//            cout<<G[i][j]<<' '<<dist1[G[i][j]]<<'\n';
            if(dist1[G[i][j]] <= k) bad--;
        }

//        cout<<i<<' '<<k<<' '<<bad<<'\n';
    }

    cout<< tot - m - bad;
}