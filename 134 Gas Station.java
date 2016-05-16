public class Solution {
    /**
     * @param gas: an array of integers
     * @param cost: an array of integers
     * @return: an integer
     */
    public int canCompleteCircuit(int[] gas, int[] cost) {
        if (gas.length == 1) {
            return gas[0] >= cost[0] ? 0 : -1;
        }
        int leftGas = gas[gas.length - 1] - cost[cost.length - 1];
        int maxLeftGas = leftGas;
        int maxLeftGasPos = gas.length - 1;
        for (int i = gas.length - 2; i >= 0; --i) {
            leftGas = leftGas + gas[i] - cost[i];
            if (leftGas >= maxLeftGas) {
                // use "=" to find the most left start position
                maxLeftGas = leftGas;
                maxLeftGasPos = i;
            }
        }
        if (leftGas < 0) {
            return -1;
        } else {
            return maxLeftGasPos;
        }
    }
}
