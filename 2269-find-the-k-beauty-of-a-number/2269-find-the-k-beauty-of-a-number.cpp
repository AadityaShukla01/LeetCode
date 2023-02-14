class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int q=0;
        string ans=to_string(num);
            if(ans.size()==1){
                int n=stoi(ans);
                return num%n==0;
            }
            string res=ans.substr(0,k);
            int n=stoi(res);
            cout<<n<<endl;
            if(n !=0 && num%n ==0){
                q++;
            }
        
        //baaki ke liye slide karenge
        for(int i=k;i<ans.size();i++){
            string res=ans.substr(i-k+1,k);
            int n=stoi(res);
            cout<<n<<endl;
            if(n!=0 && num%n==0){
                q++;
            }
        }
        return q;
    }
};