// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
int maxreach=0;
        int maxx=0;
        int jumps=0;
        
        for(int i=0;i<=n-1;i++)
        {
            maxx=max((i+arr[i]),maxx);
            
            if(i==maxreach)
            {
                maxreach=maxx;
                jumps++;
                if(maxreach>=(n-1))
                {
                    return jumps;
                }
            }
        }
        
        return -1;
    }
}