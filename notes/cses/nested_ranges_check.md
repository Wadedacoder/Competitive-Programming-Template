## Nested Ranges Check/Count

Given n ranges, your task is to determine for each range if it contains some other range and if some other range contains it.

A range [a,b] is nested inside range [c,d] if a >= c and b <= d

You can assume that the ranges are distinct.

You can make a directed graph where each range is a node and there is an edge from range [a,b] to range [c,d] if [a,b] is nested inside [c,d]. For each node, you need to calculate the in-degree and out-degree for the answer.

