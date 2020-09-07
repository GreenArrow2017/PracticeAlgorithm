//
// Created by GreenArrow on 2020/7/19.
//
#include <vector>
#include <algorithm>
#include <cstring>
#include <strstream>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = nums1.size() + nums2.size();
        vector<int> indexs;
        int counts = 1;
        if(count % 2 == 0){
            indexs.push_back(count/2);
            indexs.push_back(count/2+1);
            counts++;
        }else{
            indexs.push_back(count/2 + 1);
        }
        vector<double > sums;
        int index_1 = 0;
        int index_2 = 0;
        int index_sum = 0;
        while(index_1 < nums1.size() && index_2 < nums2.size()){
            if(nums1[index_1] < nums2[index_2]){
                index_sum++;
                if(indexs.empty()){
                    double sum = 0;
                    for(int i = 0;i < sums.size();i++){
                        sum += sums[i];
                    }
                    return sum / counts;
                } else{
                    for(int s : indexs){
                        if(s == index_sum){
                            sums.push_back(nums1[index_1]);
                            indexs.erase(indexs.begin());
                        }
                    }
                }
                index_1++;
            } else{
                index_sum++;
                if(indexs.empty()){
                    double sum = 0;
                    for(int i = 0;i < sums.size();i++){
                        sum += sums[i];
                    }
                    return sum / counts;
                } else{
                    for(int s : indexs){
                        if(s == index_sum){
                            sums.push_back(nums2[index_2]);
                            indexs.erase(indexs.begin());
                        }
                    }
                }
                index_2++;
            }
        }

        while(index_1 < nums1.size()){
            index_sum++;
            if(indexs.empty()){
                double sum = 0;
                for(int i = 0;i < sums.size();i++){
                    sum += sums[i];
                }
                return sum / counts;
            } else{
                for(int s : indexs){
                    if(s == index_sum){
                        sums.push_back(nums1[index_1]);
                        indexs.erase(indexs.begin());
                    }
                }
            }
            index_1++;
        }
        while(index_2 < nums2.size()){
            index_sum++;
            if(indexs.empty()){
                double sum = 0;
                for(int i = 0;i < sums.size();i++){
                    sum += sums[i];
                }
                return sum / counts;
            } else{
                for(int i = 0;i < indexs.size();i++){
                    int s = indexs[i];
                    if(s == index_sum){
                        sums.push_back(nums2[index_2]);
                        indexs.erase(indexs.begin());
                    }
                }
            }
            index_2++;
        }
        double sum = 0;
        for(int i = 0;i < sums.size();i++){
            sum += sums[i];
        }
        return sum / counts;
    }
};


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
