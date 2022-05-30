class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> v(boxes.size(), 0);
        vector<int> index_v;

        for (int i = 0; i< boxes.size(); ++i) {
            if (boxes[i] == '1')
                index_v.push_back(i);
        }
        
        for (int i=0; i<v.size(); ++i) {
            for (int j=0; j<index_v.size(); ++j) {
                v[i] += abs(index_v[j] -i);
            }
        }
        return v;
    }
};