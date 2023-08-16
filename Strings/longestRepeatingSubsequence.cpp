class Solution {
	public:

	    
		int LongestRepeatingSubsequence(string str){
int n=str.size();
         
        int arr[n+1][n+1];
        
         for(int i=0; i<=n; i++)
             arr[i][0]=0;
        
          for(int j=0; j<=n; j++)
             arr[0][j]=0;
        
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(str[i-1]==str[j-1] && i!=j)
                 {
                     arr[i][j]= arr[i-1][j-1] + 1;
                 }
                else
                {
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        return arr[n][n];

		}

};