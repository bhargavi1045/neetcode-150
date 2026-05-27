class Solution {
public:
    bool isPalindrome(string s) {
        string a="";
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])) a+=s[i];
            else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                a+=tolower(s[i]);
            }
        }
        int i=0;
        int j=a.size()-1;

        while(i<=j){
            if(a[i]!=a[j]) return false;
            else{
                i++;
                j--;
            }
        }

        return true;
    }
};
