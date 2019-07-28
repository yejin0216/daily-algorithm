#include <iostream>

using namespace std;

int main(void) {

    int n;
    cin >> n;

    int *a = new int[n+1];
    int *b = new int[n+1];
    int *nusum = new int[n+1];
    int *result = new int[n+1];

    //초기화
    for ( int i=0; i<=n; i++ ) {
        b[i] = 0;
        nusum[i] = 0;
        result[i] = 0;
    }
    //입력
    for ( int i=1; i<=n; i++ ) {
        cin >> a[i]; //1번부터 입력한다.
    }

    //1 1 3 4 1
    //3 0 1 1 0
    for ( int i=1; i<=n; i++ ) {
        //입력된 숫자별 개수를 위치에 넣는다.
        b[a[i]] = b[a[i]] + 1;
    }

    //3 3 4 5 5
    for ( int i=1; i<=n; i++ ) {
        //누적 숫자를 구한다.
        nusum[i] = b[i] + nusum[i-1];
    }

    //3 3 4 5 5
    for ( int i=1; i<=n; i++ ) {
        //각 배열에 숫자를 넣는다.
        result[nusum[a[i]]] = a[i];
        nusum[a[i]]--;
    }

    for ( int i=1; i<=n; i++ ) {
        cout << result[i] << endl;
    }

    delete[] a;
    delete[] b;
    delete[] nusum;
    delete[] result;

    return 0;
}
