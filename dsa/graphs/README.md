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

The single source shortest path (SSSP) problem can be solved efficiently on a DAG in **O(V + E)** time. This is due to the fact that the nodes can be ordered in a topological ordering via toposort and processed sequentially. 

After find the topological order we can assign each vertex an infinite weight except for the starting one and then apply the relaxation in a sequential manner to get the shortest path.

## Longest Path in DAG

It is similar to **SSSP on DAG** but what we do here is we multiply each edge weight with -1 and then calculate SSSP and after getting the weight array we again multily it by -1.

## Dijkstra's Algorithm

Dijkstra's algorithm is a single source shortest path (SSSP) algorithm with graphs with **non-negative edge weights**.

***Time Complexity*** -
- The theoretical minimum time complexity1 for the shortest path search problem is **O(VlogV + E)** which is the case when we use ****Fibonacci Heap**** in which the time complexity of insertion is ****O(log(n))****  and updation is ****O(1)****. But Fibonacci heap are not generally used due to their huge constant overhead and their implementaion complexity. 

- We can use data stuctures which can perform both operation insertion and updation in **O(logn)** time. In C++ we have two such data-structure **set and priority queue**. But the problem with priority queue is that it does not support the operation of removing an element that leads to a significant worse factor **log(E)** instead of **log(V)** (although in terms of complexity they are identical).

- We can improve the performance a little bit more if you don't store pairs in the containers, but only the vertex indices. In this case we must overload the comparison operator: it must compare two vertices using the distances stored in d[].

For more information about Dijkstra's algorithm refer to [1](https://cp-algorithms.com/graph/dijkstra.html) [2](https://cp-algorithms.com/graph/dijkstra_sparse.html)

## Bellman-Ford Algorithm

Bellman-Ford algorithm is also a single source shortest path (SSSP) algorithm like Dijkstra's algorithm but it can work also with **negative edge weights**. We can detect negative cycle using this algorithm. Time Complexity of this algorithm is **O(V * E)** because in this we have to relaxe all the edges (n - 1) times to propogate the changes. If we can relax a vertex even after (n - 1) operations that means there is a negative cycle and we update its distance to **- infinity** and to propogate this negative change we again need at most (n - 1) cycles of opeartion.

## Floyd-Warshall Algorithm

Floyd-Warhall is an **all pair shortest path algorithm (APSP)** algorithm with graphs with **non-negative weigths cycle**. Remember graphs can have negative edge weights but not a negative cycle.

Floyd-Warshall used the concept of dynamic programming for calculation the shortest path between two nodes by using the previously calculated distance. Time compleixty of Floyd-Warshall algorithm is **O(n3)**. 

## Bridges And Articulation Points

 A bridge is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases the number of connected components in the graph).
 
An articulation point (or cut vertex) is defined as a vertex which, when removed along with associated edges, makes the graph disconnected (or more precisely, increases the number of connected components in the graph).

We use the approach of dfs to find both the brides and articulation point in a graph in **O(V + E)** time complexity. We use the concept of intime of node and the low time (i.e. the ancestor to which it can reach via a back edge) and by using so calculate the brides and articulation point.

We can also find the bridges for dynamic graph (assuming the operation is only adding new edges). To get more informatiom refer to [Finding Bridges Online](https://cp-algorithms.com/graph/bridge-searching-online.html)

For detailed explantion of bridges and articulation point refet to -
- [Bridges](https://cp-algorithms.com/graph/bridge-searching.html)
- [Bridges Video](https://www.youtube.com/watch?v=ECKTyseo2H8&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=24&t=0s)
- [Articulation Points](https://cp-algorithms.com/graph/cutpoints.html)
- [Articulation Points Video](https://www.youtube.com/watch?v=iGGolqb6gDE&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=27&t=0s)

## Strongly Connected Components (Kosaraju's Algorithm)

- Run sequence of depth first search of graph G which will return vertices with increasing exit time tout, i.e. some list order.

- Build transposed graph GT. Run a series of depth (breadth) first searches in the order determined by list order (to be exact in reverse order, i.e. in decreasing order of exit times). Every set of vertices, reached after the next search, will be the next strongly connected component.

**Time Complexity** of the algorithm is **O(n + m)** because it is just two dfs.

## Travelling Salesman Problem 

TSP is a **NP-hard** and is not a NP-complete problem. In this problem we have to visit each city once and then return back to the starting city. Since this is a
NP-hard problem we can check for all the permutation and find the minimum sum path. Therefore the time complexity is **O(!n)**.

But we can optimize this problem using DP to solve it in **O(n2 * 2^n)** by storing the -
- The city that is visited last
- The mask which keeps the record of all the visited city till now.

