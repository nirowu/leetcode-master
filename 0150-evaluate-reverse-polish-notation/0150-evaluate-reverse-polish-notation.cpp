class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;

        for (int i = 0; i < tokens.size(); i++) {
            int fst_num, sec_num;

            if (tokens[i] == "+" ){
                sec_num = s.top(); s.pop();
                fst_num = s.top(); s.pop();
                s.push(fst_num + sec_num);
            }
            else if( tokens[i] == "-"){
                sec_num = s.top(); s.pop();
                fst_num = s.top(); s.pop();
                s.push(fst_num - sec_num);
            }
            else if( tokens[i] == "*"){
                sec_num = s.top(); s.pop();
                fst_num = s.top(); s.pop();
                s.push(fst_num * sec_num);
            }
            else if(tokens[i] == "/"){
                sec_num = s.top(); s.pop();
                fst_num = s.top(); s.pop();
                s.push(fst_num / sec_num);
            }
            else{
                int num = stoi(tokens[i]);
                s.push(num);
            }
        }
        return  s.top();
    }
};