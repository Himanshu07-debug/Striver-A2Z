// GRAPH INPUT FORMAT IN MOST QUESTIONS :
// First line: N (number of nodes) && M(No. of edges )
// Following M lines with u & v integers to denote the edges

// NOTE -> Graph usually have 1-based indexing


// ADJACENCY MATRIX --------------------->>

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // this statement will be removed in case of directed graph
    }
    return 0;
}

// TIME -> O(M)
// SPACE -> O(N*N) [ COSTLY method, consuming n^2 locations ]


// ADJACENCY LIST -------------------------------------->>>

// To create an adjacency list, we will create an array of size n+1 where n is the number of nodes. 
// This array will contain a list, so in C++ list is nothing but the vector of integers.


int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);           // if u -> v (directed) , this line will not come
    }

    return 0;

}

// SPACE -> O(2*E) [undirected]  and O(E) [directed]


// FOR WEIGHTED GRAPH -------------------------------------------> 

// ADJACENCY MATRIX -> 

int main()
{
    int n, m;
    cin >> n >> m;

    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u][v] = wt;
        adj[v][u] = wt;  // this statement will be removed in case of directed graph
    }
    return 0;
}


// ADJACENCY LIST -->>

int main()
{
    int n, m;
    cin >> n >> m;

    vector< pair<int,int> > adj[n+1];

    for(int i = 0; i < m; i++)
    {
        int u, v ,wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));           // if u -> v (directed) , this line will not come
    }

    return 0;

}

