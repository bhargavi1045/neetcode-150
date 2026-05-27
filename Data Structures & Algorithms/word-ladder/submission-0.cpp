class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> visited;

        bool found = false;
        for (auto word : wordList) {
            if (word == endWord) {
                found = true;
                break;
            }
        }
        if (!found) return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        visited[beginWord] = 1;

        while(!q.empty()){
            auto str = q.front().first;
            auto noOfWords = q.front().second;
            q.pop();
            
            if(str == endWord) return noOfWords;

            for(int i = 0; i < wordList.size(); i++){
                if(visited[wordList[i]]) continue;

                int diff = 0;
                for(int j = 0; j < wordList[i].size(); j++){
                    if(str[j] != wordList[i][j]) diff++;
                    if(diff > 1) break;
                }

                if(diff == 1){
                    q.push({wordList[i], noOfWords + 1});
                    visited[wordList[i]] = 1;
                }
            }
        }
        return 0;
    }
};
