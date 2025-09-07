/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        
        // declare a priroty queue
        priority_queue<int,vector<int>,greater<int>>pq;
        
        // traverse the each head
        for(auto it:arr)
        {
            Node* current = it;
            
            // loop throyugh the list
            while(current)
            {
                pq.push(current->data);
                current = current->next;
            }
        }
        
        // now just traverse the queue and fetch the details
        
        Node* head = new Node(-1); //craeting a dummy node
        Node* current = head;
        
        while(!pq.empty())
        {
            int top = pq.top();
            pq.pop();
            Node* temp = new Node(top); // crearing a new node by usjng the data
            current->next = temp;
            current = temp;
        }
        
         return head->next;
        
    }
};






















