class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0),freq2(26,0);

        for(auto ch : s1) freq1[ch-'a']++;

        int sz=0;

        for(int i=0;i<s2.size() && sz<s1.size();i++){
            freq2[s2[i]-'a']++;
            sz++;
        }

        if(freq1==freq2) return true;

        int right=sz;
        int left=0;

        while(right<s2.size()){
            freq2[s2[left]-'a']--;
            left++;
            freq2[s2[right]-'a']++;
            if(freq1==freq2) return true;
            right++;
        }
        
        return false;
    }
};
