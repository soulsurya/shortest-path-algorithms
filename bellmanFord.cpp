//Author- Suryakant Chandrakar
//contact-785surya@gmail.com

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Struct for the edges of the graph
struct Edge
{
  int u; //start vertex of the edge
  int v; //end vertex of the edge
  int w; //w of the edge (u,v)
};

// Graph - it consists of edges
struct Graph
{
  int V;             // Total number of vertices in the graph
  int E;             // Total number of edges in the graph
  struct Edge *edge; // Array of edges
};

// Creates a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
  struct Graph *graph = new Graph;
  graph->V = V; // Total Vertices
  graph->E = E; // Total edges

  // Array of edges for graph
  graph->edge = new Edge[E];
  return graph;
}

// Printing the solution
void printArr(int arr[], int size)
{
  std::cout << "Shortest Distance Of Vertices from Source Vertex is :";
  int i;
  for (i = 0; i < size; i++)
  {
    cout << endl
         << arr[i];
  }
  cout << endl;
}

void BellmanFord(struct Graph *graph, int u)
{
  int V = graph->V;
  int E = graph->E;
  int distance[V];
  // Step 1: fill the distance array and predecessor array
  for (int i = 0; i < V; i++)
    distance[i] = INT_MAX;

  // Mark the source vertex
  distance[u] = 0;
  // Step 2: relax edges |V| - 1 times
  for (int i = 1; i <= V - 1; i++)
  {
    for (int j = 0; j < E; j++)
    {
      // Get the edge data

      int u = graph->edge[j].u;
      int v = graph->edge[j].v;
      int w = graph->edge[j].w;
      if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        distance[v] = distance[u] + w;
    }
  }

  // Step 3: detect negative cycle
  // if value changes then we have a negative cycle in the graph
  // and we cannot find the shortest distances
  for (int i = 0; i < E; i++)
  {
    int u = graph->edge[i].u;
    int v = graph->edge[i].v;
    int w = graph->edge[i].w;
    if (distance[u] != INT_MAX && distance[u] + w < distance[v])
    {
      cout << "Graph contains negative w cycle";
      return;
    }
  }
  // No negative weight cycle found!
  printArr(distance, V);
  return;
}

int main()
{
  // Create a graph
  int V = 4; // Total vertices
  int E = 5; // Total edges
  int S = 0; //Source index is 0
  // Array of edges for graph
  struct Graph *graph = createGraph(V, E);

  //new edge 0 --> 1
  graph->edge[0].u = 0;
  graph->edge[0].v = 1;
  graph->edge[0].w = 5;

  //new edge 0 --> 2
  graph->edge[1].u = 0;
  graph->edge[1].v = 2;
  graph->edge[1].w = 4;

  //new edge 1 --> 3
  graph->edge[2].u = 1;
  graph->edge[2].v = 3;
  graph->edge[2].w = 3;

  //new edge 2 --> 1
  graph->edge[3].u = 2;
  graph->edge[3].v = 1;
  graph->edge[3].w = 6;

  //new edge 3 --> 2
  graph->edge[4].u = 3;
  graph->edge[4].v = 2;
  graph->edge[4].w = 2;

  BellmanFord(graph, S); //S is the source vertex

  return 0;
}
