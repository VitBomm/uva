#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define MAX 20010
const int INF = 1000000000;
using namespace std;
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX,INF);
int path[MAX];
struct option
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};
void Dijtrans(int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,option> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    while(!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
        for(int i = 0 ; i < graph[u].size();i++)
        {
            pair<int, int> neighbor = graph[u][i];
            if(w+ neighbor.second < dist[neighbor.first])
            {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first, dist[neighbor.first]));
                path[neighbor.first] = u;
            }
        }
    }
}
int main()
{

    int q,n,m,s,t;
    int a,b,c;
    int i =0;
    cin>>q;
    while (q--) {
        i++;
        cin>>n>>m>>s>>t;
        graph = vector<vector<pair<int, int>>>(MAX+5, vector<pair<int, int>>());
        for(int i = 0 ; i <m;i++)
        {
            cin>>a>>b>>c;
            graph[b].push_back(pair<int, int>(a,c));
            graph[a].push_back(pair<int, int>(b,c));
        }
        dist = vector<int>(MAX,INF);
        Dijtrans(s);
            if(dist[t] == INF)
            {
                cout<<"Case #"<<i<<": unreachable"<<endl;
            }
            else
            {
                cout<<"Case #"<<i<<": "<<dist[t]<<endl;
            }
    }
    return 0;
}
