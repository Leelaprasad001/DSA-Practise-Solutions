class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
         priority_queue<int, vector<int>, greater<int>> ahead;
        priority_queue<int, vector<int>, greater<int>> behind;
        int i = costs.size() - 1, j = 0;
        long long cost = 0;
        for (; j < candidates; j++) ahead.push(costs[j]);
        
        j--;

        for (; i > costs.size() - candidates - 1 && i > j; i--)   behind.push(costs[i]);
        

        bool pass = true;
        j++;
        if (j > i) {
            j = i;
            pass = false;
        }

        while (k) {
            if (!ahead.empty() && !behind.empty()) {
                if (ahead.top() > behind.top()) {
                    cost += behind.top();
                    behind.pop();
                    if (i == j && pass) {
                        behind.push(costs[i]);
                        pass = false;
                    } else if (i != j) {
                        behind.push(costs[i]);
                        i--;
                    }

                } else {
                    cost += ahead.top();
                    ahead.pop();
                    if (j == i && pass) {
                        ahead.push(costs[j]);
                        pass = false;
                    } else if (j != i) {
                        ahead.push(costs[j]);
                        j++;
                    }
                }
            } else if (!ahead.empty()) {
                cost += ahead.top();
                ahead.pop();
                if (i > j) {
                    ahead.push(costs[i]);
                    j++;
                }
            } else if (!behind.empty()) {
                cost += behind.top();
                behind.pop();
                if (i > j) {
                    behind.push(costs[i]);
                    i--;
                }
            }
            k--;
        }
        return cost;
    }
};