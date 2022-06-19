/*
 * TwoSum_001.h
 *
 *  Created on: 2022年6月19日
 *      Author: pirate
 */

#ifndef TWOSUM_001_H_
#define TWOSUM_001_H_

#include <vector>
#include <map>
#include <iostream>
using namespace std;

/**
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

输入：nums = [3,2,4], target = 6
输出：[1,2]

输入：nums = [3,3], target = 6
输出：[0,1]

提示：
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？

 * */

class TwoSum001 {
public:
	//vector 遍历
	static vector<int> twoSumNormal(vector<int> &nums, int target) {
		int tmp = 0;
		for (int i = 0; i < nums.size(); i++) {
			tmp = target - nums[i];
			for (int j = i + 1; j < nums.size(); j++) {
				if (tmp == nums[j]) {
					return {i,j};
				}
			}
		}
		return {};
	}

	static vector<int> twoSumMap(vector<int> &nums, int target) {
		map<int, int> numMap;
		for (int i = 0; i < nums.size(); i++) {
			//numMap.insert(make_pair(target - nums[i], i));
			numMap.insert(map<int,int>::value_type(target - nums[i], i));
			//numMap[target - nums[i]]=i;
		}
		cout << "map size="<< numMap.size()<< endl;
		for (map<int,int>::iterator ite = numMap.begin();ite != numMap.end(); ite++) {
			cout << "map first" << ite->first << endl;
			cout << "map second" << ite->second << endl;
		}

		for (int i = 0; i < nums.size(); i++) {
			auto ite = numMap.find(target - nums[i]);
			if(ite != numMap.end()){
				if(ite->second == i){
					continue;
				}
				return {i,ite->second};
			}
		}
		return {};

	}

	static void main() {
		vector<int> nums1 = { 2, 7, 11, 15 };
		int target1 = 9;
		vector<int> nums2 = { 3, 2, 4 };
		int target2 = 6;
		vector<int> nums3 = { 3, 3 };
		int target3 = 6;
		vector<int> nums4 = { 2, 5, 5, 11 };
		int target4 = 10;
		//vector<int> result = twoSumNormal(nums4, target4);
		vector<int> result = twoSumMap(nums4, target4);
		cout << result[0] << result[1] << endl;

	}
};



#endif /* TWOSUM_001_H_ */
