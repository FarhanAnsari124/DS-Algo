class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        set<string>words(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        while(!q.empty()){
            if(q.front().first==endWord){
                return q.front().second;
            }
            string temp=q.front().first;
            int cnt=q.front().second;
            q.pop();
            for(int k=0;k<temp.size();k++){
                char c=temp[k];
                for(int i=97;i<(97+26);i++){
                temp[k]=(char)i;
                if(words.find(temp)!=words.end()){
                    words.erase(temp);
                    q.push({temp,cnt+1});
                    
                }
            }
            temp[k]=c;
        }
        }
        return 0;
    }
};