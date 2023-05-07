class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> queue(stones.begin(), stones.end());
        while(queue.size()>1){
            int x = queue.top();
            queue.pop();
            int y = queue.top();
            queue.pop();
            if(x!=y)
                queue.push(x-y);
        }
        if(queue.empty()){
            return 0;
        }
        else
            return queue.top();
    }
};