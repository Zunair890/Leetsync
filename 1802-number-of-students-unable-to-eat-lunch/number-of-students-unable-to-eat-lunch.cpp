class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeroCount=0;
        int oneCount=0;
        for(auto c : students){
            if(c==0) zeroCount++;
            else  oneCount++;
        }
        for(auto d : sandwiches){
            if(d==0 && zeroCount==0){
                return oneCount;
            }
            else if(d==1 && oneCount==0){
                return zeroCount;
            }
            else if(d==0) zeroCount--;        
               else{
                oneCount--;
            }
        }
        return 0;

    }
};
