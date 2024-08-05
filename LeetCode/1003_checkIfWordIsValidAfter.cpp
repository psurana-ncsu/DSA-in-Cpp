class Solution {
public:
    bool isValid(string s) {
        int index=0;
        vector<char> st(s.size(), 'a');
        for(char c:s){
            if(c=='c'){
                if(index>1 && st[index-1]=='b' && st[index-2]=='a'){
                    index=index-3;
                }
                else{
                    return false;
                }
            }
            else{
                st[index]=c;
            }
            index++;
        }
        return index>0? false:true;

    }
};
