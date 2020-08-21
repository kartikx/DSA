1. Video on Union Finding William Fiset.

# Graph Theory on Grids
1. A common approach when solving grid problems is to first convert the grid to an Adj. List or Adj. Matrix. This is done by first numbering each cell in the grid from [0, n). Now since edges will be present from each cell to its L,R, U, D you can construct the appropriate representation. This will allow you to use standard Graph algorithms on the grid you're trying to solve.
2. However a conversion isn't always necessary. As you've experienced, considering each position and moving L,R,U,D can be used to implement common algorithms.
3. In the dungeon problem statement, you're given a grid with a start, end, # representing rocks, and . representing empty cell. Your goal is to reach the exit using the shortest path possible. Since, this is an unweighted undirected graph, it screams BFS, so that's what we use.
4. Instead of maintaining a queue of pairs, you can maintain 2 queues, one for x and one for y. This implementation will translate well to higher dimesnions as well.
