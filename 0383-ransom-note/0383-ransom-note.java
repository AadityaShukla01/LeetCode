class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int arr1[] = new int [26];
        int arr2[] = new int [26];

        for(int i=0; i<ransomNote.length(); i++)
        {
            arr1[ransomNote.charAt(i) - 'a']++;
        }

        
        for(int i=0; i<magazine.length(); i++)
        {
            arr2[magazine.charAt(i) - 'a']++;
        }

        for(int i=0; i<26; i++)
        {
            if(arr1[i] > arr2[i]) return false;
        }
        return true;
    }
}