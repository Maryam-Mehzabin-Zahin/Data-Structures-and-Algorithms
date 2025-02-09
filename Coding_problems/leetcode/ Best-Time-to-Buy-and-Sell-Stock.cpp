class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 1;
        int maxProf = 0;

        while(sell < prices.size()) {
            if(prices[buy] < prices[sell]) {
                int prof = prices[sell] - prices[buy];
                maxProf = max(maxProf, prof);
            }else {
                buy = sell;
            }
            sell++;
        }
        return maxProf;
    }
};