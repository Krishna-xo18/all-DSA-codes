class Solution {
    vector<int> next_smaller_element(vector<int>&histo)
    {
        stack<int>s;
        vector<int>v(histo.size());
        s.push(histo.size());
        for(int i=histo.size()-1 ; i>=0 ; i--)
        {
            while(s.top() !=histo.size() && histo[i]<=histo[s.top()])
            {
                s.pop();
            }
            v[i]=s.top();
            s.push(i);
        }
        return v;
    }

    vector<int> prev_smaller_element(vector<int>&histo)
    {
        stack<int>s;
        vector<int>v(histo.size());
        s.push(-1);
        for(int i=0 ; i<histo.size() ; i++)
        {
            while(s.top() !=-1 && histo[i]<=histo[s.top()])
            {
                s.pop();
            }
            v[i]=s.top();
            s.push(i);
        }
        return v;
    }

    int max_area(vector<int>&histo)
    {
        
        cout<<endl;
        vector<int>next;
        vector<int>prev;
        int max_area = INT_MIN;
        
        next = next_smaller_element(histo);
        prev = prev_smaller_element(histo);
        for(int i=0 ; i<histo.size() ; i++)
        {
            
            max_area = max(max_area , histo[i]*(next[i]-prev[i]-1));

        }
        
        return max_area;
    }
public:
        int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<int>box(matrix[0].size());
        vector< int>v;
        for(int i=0 ; i<matrix[0].size() ; i++)
        {
            if(matrix[0][i]=='1')
            {
                box[i]=1;
            }
            else{
            box[i]=0;
            }
        }
        v.push_back(max_area(box));

        for(int i=1 ; i<matrix.size() ; i++)
        { 
            for(int j=0 ; j<matrix[i].size() ; j++)
            {
                if(matrix[i][j]=='0')
                {
                    box[j]=0;
                }
                else
                {
                    box[j] = box[j]+1; 
                }
            }
            v.push_back(max_area(box));
        }
        return *max_element(v.begin() , v.end());
        
      
    }
};