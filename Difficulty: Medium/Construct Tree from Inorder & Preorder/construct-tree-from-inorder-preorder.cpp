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
class Solution {
    int findPosition(int in[],int element,int n)
    {
        for(int i = 0;i<n;i++)
        {
            if(in[i] == element)
            {
                in[i] = INT_MAX;
                return i;
            }
        }
    }
private:
    Node* solve(int in[], int pre[], int inStart, int inEnd, int& preStart,int n){
        // base case
        if (inStart > inEnd) {
            return NULL;
        }
        
        // creating node
        int element = pre[preStart]; // basically 0th index of preorder
        Node* root = new Node(element);
        preStart++; // increment preStart
        
        int position = findPosition(in,element,n);
        
        root->left = solve(in, pre, inStart, position - 1, preStart,n);
        root->right = solve(in, pre, position + 1, inEnd, preStart,n);
        
        return root;
    }
    
public:
    Node* buildTree(int in[], int pre[], int n) {
        // Code here
        // unordered_map<int, int> mp; // mapping the inordered vector
        // for (int i = 0; i < n; i++) {
        //     mp[in[i]] = i; // mapping with element with index in inorder element
        // }
        
        int inStart = 0;
        int inEnd = n - 1;
        int preStart = 0;
        
        Node* root = solve(in, pre, inStart, inEnd, preStart,n);
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