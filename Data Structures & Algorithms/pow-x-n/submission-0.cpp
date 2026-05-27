class Solution {
public:
    double myPowCalc(double x,int n){
        if(n==0) return (double)1;
        return (double)x*myPowCalc(x,n-1);
    }
    double myPow(double x, int n) {
        if(n>=0) return myPowCalc(x,n);
        else return (double)1/myPowCalc(x,-n);
    }
};
