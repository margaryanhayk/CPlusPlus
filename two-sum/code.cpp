class Solution {
public:
	std::vector<int> twoSum(std::vector<int> & nums, int target) {
		std::vector<int> output;
		for (int i = 0; i < nums.size(); ++i) {
			int x = target - nums[i];
			for (int ix = i + 1; ix < nums.size(); ++ix) {
				if (nums[ix] == x) {
					output.push_back(i);
					output.push_back(ix);
					return output;
				}
			}
		}
		return output;
	}
};
