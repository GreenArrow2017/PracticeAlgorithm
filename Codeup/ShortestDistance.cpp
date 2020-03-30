//
// Created by GreenArrow on 2020/2/10.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int arr[n];
        int des[n];
        int all = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            des[i] = all;
            all += arr[i];
        }


//         cout << endl;
//        for (int l = 0; l < n; ++l) {
//            for (int i = 0; i < n; ++i) {
//                cout << vector[l][i] << " ";
//            }
//            cout << endl;
//
//        }


        int num, index = 0;
        cin >> num;
        int result[num];
        for (int j = 0; j < num; ++j) {
            int source, destine;
            cin >> source >> destine;
            source--, destine--;
            if(source > destine){
                int temp = source;
                source = destine;
                destine = temp;
            }

            int right = des[destine] - des[source];
            int left = all - right;

            result[index++] = right > left ? left : right;
        }
        for (int k = 0; k < index; ++k) {
            cout << result[k] << endl;
        }
        index = 0;
    }
}
