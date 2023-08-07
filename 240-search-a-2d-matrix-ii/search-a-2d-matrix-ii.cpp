class Solution
{
    public:
        bool searchMatrix(vector<vector < int>> &matrix, int target)
        {
            vector<int> v;
            for (int i = 0; i < matrix.size(); i++)
            {
                v.push_back(matrix[i][0]);
            }
            int x = upper_bound(v.begin(), v.end(), target) - v.begin();
            for (int j = 0; j < x; j++)
            {
                if (binary_search(matrix[j].begin(), matrix[j].end(), target))
                {
                    return true;
                }
            }
            return false;
        }
};