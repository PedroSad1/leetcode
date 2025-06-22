class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount = 0;

        for(int i = 0; i < s.length(); i++){
            string substring = "";

            for(int j = i; j < s.length(); j++){
                if(substring.contains(s[j])){
                    break;
                }

                substring += s[j];
            }

             if(substring.length() > maxCount){
                maxCount = substring.length();
            }
        }

        return maxCount;
    }
};