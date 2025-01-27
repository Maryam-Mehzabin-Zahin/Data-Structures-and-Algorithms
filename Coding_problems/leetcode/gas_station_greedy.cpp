class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int num = gas.size();
        int sum_gas = 0, sum_cost = 0;
        for(int i = 0; i < num; i++) {
            sum_gas += gas[i];
            sum_cost += cost[i];
        }
        if(sum_gas - sum_cost < 0) return -1;
        int res = 0;
        int total = 0;
        for(int i = 0; i < num; i++) {
            total = total - cost[i] + gas[i];
            if(total < 0) {
                res = i+1;
                total = 0;
            }
        }
        return res;
    }
        
};