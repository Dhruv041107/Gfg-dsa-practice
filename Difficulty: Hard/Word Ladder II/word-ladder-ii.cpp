// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        // code here
        vector<vector<string>>ans;
        queue<pair<vector<string>,int>>q;
        q.push({{beginWord},1});

        unordered_set<string>s(wordList.begin(),wordList.end());

        int prevLevel=-1;
        vector<string>toBeRemoved;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            auto stringvector=front.first;
            auto frontstring=stringvector[stringvector.size()-1];
            int frontdistance=front.second;
            
            if(frontdistance!=prevLevel){
                for(auto &st:toBeRemoved) s.erase(st);
                toBeRemoved.clear();
                prevLevel=frontdistance;
            }
                
            if(endWord == frontstring)  {
                ans.push_back(stringvector);
            }
            
            for(int index=0;index<frontstring.size();index++){
                char original=frontstring[index];
                for(char ch='a';ch<='z';ch++){
                    frontstring[index]=ch;
                    if(s.find(frontstring)!=s.end()){
                        vector<string> temp = stringvector;
                        temp.push_back(frontstring);
                        q.push({temp,frontdistance+1});
                        toBeRemoved.push_back(frontstring);
                    }
                }
                frontstring[index]=original;
            }
            
        }
        return ans;
    }
};