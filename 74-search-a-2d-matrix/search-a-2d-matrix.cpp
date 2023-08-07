class Solution {
public:
    bool rowsearch(vector<vector<int>>& matrix, int target,int midcolumn){
            int startrow=0;
            int endrow=matrix[0].size()-1;
            int midrow=startrow+(endrow-startrow)/2;
            while(startrow<=endrow){
                if(matrix[midcolumn][midrow]==target){
                    return true;
                }
            else if(matrix[midcolumn][midrow]<target){
                startrow=midrow+1;
            }
            else{
                endrow=midrow-1;
            }
             midrow=startrow+(endrow-startrow)/2;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int startcolumn=0;
        int endcolumn=matrix.size()-1;
        int midcolumn=startcolumn+(endcolumn-startcolumn)/2;
        while(startcolumn<=endcolumn){
            if(matrix[midcolumn][0]==target){
                return true;
            }
         else if(matrix[midcolumn][0]<target){
                startcolumn=midcolumn+1;
            }
            else{
                endcolumn=midcolumn-1;
            }
            midcolumn=startcolumn+(endcolumn-startcolumn)/2;
        }
        if(endcolumn<0){
            return false;
        }
        return rowsearch(matrix,target,endcolumn);
         
    }
};