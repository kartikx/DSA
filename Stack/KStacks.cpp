/**
 * Implement K Stacks in a Single Array efficiently.
 */

/*

You'll construct a back chain, that is the Top Array will store the index
of the final elements that have been inserted in each stack.

1. Insertion
next[free] = top[n] // Set up the back link.
top[n] = free       // top[n] stores the index of current top element
arr[free] = val
free = next[free]   // update free.
Initially, free has been set up so that free[i] = i+1;

2. Removal
free = top[n]
top[n] = next[free] 

*/