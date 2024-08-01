//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node *build(int &postIdx, int inStart, int inEnd, int len, int in[], int post[])
    {
        if (postIdx < 0) 
            return NULL;
        if (inStart > inEnd)
            return NULL;
        int idx = inStart;
        for (; idx <= inEnd; ++idx)
            if (post[postIdx] == in[idx])
                break;
        Node *root = new Node(post[postIdx--]);
        root->right = build(postIdx, idx + 1, inEnd, len, in, post);
        root->left = build(postIdx, inStart, idx - 1, len, in, post);
        return root;
    }
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
        int postIdx = n - 1;
        return build(postIdx, 0, n - 1, n, in, post);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends