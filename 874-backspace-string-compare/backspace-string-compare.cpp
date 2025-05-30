class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>stS;
        stack<char>stT;

        for(auto ch : s){
            if(ch !='#'){
                stS.push(ch);
            } else if ( !stS.empty()){
                stS.pop();
            }
        }
         for(auto ch : t){
            if(ch !='#'){
                stT.push(ch);
            } else if ( !stT.empty()){
                stT.pop();
            }
            
        }
        return stS == stT;
    }
    };
        
    