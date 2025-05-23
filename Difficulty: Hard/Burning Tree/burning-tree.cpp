//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    private:
    Node* mapping(Node* root,int target, unordered_map<Node*,Node*>&mp)
    {
        if(!root) return NULL;
        Node* targetnode = NULL;
        queue<Node*>q;
        q.push(root); 
        
        while(!q.empty())
        {
            Node* frontNode = q.front();
            q.pop();
            if(frontNode->data  == target)
            {
                targetnode = frontNode;
            }
            
            
            // traverse and map with parent
            if(frontNode->left)
            {
                mp[frontNode->left] = frontNode;
                q.push(frontNode->left);
            }
            
            if(frontNode->right)
            {
                mp[frontNode->right] = frontNode;
                q.push(frontNode->right);
            }
            
        }
        
        return targetnode;
        
    }
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>mp;
        Node* targetNode = mapping(root,target,mp); 
        
        // gor the mappping
        unordered_map<Node*,bool>visited;
        queue<Node*>q;
        q.push(targetNode);
        visited[targetNode] = true;
        int time = 0;
        
    while(!q.empty())
    {
        
        bool flag  =  false;
        
        int n = q.size();
        for(int i = 0;i<n;i++)
        {
           
            Node* frontNode = q.front();
            q.pop();
        
        // traverse
        if(frontNode->left && !visited[frontNode->left])
        {
            flag = true;
            q.push(frontNode->left);
            visited[frontNode->left] = true;
        }
        
         if(frontNode->right && !visited[frontNode->right])
        {
            flag = true;
            q.push(frontNode->right);
            visited[frontNode->right] = true;
        }
        
        if(mp[frontNode] && !visited[mp[frontNode]])
        {
            q.push(mp[frontNode]);
            visited[mp[frontNode]] = true;
            flag = true;
        }
        
        }
       
        
        if(flag) time++;
          
    }
    
        return time;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends