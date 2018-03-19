#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int d, n;
	cin >> d >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	int sum = 0, count = 0;
	for (int i = 1; i < nums.size() - 1; i++) {
		if (nums[0] + d < nums[i] && nums[nums.size() - 1] - d > nums[i]) {
			sum += nums[i];
			count++;
		}
	}
	cout << (float)sum / count << endl;
	system("pause");
	return 0;
}