//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i = 0 ; i<n ; i++){
            st.push(i);
        }
        
        //Condition check 
        while(st.size()!=1){
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();
            
            if(M[A][B] == 1){
                //a knows b
                st.push(B);
            }
            else{
                st.push(A);
            }
        }
        //potential to be celebrity
        int celebrityPossible = st.top();
        
        //verifying conditions
        //checkingRow
        int zeroCount = 0;
        for(int i = 0 ; i<n ; i++){
            if(M[celebrityPossible][i] == 0){
                zeroCount++;
            }
        }
        
        if(zeroCount!=n){
            return -1;
        }
        
        //checkingCoulums
        int oneCount = 0;
        for(int i = 0 ; i<n ; i++){
            if(M[i][celebrityPossible]==1){
                oneCount++;
            }
        }
        
        if(oneCount!=n-1){
            return -1;
        }
        return celebrityPossible;
    }
    
};