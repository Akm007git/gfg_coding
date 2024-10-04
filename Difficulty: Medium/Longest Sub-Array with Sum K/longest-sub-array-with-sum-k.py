#User function Template for python3

class Solution:
    def lenOfLongSubarr(self, arr, n, k):
        # Dictionary to store prefix sums
        prefix_sum_map = {}
        prefix_sum = 0
        max_length = 0
        
        for i in range(n):
            # Add the current element to the prefix sum
            prefix_sum += arr[i]
            
            # If the prefix sum itself is equal to k, update max_length
            if prefix_sum == k:
                max_length = i + 1  # Subarray from index 0 to i
                
            # If (prefix_sum - k) is found in the map, a subarray with sum k exists
            if (prefix_sum - k) in prefix_sum_map:
                max_length = max(max_length, i - prefix_sum_map[prefix_sum - k])
            
            # Store the first occurrence of prefix_sum in the map
            if prefix_sum not in prefix_sum_map:
                prefix_sum_map[prefix_sum] = i
        
        return max_length

            
    



#{ 
 # Driver Code Starts
#Initial Template for Python 3


for _ in range(0,int(input())):
    
    n, k = map(int , input().split())
    arr = list(map(int,input().strip().split()))
    ob = Solution()
    print(ob.lenOfLongSubarr(arr, n, k))




# } Driver Code Ends