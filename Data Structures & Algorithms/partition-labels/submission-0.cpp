class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> index(26,-1);
        vector<int> v;
        
        for(int i = 0; i < n; i++){
            index[s[i]-'a'] = i;
        }


        int left=0;
        int right=0;

        while(right<n){
            int ind=index[s[left]-'a'];

            right=ind;

            for(int i=left;i<=right;i++){
                if(index[s[i]-'a']>right){
                    right=index[s[i]-'a'];
                }
            }

            v.push_back(right-left+1);
            right++;
            left=right;
        }

        return v;
    }
};
