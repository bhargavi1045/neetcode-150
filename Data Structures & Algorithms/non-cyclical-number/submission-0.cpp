class Solution {
public:
    bool isAHappyNumber(int n,set<int>&s){
        if(n==1) return true;
        if(s.count(n)) return false;
        s.insert(n);
        int num=n;
        int newn=0;
        while(num){
            int x=num%10;
            num=num/10;
            newn+=pow(x,2);
        }
        return isAHappyNumber(newn,s);
    }
    bool isHappy(int n) {
        set<int> s;
        return isAHappyNumber(n,s);
    }
};
