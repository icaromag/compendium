/*
 * @Author: Marcello Marques
 */
#include <bits/stdc++.h>

#define therms(type, func) type, vector<type>, func

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
int n_v, n_e;
const int V = 10001;
int dist[10001];
vector<ii> G[10001];

typedef struct mindist { bool operator()(const int& a, const int& b) const { return dist[a] > dist[b]; } } mindist;

void dijkstra(int root)
{
    for(int i = 1; i <= n_v; i++) dist[i] = INT_MAX;
    dist[root] = 0;

    priority_queue< therms(int, mindist) > pq;
    pq.push(root);

    while(!pq.empty())
    {
        int act = pq.top();
        pq.pop();

        for(vii::iterator it = G[act].begin(); it != G[act].end(); it++)
            if(dist[it->first] > dist[act] + it->second) {
                dist[it->first] = dist[act] + it->second;
                pq.push(it->first);
            }
    }
}

// Avoid multiple definitions of main()
/*
int main()
{
    int u, v, w, v_start, v_end;
    while(cin >> n_v)
    {
        for(int i = 0; i <= n_v; i++)
            G[i].clear();

        cin >> n_e;
        while(n_e--)
        {
            cin >> u >> v >> w;
            G[u].push_back(ii(v,w));
        }

        cin >> v_start >> v_end;
        dijkstra(v_start);
        cout << dist[v_end] << endl;
    }

    return 0;
}
*/