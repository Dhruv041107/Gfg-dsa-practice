// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        stack<string>st;
        int i=s.length()-1;
        while(i>=0){
            if(isalnum(s[i]))   st.push(string(1,s[i]));
            else{
                string t1=st.top();st.pop();
                string t2=st.top();st.pop();
                string ans=t1+t2+s[i];
                st.push(ans);
            }
            i--;
        }
        return st.top();
    }
};