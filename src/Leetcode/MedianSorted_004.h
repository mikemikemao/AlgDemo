/*
 * MedianSorted_004.h
 *
 *  Created on: 2022年6月29日
 *      Author: maochaoqun
 */

#ifndef MEDIANSORTED_004_H_
#define MEDIANSORTED_004_H_

/**
 *
 *
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n))

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5


 * **/
#include <vector>

class MedianSorted004 {
public:
	static double findMedianSortedArrays(vector<int> &nums1,
			vector<int> &nums2) {
		multiset<int> mlset;
		//添加元素
		for (int num : nums1) {
			mlset.insert(num);
		}
		for (int num : nums2) {
			mlset.insert(num);
		}
//		for (auto it = mlset.begin(); it != mlset.end(); it++) {
//			cout << *it << endl;
//		}
		multiset<int>::iterator it = mlset.begin();
		for (int i = 0; i < (mlset.size()-1) / 2; i++)
			it++;
		//中序排列
		cout << "*it" << *it <<endl;
		if (mlset.size() % 2 == 0) {
			return (double)((*it + *(++it)) / 2.0);
		} else {
			return *it;
		}

	}
	static void main() {
		vector<int> nums1 = { 1, 2 };
		vector<int> nums2 = { 3, 4 };
		double value = findMedianSortedArrays(nums1, nums2);
		cout << "value = " << value << endl;
	}
};



#endif /* MEDIANSORTED_004_H_ */
