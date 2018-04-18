    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <functional>
    using namespace std;
    
        int main() {
            int n;
            cin >> n;
            int k;
            cin >> k;
            vector <int> pr(n + 1, 1);
            pr[0] = pr[1] = 0;
            for (int i = 0; i * i <= n ; i++) {
                if(pr[i] == 1) {
                    for (int j = i * i; j <= n; j += i) {
                        pr[j] = 0;
                    }
                }
            }
            vector <int> nums;
            for (int i = 0; i < k; i++) {
                int a;
                cin >> a;
                nums.push_back(a);
            }
            int check = 0;
            int wrong = 0;
            int j = 0;
            sort(nums.begin(), nums.end());
            if (nums[0] == 1) {
                cout << 2;
                return 0;
            }
            for (int i = 2; i <= n; i++) {
                if (pr[i] == 0) {
                    for (j; nums[j] < i; j++) {
                        if (i % nums[j] != 0) {
                            check++;
                            if (wrong == 0) {
                                wrong = i;
                            }
                        }
                    }
                }
            }
            if (check == j)  {
                cout << wrong;
            } else {
                cout << -1;
            }
            return 0;
        }