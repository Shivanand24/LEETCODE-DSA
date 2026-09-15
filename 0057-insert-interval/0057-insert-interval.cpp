class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> res;

        // Add new interval
        intervals.push_back(newInterval);

        // Sort all intervals
        sort(intervals.begin(), intervals.end());

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if (start2 <= end1) {
                // Overlap
                end1 = max(end1, end2);
            }
            else {
                // No overlap
                res.push_back({start1, end1});

                start1 = start2;
                end1 = end2;
            }
        }

        // Add last interval
        res.push_back({start1, end1});

        return res;
    }
};