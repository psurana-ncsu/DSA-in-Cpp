class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int n:gifts){
            pq.push(n);
        }
        for(int i=0;i<k;i++){
            int t = pq.top();
            pq.pop();
            pq.push((int)(sqrt(t)));
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};
