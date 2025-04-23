//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);

cout << "~" << "\n";
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void rightPosition(stack<int>&st,int element)
{
    if(st.empty() || st.top() <= element)
    {
        st.push(element);
        return;
    }
    // else do the rest opeartion
    int top = st.top();
    st.pop();
    
    rightPosition(st,element);
    st.push(top);
    
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty()) return;
   
   // elsse
   int top = s.top();
   s.pop();
   
   // use recurion
   sort(); // basically extarct all the things
   // now while returning at the currect position
   
   return rightPosition(s,top);
   
}