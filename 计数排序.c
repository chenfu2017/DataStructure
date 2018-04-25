#include <iostream>
#define MAX 10
int c[MAX];
using namespace std;
int main() {
    int i,n;
    cin >> n;
    int a[n];
    int b[n];
    for (i = 0; i < n; ++i) {
        cin >> a[i]; 
        ++c[a[i]];
    }
    for (i = 1; i < MAX; ++i)
        c[i] += c[i-1];
    for (i = n-1; i >= 0; --i)
        b[--c[a[i]]] = a[i];
    for (i = 0; i < n; ++i)
        cout << b[i] << endl;
    return 0;
}
