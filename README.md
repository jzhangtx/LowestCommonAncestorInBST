Lowest Common Ancestor in BST (Please refer to the docx version of README for a better understanding)


The lowest common ancestor of two nodes p and q is the lowest node in the binary search tree that has both p and q as its descendants. A node is also considered a descendant of itself.

Given the root node and two nodes p and q in a binary search tree, return their lowest common ancestor.

Note: You can assume that p and q will be present in the tree.

lowest-common-ancestor-bst
Testing
Input Format
The first line contains an integer T denoting the number of test cases.

For each test case, the input has 3 lines:

The first line contains an integer n denoting the number of nodes in the tree (including the NULL nodes).
The second line contains n space-separated integers that will form the binary tree. The integers follow level order traversal of the tree where -1 indicates a NULL node.
The second line contains n space-separated integers that will form the binary tree. The integers follow level order traversal of the tree where -1 indicates a NULL node.
The third line contains 2 space-separated integers denoting the 0-based index of p and q in the above list.
Output Format
For each test case, the output contains a line with the value of the lowest common ancestor for p and q.

Sample Input
4
9
2 1 3 -1 -1 -1 5 4 7
6 7
7
6 3 21 -1 -1 -1 89
0 6
12
8 3 9 -1 4 -1 10 -1 -1 -1 12 11
1 6
4
28 14 -1 11
0 3
Expected Output
5
6
8
28