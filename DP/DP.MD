### Coin Game
#### General
The recursive approaches are kinda neat. You did figure out that on every step you have two options, either L or R. So all you have to do is traverse down these paths in the Recursion Tree, and select the maximum one. However, my "intuition" based approach in such scenarios is to have a max reference parameter, and pass that into the function call, whenever the value becomes greater than this passed parameter, replace it.
A much more elegant way is the one provided, you could just set up recursive calls such that:

`f(a, b) = max(f(a+1, b), f(a, b-1)).`

This does the max setting for you.

#### Optimizations
The second approach (which utilizes just 2 recursive sub-tree calls), has a hidden optimization. Instead of computing the Sum for every node in the tree, we are passing the Sum in as a parameter as well. This is easy because every time we make the recursive sub-call, we know the value of the elements that span that sub-array. This approach may be utilized whenever you're making sub-calls by stripping off some elements from the array.
`f(a, b) = max(sum(a, b) - f(a+1, b, sum(a+b)-v[a]), sum(a, b) - f(a, b-1, sum(a,b)-v[b]))`

### Coin Change
Note that you have an infinite supply of coins, and order does *NOT* matter. Hence the discriminator between various sets is the number of coins of each type, and not the order in which they appear.
Hence, every time I'll consider the first element of the Set of Coins, and make one of two choices. Either to keep this coin in the first answer, or not keep this coin.
Now if I keep this coin, I may re-use it, hence now I need to find the number of ways to make the reduced sum using the same coins.
If I don't keep this coin, I am going to remove it from my set, and find the answer for the same total value using the reduced set.

### Longest Increasing Subsequences
* Remember that in subsequence questions, it's a good idea to view from the point of view of the element rather than a container.
* The deciding element in this case, is the last element. Consider two IS ending at 11.. (10, 11) and (9, 11). When you're building on top of this, it doesn't matter whether you used 9 or 10, because later elements have to be bigger than 11.

### Ways to write n as sum of two or more positive integers
* Instead of looking at this problem as breaking down a number, you could instead look at it as building a number from the set (1 .. n-1) where each number may be used infinitely times. It then becomes your coin change problem.
* In this problem also (similar to coin change), the base case (i.e. column 0) value will be 1, even though you have been told to not include the single values (such as 4 = 4+0). This is because:
    * For the number n, the value n itself won't be considered in the set.
    * For the numbers less than n, you need to consider it's individual cases. For eg. for 4 when you consider 3. You need to consider the single 3+0 case, as that would give 3+1.
    
### Word Break Problem
* My intuitive solution to memoize the question, was to store a matrix of [l][r] which would be true if the substring from [l,r] was segmentable into words of the dictionary. However GfG proposed a more space efficient solution.
* Basically, you store a 1D matrix dp[N+1], where dp[i] is true if the substr from [0..i-1] is segmentable, i.e. we have fixed the l index at 0.
* Earlier, in my recursive call, I used to first check if the prefix is in the dictionary, and if so I called into the suffix (with a changed value for l). In the new Bottom Up approach, first I iterate over all possible values of the Partition Point, and the suffix for a particular iteration will be fixed at Partition Point + 1. The basic idea is that if the string from [0..partitionpoint] is in the dictionary (or can be broken into words of the dictionary).. and a string from [pp+1 .. j] is directly in the dictionary, then the string from [0..j] is segmentable into words of the dictionary.
* If j so happens to be the last index, then the whole string is segmentable.

### Rod Cutting and Rope Product Cutting (TODO)

### Longest Palindromic Subsequence
* This question is solvable similar to Longest Common Subequence, in that we can compare the first letter with the last letter, if they are equal, then they will be present in my LPS, if not it will either be the substring when Left is incremented, or when Right is decremented. You could also solve this by finding the LCS between the string and it's reversed string.

### Longest Palindromic Substring
* You can't solve this like the last one. In a subsequence, if the first and last were equal, then I could easily include it in my LPS because I am allowed to skip letters when forming a subsequence, however that's not the case for a Substring. A string is a palindrome only if the first and last letters are equal, and the substring in between is a palindrome as well. You can use this recursive property, to build a bottom up solution.


