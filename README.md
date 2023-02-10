Tools
- C++

About:
This program provides the algorithm to the bin-packing problem where the goal is to fit an amount of items with varying sizes into the least bins as possible with a cap on how much each bin can carry. I coded both a brute force algorithm and a heuristic to the problem in C++ and compared the time it took for each solution. The brute force algorithm will take O(N!) time as it will need to constantly compare to make sure that each bin is fit to its maximum capacity. The heuristic will take O(N) time as it will just put the item into the next bin if there is no more space in the current bin. Though the brute force takes a considerable amount of time to complete, it will always find the optimal solution compared to the heuristic which takes considerably less time, though does not always create the optimal output.
