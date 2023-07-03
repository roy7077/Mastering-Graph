class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        set<string> st(wordList.begin(),wordList.end());
        // for(auto it:wordList)
        // st.insert(it);
        
        queue<pair<string,int>> q;
        q.push({startWord,1});
        st.erase(startWord);
        
        while(!q.empty())
        {
            auto it=q.front();
            string s=it.first;
            int level=it.second;
            q.pop();
            
            if(s==targetWord)
               return level;
            
            for(int i=0;i<s.length();i++)
            {
                char original=s[i];
                
                for(char ch='a';ch<='z';ch++)
                {
                    s[i]=ch;
                    if(st.find(s)!=st.end())
                    {
                        st.erase(s);
                        q.push({s,level+1});
                    }
                }
                
                s[i]=original;
            }
        }
        
        return 0;
    }
};
