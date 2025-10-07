// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        stack<string>st;
        int i=s.length()-1;
        while(i>=0){
            if(isalnum(s[i]))  st.push(string(1,s[i]));
            else{
                string t1=st.top();st.pop();
                string t2=st.top();st.pop();
                string newst="("+t1+s[i]+t2+")";
                st.push(newst);
            }
            i--;
        }
        return st.top();
    }
};