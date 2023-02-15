class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //aisi window jaha character ki frequency 2 rahe
        
        //hame sliding window ki size ni pata->variable sliding window ki problme han ye
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<int,int>map; //to store the frequency
        while(i<fruits.size() && j<fruits.size()){
            //agar element pele ni dekha to inset karo set ke ansar

            map[fruits[i]]++;
        
             if(map.size()>2){
                 //window aage slide karo 
                    map[fruits[j]]--;
                    if(map[fruits[j]]==0) 
                        //map ki size reeduce karne ke liiy erase use kiya warna hamesha 2 length ka hi re jata
                        map.erase(fruits[j]);
                    j++;
            }
            
            ans=max(ans,i-j+1);  
            i++;
        }
        return ans;
    }
};