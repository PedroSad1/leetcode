class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0.0;
        std::vector<int> mergedArray(nums1.size() + nums2.size());
        std::merge(nums1.begin(), nums1.end(), 
               nums2.begin(), nums2.end(), 
               mergedArray.begin());

        bool isEven = mergedArray.size() % 2 == 0;

        if(!isEven){
            result = mergedArray[std::floor(mergedArray.size() / 2)];
        }else{
            result = (mergedArray[mergedArray.size() / 2] + mergedArray[(mergedArray.size() / 2) - 1]) / 2.0;
        }

        return result;
    };
};