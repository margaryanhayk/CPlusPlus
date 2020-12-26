
class Solution {
public:

    std::vector<int> nextFromPrevious(const std::vector<int>& right) {
        std::vector<int> line;
        line.push_back(1);
        for (int i = 0; i < right.size() - 1; ++i) {
            line.push_back(right[i] + right[i + 1]);
        }
        line.push_back(1);
        return line;
    }
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> source;
        ++rowIndex;
        source.push_back(1);
        for (int ix = 0; ix < rowIndex - 1; ++ix) {
            source = nextFromPrevious(source);
        }
        return source;
    }
};
