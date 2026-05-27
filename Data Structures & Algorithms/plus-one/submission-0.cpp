class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> numPlusOne;
        int carry=0;

        reverse(digits.begin(),digits.end());

        for(int i=0;i<digits.size();i++){
            int num=digits[i]+carry;
            if(i==0) num++;
            carry=num/10;
            numPlusOne.push_back(num%10);
            
        }

        if(carry) numPlusOne.push_back(carry);
        reverse(numPlusOne.begin(),numPlusOne.end());
        return numPlusOne;
    }
};
