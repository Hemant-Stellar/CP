class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = accumulate(gas.begin(),gas.end(),0);
        int costSum = accumulate(cost.begin(),cost.end(),0);
        if(gasSum<costSum) return -1;
        int currentGas=0,startingIndex=0;
        for(int i=0;i<gas.size();i++){
            currentGas += gas[i]-cost[i];
            if(currentGas<0){
                currentGas= 0; 
                startingIndex = i+1;
            }
        }
        return startingIndex;
    }
};