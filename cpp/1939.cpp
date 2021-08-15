#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
 
int N, M;
vector<pair<int, long long>> v[10010];
int start, arrive;
long long Max;
long long MaxCost;
 
bool BFS(int limit)
{
    queue<int> q;
    int visited[10010] = {0};
    
    q.push(start);
    visited[start] = 1;
    
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        
        if(x == arrive)
        {
            return true;
        }
        
        for(int i = 0; i < v[x].size(); i++)
        {
            if(visited[v[x][i].first] == 0 && v[x][i].second >= limit)
            {
                visited[v[x][i].first] = 1;
                q.push(v[x][i].first);
            }
        }
    }
    
    return false;
}
 
int main(void)
{
//    freopen("B1939_input.txt", "r", stdin);
    
    cin >> N >> M;
    
    for(int i = 1; i <= M; i++)
    {
        int from, to;
        long long cost;
        cin >> from >> to >> cost;
        
        v[from].push_back({to, cost});
        v[to].push_back({from, cost});
        
        MaxCost = max(MaxCost, cost);
    }
    
    cin >> start >> arrive;
    
    long long left = 1;
    long long right = MaxCost;
    
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        
        if(BFS(mid))
        {
            left = mid+1;    
            Max = mid;
        }
        else
        {
            right = mid-1;
        }
    }
    
    cout << Max << endl;
        
    return 0;
}
