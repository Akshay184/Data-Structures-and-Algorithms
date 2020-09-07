# Graph Theory

A graph is a data structure that is defined by two components :
1. A node or a vertex.
2. An edge E or ordered pair is a connection between two nodes u,v that is identified by unique pair(u,v). The pair (u,v) is ordered because (u,v) is not same as (v,u) in case of directed graph.The edge may have a weight or is set to one in case of unweighted graph.

![Graph image](./images/graph1.jpg)


## Breadth First Search (BFS)

BFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) and traverse the graph layerwise thus exploring the neighbour nodes (nodes which are directly connected to source node). You must then move towards the next-level neighbour nodes.

As the name BFS suggests, you are required to traverse the graph breadthwise as follows:

1. First move horizontally and visit all the nodes of the current layer
2. Move to the next layer

![BFS image](./images/graph1.jpg?raw=true "Title")

**Time Complexity** = O(V + E)

## Depth First Searcg (DFS)
The DFS algorithm is a recursive algorithm that uses the idea of backtracking. It involves exhaustive searches of all the nodes by going ahead, if possible, else by backtracking.

**Time Complexity** = O(V + E)

## Topological Sort

Topological sorting of vertices of a Directed Acyclic Graph is an ordering of the vertices in such a way, that if there is an edge directed towards vertex from vertex , then comes before . For example consider the graph given below:

![Toposort image](./images/graph1.jpg?raw=true "Title")

A topological sorting of this graph is: 1 2 3 4 5.

There are multiple topological sorting possible for a graph. For the graph given above one another topological sorting is: 1 2 3 5 4.

**Time Complexity** = O(V + E)

For topological sort for direted acyclic graph you can refer to [click here](https://cp-algorithms.com/graph/topological-sort.html)

## SSSP on DAG

The single source shortest path (SSSP) problem can be solved efficiently on a DAG in **O(V + E)** time. This is due to the fact that the nodes can be ordered in a topological ordering via toposort and processed sequentially. After find the topological order we can assign each vertex an infinite weight except for the starting one and then apply the relaxation in a sequential manner to get the shortest path.

