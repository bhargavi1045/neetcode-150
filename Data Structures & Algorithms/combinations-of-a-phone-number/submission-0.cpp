class Solution {
public:
    void recursion(string digits,int index,string ans,vector<string>&answer){
        if(index==digits.size()){
           answer.push_back(ans);
        }
        if(digits[index]=='2'){
            recursion(digits,index+1,ans+"a",answer);
            recursion(digits,index+1,ans+"b",answer);
            recursion(digits,index+1,ans+"c",answer);
        }
        if(digits[index]=='3'){
            recursion(digits,index+1,ans+"d",answer);
            recursion(digits,index+1,ans+"e",answer);
            recursion(digits,index+1,ans+"f",answer);
        }
        if(digits[index]=='4'){
            recursion(digits,index+1,ans+"g",answer);
            recursion(digits,index+1,ans+"h",answer);
            recursion(digits,index+1,ans+"i",answer);
        }
        if(digits[index]=='5'){
            recursion(digits,index+1,ans+"j",answer);
            recursion(digits,index+1,ans+"k",answer);
            recursion(digits,index+1,ans+"l",answer);
        }
        if(digits[index]=='6'){
            recursion(digits,index+1,ans+"m",answer);
            recursion(digits,index+1,ans+"n",answer);
            recursion(digits,index+1,ans+"o",answer);
        }
        if(digits[index]=='7'){
            recursion(digits,index+1,ans+"p",answer);
            recursion(digits,index+1,ans+"q",answer);
            recursion(digits,index+1,ans+"r",answer);
            recursion(digits,index+1,ans+"s",answer);
        }
        if(digits[index]=='8'){
            recursion(digits,index+1,ans+"t",answer);
            recursion(digits,index+1,ans+"u",answer);
            recursion(digits,index+1,ans+"v",answer);
        }
        if(digits[index]=='9'){
            recursion(digits,index+1,ans+"w",answer);
            recursion(digits,index+1,ans+"x",answer);
            recursion(digits,index+1,ans+"y",answer);
            recursion(digits,index+1,ans+"z",answer);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        string ans="";
        if(digits=="") return {};
        recursion(digits,0,ans,answer);
        return answer;
    }
};
