// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        stack<string>st;
        
        for(auto c:s){
            if(isalnum(c))  st.push(string(1,c));
            else{
                string t1=st.top();st.pop();
                string t2=st.top();st.pop();
                string ans=c+t2+t1;
                st.push(ans);
            }
        }
        return st.top();
    }
};