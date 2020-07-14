# Rooting a Tree
* Whenever you traversing undirected graphs, you need to take care that you don't retraverse the parent which you just came from. However, you can do this check without needing a visited array. You could pass in the parent when doing the recursive call, and check within the function that child != parent.

# Center of an undirected Tree
This could be useful if we want to select a good node to root our tree.
The center of the Tree is defined as middle (or middle 2) nodes on the longest path of the tree. A tree may have 2 middle nodes, and it isn't necessary that the path found for getting these 2 nodes be the same, i.e. they may be the middle of 2 paths both of which are of maximal length.
The algorithm for this does not involve finding the longest path, and is in-fact much more subtle.

<TODO>: Solve using longest path.

* Isomorphic Trees
Checking whether two graphs are isomorphic is a tough problem. However, there exist simpler algo.s for checking whether two trees are isomorphic.

<TODO>: Isomorphism has another approach.
