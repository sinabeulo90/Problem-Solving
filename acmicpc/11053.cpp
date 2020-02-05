#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
int cache[1001];

int lis(int start, const vector<int> &nums) {
    int &ret = cache[start + 1];
    
    if (ret != -1)
        return ret;
    
    ret = 1;
    
    for (int next = start + 1; next < N; ++next) {
        if (start == -1 || nums[start] < nums[next])
            ret = max(ret, 1 + lis(next, nums));
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    
    cout << lis(-1, nums) - 1 << '\n';
    
    return 0;
}