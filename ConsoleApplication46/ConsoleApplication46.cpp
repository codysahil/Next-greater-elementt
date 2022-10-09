#include <iostream>
#include<vector>
#include<stack>
using namespace std;
// USING BRUTE FORCE METHOD O(N^2)
void nge(int arr[], int n) {
    vector<int> k;
    for (int i = 0; i < n; i++) {
        int max = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                max = arr[j];
                break;
            }

        }
        cout << max << " ";
    }
}
// USING STACK O(N)
void findnge(int arr[], int n) {
    stack<int> st;
    st.push(arr[0]);
    for (int i = 1; i < n; i++) {
        if (st.empty()) {
            st.push(arr[i]);
            continue;
        }
        while (st.empty() == false && st.top() < arr[i]) {
            cout << st.top() << "-->" << arr[i] << endl;
            st.pop();
        }
        st.push(arr[i]);
    }
    while (st.empty() == false) {
        cout << st.top() << "-->" << -1 << endl;
        st.pop();
    }
}
int main() {
    // Write C++ code here
    int arr[] = { 4,5,2,25,7,8 };
    int n = 6;
    nge(arr, n);
    cout << endl;
    findnge(arr, n);
    return 0;
}