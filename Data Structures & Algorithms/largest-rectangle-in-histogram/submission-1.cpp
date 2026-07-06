class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); 
        
        stack<int> st; 
        int max_area = 0;
        
        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                
                int lb = st.empty() ? -1 : st.top();
                int rb = i;
                max_area = max(max_area, h * (rb - lb - 1));
            }
            st.push(i);
        }
        
        return max_area;
    }
};
