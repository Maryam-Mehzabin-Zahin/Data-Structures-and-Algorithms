class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int num = gas.size();
        for(int i = 0; i < num; i++) {
            int node = i, total_gas = 0;
            while(1) {
                total_gas = total_gas - cost[node] + gas[node];
                if(total_gas < 0) {
                    break;
                }
                node = (node + 1) % num;
                if(node == i) return node;
            }
        }
        return -1;
    }
};