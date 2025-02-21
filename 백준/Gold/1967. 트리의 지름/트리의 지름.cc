#include <bits/stdc++.h>

using namespace std;

int n;
int startnode = 0;
int longweight = 0;
void dfs(int curnodeidx, int curweight, const vector<vector<pair<int,int>>> &tree, vector<bool> visited)
{
    bool canmove = false;
    visited[curnodeidx] = true;
    int len = tree[curnodeidx].size();
    for(int i = 0; i < len; i++)
    {
        if(!visited[tree[curnodeidx][i].first])
        {
            canmove = true;
            curweight += tree[curnodeidx][i].second;
            dfs(tree[curnodeidx][i].first,curweight,tree,visited);
            curweight -= tree[curnodeidx][i].second;
        }
    }
    if(!canmove)
    {
        if(curweight > longweight)
        {
            startnode = curnodeidx;
            longweight = curweight;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n;
    vector<vector<pair<int,int>>> tree(n + 1,vector<pair<int,int>>());
    vector<bool> visited(n + 1,false);
    for(int i = 0; i < n - 1; i++)
    {
        int start,end,weight;
        cin >> start >> end >> weight;
        tree[start].push_back({end,weight});
        tree[end].push_back({start,weight});
    }
    dfs(1,0,tree,visited);
    longweight = 0;
    dfs(startnode,0,tree,visited);
    cout << longweight;
    return 0;
}