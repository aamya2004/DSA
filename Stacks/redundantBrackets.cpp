#include <bits/stdc++.h> 
bool checkStringExpression(string str) {
	bool ans;
	stack<char> st;
	for(int i = 0 ; i<str.length() ; i++){
		char ex = str[i];
		if(ex =='+' ||ex =='-' ||ex =='/' ||ex =='*' ||ex =='(' ){
			st.push(ex);
		}
		else{

				if(ex == ')'){
					ans=true;
					while(st.top()!='('){

					if(st.top() == '+'||st.top() == '-'||st.top() == '/'||st.top() == '*'){
						ans=false;

					}
						st.pop();
					}
					if(ans==true){
						return ans;
					}
					st.pop();
				}
				

			}
		}
	return false;
	
}