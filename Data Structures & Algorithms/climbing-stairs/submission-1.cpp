class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        
        int oneStairLess=1;
        int twoStairsLess=1;
        int answer=0;
        for(int i=2;i<=n;i++){
            answer=oneStairLess+twoStairsLess;
            twoStairsLess=oneStairLess;
            oneStairLess=answer;
        }

        return answer;
    }
};
