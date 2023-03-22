class Solution {
public:
    vector<int>sol1(vector<int>&a){
        stack<pair<int,int>>st;
        vector<int>ans;

        for(int i=0;i<a.size();i++){
        if(st.size()==0) ans.push_back(-1);

        else if( st.empty()==false && st.top().first <a[i]){
            ans.push_back(st.top().second);
        }
        else if(st.empty()==false && st.top().first >=a[i]){
            while(st.size()>0 && st.top().first >=a[i]) st.pop();

            if(st.size()==0) ans.push_back(-1);
            else 
                ans.push_back(st.top().second);
        }
        st.push({a[i],i});
    }
    return ans;
    }
    vector<int>sol2(vector<int>&a){
        stack<pair<int,int>>st;
        vector<int>ans;
        
        for(int i=a.size()-1;i>=0;i--){
        if(st.size()==0) ans.push_back(a.size());

        else if( st.empty()==false && st.top().first<a[i]){
            ans.push_back(st.top().second);
        }
        else if(st.empty()==false && st.top().first >=a[i]){
            while(st.size()>0 && st.top().first>=a[i]) st.pop();

            if(st.size()==0) ans.push_back(a.size());
            else 
                ans.push_back(st.top().second);
        }
        st.push({a[i],i});
    }   
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int> &a) 
    {
        //maximum area = max(nsr-nsl)*a
        vector<int>ans1=sol1(a);
        vector<int>ans2=sol2(a);

        int maxi=0;
        for(int i=0;i<a.size();i++){
            maxi=max(maxi,a[i]*abs(ans2[i]-ans1[i]-1));
        }
        return maxi;
    }
};