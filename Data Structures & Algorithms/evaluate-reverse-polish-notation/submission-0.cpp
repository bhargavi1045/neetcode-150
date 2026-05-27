class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
    
        for(int i=0;i<tokens.size();i++){
            if (tokens[i] != "+" && tokens[i] != "-" &&
    tokens[i] != "*" && tokens[i] != "/") st.push(stoi(tokens[i]));
            else{
                string op=tokens[i];
                int first=st.top();

                st.pop();
                int second=st.top();
                st.pop();

                if(op=="+") st.push(first+second);
                else if(op=="-") st.push(second-first);
                else if(op=="*") st.push(first*second);
                else st.push(second/first);
            }
        }
        return st.top();
    }
};
