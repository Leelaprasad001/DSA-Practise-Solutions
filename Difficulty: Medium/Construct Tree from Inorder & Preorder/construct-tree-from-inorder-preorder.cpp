//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        if(n<=0)
        return NULL;
        
        Node *root = (Node*)malloc(sizeof(Node));
        root->data = pre[0];
        root->left = NULL;
        root->right = NULL;
        
        int *ptr = find(in,in+n,pre[0]);
        int index = ptr - in;
        
        int leftSize = index;
        int rightSize = n - index -1;
        
        Node *left = buildTree(in,pre+1,leftSize);
        Node *right = buildTree(in+index+1,pre+1+leftSize,rightSize);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends