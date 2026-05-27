class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }

        priority_queue<int> pq;
        for(int i=0;i<freq.size();i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }

       
        int time=0;
        while(!pq.empty()){
            queue<int> q;
            int used=0;

            for(int i=0;i<=n;i++){
              
                if(pq.empty()) continue;
                auto fre=pq.top();
                pq.pop();
                
                
                if(fre>1){
                    q.push(fre-1);
                }
                used++;
                
            }
            
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }

            if(pq.empty()) time+=used;
            else time+=(n+1);
        }
        return time;
    }
};
