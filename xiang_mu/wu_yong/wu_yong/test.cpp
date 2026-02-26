//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {
//        int n = arr.size();
//        int right = -1;
//        int left = 0;
//        int i = 0;
//        // 找到最后一个复写的数
//        while (left < n) {
//            if (arr[left] == 0) {
//                right += 2;
//            }
//            else {
//                right++;
//            }
//            if (right >= n - 1) {
//                break;
//            }
//            left++;
//        }
//        if (right == n) {
//            arr[n - 1] = 0;
//            left--;
//            right -= 2;
//        }
//        while (left >= 0) {
//            if (arr[left] == 0) {
//                arr[right--] = 0;
//                arr[right--] = 0;
//                left--;
//            }
//            else {
//                arr[right--] = arr[left--];
//            }
//        }
//    }
//};
//int main()
//{
//    vector<int> vec = { 1,0,2,3,0,4,5,0 };
//    Solution s;
//    s.duplicateZeros(vec);
//    for (auto e : vec)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<math.h>
//using namespace std;
//class Solution
//{
//public:
//	vector<vector<int>>& SLGet(vector<vector<int>>& vec)
//	{
//		int count = 1;
//		int row = 0;
//		int n = vec.size();
//		for(int i = 0;i< n;i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				vec[row].push_back(count++);
//			}
//			row++;
//		}
//		return vec;
//	}
//private:
//	int _num;
//};
//int main()
//{
//	Solution s;
//	vector<vector<int>> vec(2,vector<int>(3));
//	s.SLGet(vec);
//	for (const auto& i : vec)
//	{
//		for (auto j : i)
//		{
//			cout << j << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<math.h>
//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//    int minSubArrayLen(int target, vector<int>& nums)
//    {
//        int sum = 0,ret = nums.size();
//        int left = 0;
//        for (int right = 0; right < nums.size(); right++)
//        {
//            sum += nums[right];
//            while (sum >= target)
//            {
//                ret = min(ret, right - left + 1);
//                sum -= nums[left];
//                left++;
//            }
//        }
//        if (sum < target && left == 0)
//        {
//            return 0;
//        }
//        return ret;
//    }
//};
//int main()
//{
//	Solution s;
//    vector<int> vec = { 2,3,1,2,4,3 };
//    int ret = s.minSubArrayLen(7,vec);
//    cout << ret << endl;
//	return 0;
//}


//#include<string>
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//class Solution 
//{
//public:
//    void duplicateZeros(vector<int>& arr) 
//    {
//        int n = arr.size();
//        int top = 0;
//        int i = -1;
//        while (top < n) 
//        {
//            i++;
//            if (arr[i] != 0) 
//            {
//                top++;
//            }
//            else 
//            {
//                top += 2;
//            }
//        }
//        int j = n - 1;
//        if (top == n + 1) 
//        {
//            arr[j] = 0;
//            j--;
//            i--;
//        }
//        while (j >= 0) 
//        {
//            arr[j] = arr[i];
//            j--;
//            if (!arr[i]) 
//            {
//                arr[j] = arr[i];
//                j--;
//            }
//            i--;
//        }
//    }
//};
//int main()
//{
//    Solution s;
//    vector<int> vec{ 0,0,0,0,0,0,0 };
//    s.duplicateZeros(vec);
//    for (auto& e:vec)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//    return 0;
//}


