//
//  main.cpp
//  1、TWO SUM
//
//  Created by Luo on 2017/8/14.
//  Copyright © 2017年 luochaojing. All rights reserved.
//

/*
 ====Description====
 
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 
 =====Example=========
 
 Given nums = [2, 7, 11, 15], target = 9,
 
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 
 */


/*
 =====描述=====
 给出一个整型数组，找出和为参数的两个整数的下标
 你可以假设【assume】每个输入参数只会有一个答案，你可以不使用一个参数两次
 
 */


/*
 ===解题思路====
 使用哈希表，值作为hashKey，下标作为hashValue
 遍历一次，每次查询的时间复杂度为1，整体为n
 
 ===心得====
 使用哈希表空间换时间
 
 ===关键词===
 哈希表
 */



//basefunction
#include <iostream>
using namespace std;

//core
#include <vector>
#include <unordered_map>


#pragma mark - solution

vector<int> twoSum(vector<int>& nums, int target)
{
    
    vector<int> resultVector;
    unordered_map<int, int> myHashMap;
    //unordered_map 是Windows和leetcode上
    
    for (int i = 0; i < nums.size(); i++) {
        
        int num = nums[i];
        
        //有的话
        if (myHashMap.find(target - num) != myHashMap.end())
        {
            int index = myHashMap[target - num];
            resultVector.push_back(index);
            resultVector.push_back(i);
            
            return resultVector;
            
        }
        
        myHashMap[num] = i;
    }
    
    resultVector.push_back(-1);
    resultVector.push_back(-1);
    return resultVector;
}


#pragma mark - 主函数

int main(int argc, const char * argv[]) {

    //测试数据
    int target = 40;
    vector<int> testNums;
    int arr[20] = {3,3,3,3,2,4,16,18,20,23,12,22,98,23,23,42,12,14};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        
        int value = arr[i];
        testNums.push_back(value);
    }
    
    
    vector<int> resultNum = twoSum(testNums, target);
    cout<< "下标:" << resultNum[0] << "-" << resultNum[1] << endl;
    
    return 0;
}





