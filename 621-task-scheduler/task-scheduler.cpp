class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;
        for (char task : tasks) {
            taskCount[task]++;
        }

        vector<int> counts;
        for (auto& entry : taskCount) {
            counts.push_back(entry.second);
        }

        sort(counts.begin(), counts.end(), greater<int>());

        int maxCount = counts[0];
        int numMaxTasks = count(counts.begin(), counts.end(), maxCount);

        return max((maxCount - 1) * (n + 1) + numMaxTasks, static_cast<int>(tasks.size()));
    }
};
