class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff_gas_cost;
        int total = 0;
        for(int i = 0; i < gas.size(); i++) {
            diff_gas_cost.push_back(gas[i] - cost[i]);
            total += diff_gas_cost[i];
        }
        // [-1, 0, -1, 3]
        // i = 3
        // currTank += 3
        // start = 3

        if(total < 0) return -1;

        int currTank = 0;
        int start = 0;
        for(int i = 0; i < diff_gas_cost.size(); i++) {
            currTank += diff_gas_cost[i];
            if(currTank < 0) {
                currTank = 0;
                start = i + 1;
            }
        }

        return start;
    }
};
