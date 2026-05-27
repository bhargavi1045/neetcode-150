class Solution {
public:
    int reverse(int x){
        string s=to_string(x);
        int sign=1;

        if(s[0]=='-'){
            sign=-1;
            s=s.substr(1);
        }

        std::reverse(s.begin(),s.end());

         while(s.size()>1 && s[0]=='0') {
            s.erase(0, 1);
        }

        long long number=stoll(s);
        if(sign==-1) number=-number;

        if(number>INT_MAX || number<INT_MIN) return 0;
        else return (int)number;
    }
};
