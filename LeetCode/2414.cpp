class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=1;
        int curr=0;
        for(int i=0;i<s.size();i++){
            if(i==0 || int(s[i])!=int(s[i-1])+1){
                curr=1;
                
            }else{
                curr++;
            }
            ans=max(ans, curr);
        }
        return ans;
    }
};
