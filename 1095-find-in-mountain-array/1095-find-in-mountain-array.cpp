/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
     int i=0;
     int j=mountainArr.length()-1;
     //fin peak
     while(i<j){
         int m=(i+j)/2;
        if( mountainArr.get(m) > mountainArr.get(m+1)){
            j=m;
        }
        else{
            i=m+1;
        }
     }
     int peak=j;
     //search in left 
     i=0;
     j=peak;
     while(i<=j){
        int m=(i+j)/2;
        if(mountainArr.get(m)==target)
            return m;
        else if(mountainArr.get(m)>target)
            j=m-1;
        else
            i=m+1; 
     }
     i=peak;
     j=mountainArr.length()-1;
     //ryt
     while(i<=j){
        int m=(i+j)/2;
        if(mountainArr.get(m)==target)
            return m;
        else if(mountainArr.get(m)>target)
            i=m+1;
        else
            j=m-1; 
     }
     return -1;
    }
};