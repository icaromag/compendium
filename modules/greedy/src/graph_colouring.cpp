/*
 * @Author: Marcello Marques
 */
#include <bits/stdc++.h>

using namespace std;

list<int> G[100];

void graphColoring(int V, int *result)
{
    result[0]  = 0;

    for (int u = 1; u < V; u++)
        result[u] = -1;

    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = 0;

    for (int u = 1; u < V; u++)
    {
        for (list<int>::iterator it = G[u].begin(); it != G[u].end(); ++it)
            if (result[*it] != -1)
                available[result[*it]] = 1;

        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == 0)
                break;

        result[u] = cr;

        for (list<int>::iterator it = G[u].begin(); it != G[u].end(); ++it)
            if (result[*it] != -1)
                available[result[*it]] = 0;
    }
}

// Avoid multiple definitions of main()

/*
int main()
{
    int n, e, u, v;

    while(cin >> n >> e)
    {
        for(int i = 0; i <= n; i++)
            G[i].clear();

        while(e--)
        {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int *sol = new int[n];
        graphColoring(n, sol);

        cout << "Graph: \n";
        for(int i = 0; i < n; i++)
            cout << sol[i] << endl;
    }

    return 0;
}
*/
