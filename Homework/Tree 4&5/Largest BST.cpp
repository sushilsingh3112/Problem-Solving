  class Solution{
    public:
    class Info
    {
      public:
        int maximum;
        int minimum;
        bool isBST;
        int size;
    };
    Info solve(Node *root, int & maxSize)
    {
        if(root == NULL)
            return {INT_MIN, INT_MAX, true, 0};
        Info left = solve(root -> left, maxSize);
        Info right = solve(root -> right, maxSize);
        Info currentNode;
        currentNode.size = left.size + right.size + 1;
        currentNode.maximum = max(root -> data, right.maximum);
        currentNode.minimum = min(root -> data, left.minimum);
        if(left.isBST && right.isBST && (root -> data > left.maximum) && (root -> data < right.minimum))
            currentNode.isBST = true;
        else
            currentNode.isBST = false;
        if(currentNode.isBST)
            maxSize = max(maxSize, currentNode.size);
        return currentNode;
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        //Your code here
        int maxSize = 0;
        Info temp = solve(root, maxSize);
        return maxSize;
    }
