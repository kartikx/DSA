#1. Dijkstra#
Time Complexity : O((E+V)logV) in my implementation, best case O(E + VlogV) using Fibonacci Heaps.
Source: https://www.youtube.com/watch?v=pSqmAO-m7Lk&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=18&t=426s

Dijkstra is a single source shortest path algorithm, applicable only on graphs with non-negative weights. The algorithm leverages this property by not re-visiting any node. If you've visited a node, since there aren't any negative edges, you can't then take any path to end up back at that node with a smaller value than before.

Dijkstra follows a greedy approach. We consider the shortest path to each neighbout at every step. Once you've visited a node, you can be sure it's value can't be decreased, because we pluck nodes following the order of most promising nodes.

We have a dist[V] and an adjacency matrix representation. We also store a Priority Queue structure, which allows us to selectively pick each time the Node with smallest dist value.

In the lazy Dijkstra video, we don't update the values of keys. For eg. If you'd already inserted (1,3) into your Queue, and before getting to that, you obtain (1,2). You'll just add (1,2) without doing anything to (1,3). If the library does provide an implementation to decrease key, then use it. Otherwise you'll have to search in the PQ for key=1, which could take O(N) and then insert this key O(logN). Instead we could just insert it in O(logN), and every time we pull out a key-val pair, we check if the val is < dist[key].

The problem with the Lazy implementation is that it adds Stale Values. Such redundant additions will be a lot, if the graph is dense.  We can improve upon this by using an Indexed Priority Queue (watch video on this sometime in the future). This variant is called the Eager Dijkstra's Algorithm, and allows us to update stale values in LogN.

*Revisit* the ending part of the video, once you've gone through Heaps, D-ary heaps.


#2. Bellman Ford#
Main Concept : To relax each edge V-1 times.
The shortest path from (s,v) will have path length 1,2 .. V-1 (because shortest path must be simple).
Now the path from source s to v containing 2 edges, can be considered as path from s to u with 1 edge, and then path from u to v. Where u are all vertices that have a directed edge to v.
Now before you get to 2 edges, you will have relaxed every edge for the 1 edge case. Hence the s to u path with 1 edge, is known to us. Now we just have to consider the direct edge. 
Hence, this is a DP algorithm. Since, max length possible is V-1, this loop iterates V-1 times.

After one iteration, you would have computed the shortest path from the source using just one edge. So for all vertices that are located 2 edges or more away, then the distance would (correctly) be infinite (for now). This will get rectified as you consider more edges.

https://comtechstash.wordpress.com/2013/12/23/bellman-ford-algorithm-an-intuitive-understanding/
https://www.youtube.com/watch?v=lyw4FaxrwHg&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=19

*Doubt* : The article says that on each iteration we compute d'(v,i) that is path from source to v using i edges. However, do a sample run. It doesn't always follow this?


#3. Shortest Path in Directed Acyclic Graphs.#
Main Concept : Use Topological Sort to define the order in which to relax.
DAGs are a special case where we can find the SSSP in O(E+V). The main idea is that for a vertex V, if you can find the shortest path to all vertices U, that come before V, then you just have to relax all edges corresponding to u->v. 
Hence, first find the topological sort (using DFS in O(E+V)) then iterate over those, and relax each edge outgoing from the current vertex.

At the end of the day, most of these Algorithms employ Relaxation, it's just employing clever relaxations to make use of the properties in your graph.

#4. Floyd Warshall #
This algorithm is used to compute All Source Shortest Paths.
Basic Idea : The shortest path from u to v, may consist of any of the V vertices (wait doesn't this cause repetitions?). We first consider possible paths for all pairs of vertices (u,v) with intermediate vertex as 0, then we improve upon this by considering intermediate vertex 1 as well, then 2 as well... so on till all vertices are allowed to be in the path.

Now consider an intermediate case, where we're checking for k vertices. The current path consists of u .. (0..k-1) .. v, hence if we insert the vertex K in between then it will now become u .. (0..k-1) .. k .. (0..k-1) .. v.

Hence, we can check d[k-1][u][v] > d[k-1][u][k] + d[k-1][k][j].

Note that we don't actually use a 3-d Array, because since we only need the previous value, we can keep updating the same d[u][v].

Time complexity : O(V^3)
