#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;
class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};
int N = 14;

vector<vector<Edge>> graph(N, vector<Edge>());

void addEdge(int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
}

// Display

void displayGraph()
{
    for (int i = 0; i < N; i++)
    {
        cout << to_string(i) + "->";
        for (Edge e : graph[i])
        {
            cout << "(" + to_string(e.v) + "," + to_string(e.w) + ")";
        }
        cout << endl;
    }
}

void constructGraph()
{

    addEdge(5, 2, 0);
    addEdge(5, 0, 0);
    addEdge(4, 0, 0);
    addEdge(4, 1, 0);
    addEdge(11, 1, 0);
    addEdge(12, 1, 0);
    addEdge(13, 1, 0);
    addEdge(0, 10, 0);
    addEdge(10, 6, 0);
    addEdge(6, 7, 0);
    addEdge(2, 3, 0);
    addEdge(3, 6, 0);
    addEdge(1, 8, 0);
    addEdge(8, 9, 0);
    addEdge(9, 7, 0);
    displayGraph();
}

void DFS(int src, vector<bool> &vis, vector<int> &ans)
{
    vis[src] = true;
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
        {
            DFS(e.v, vis, ans);
        }
    }
    ans.push_back(src);
}

void topoDFS()
{
    vector<bool> vis(N, false);
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            DFS(i, vis, ans);
        }
    }
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
}

void topoBFS(){
    vector<int>ans;
    vector<int>indegree(N,0);

    for(int i=0;i<N;i++){
        for(Edge e:graph[i]){
            indegree[e.v]++;
        }
    }

    queue<int>que;
    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            que.push(i);
        }
    }


    while(que.size()!=0){
        int vtx=que.front();
        que.pop();

        ans.push_back(vtx);
        for(Edge e:graph[vtx]){
            if(--indegree[e.v]==0){
                que.push(e.v);
            }
        }
    }
    if(ans.size()!=N){
        cout<<"There is a Cycle"<<endl;
    }else{
        cout<<"NO cycle"<<endl;
    }

    for(int e:ans){
        cout<<e<<" ";
    }
}

int main()
{
    constructGraph();
    cout << endl;
    // topoDFS();
    topoBFS();
    return 0;
}