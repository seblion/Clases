#include <iostream>
#include <vector>

using namespace std;

void showVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void shellsort(vector<int>& vectorshell) {
    int largo = vectorshell.size();
    
    for (int distancia = largo / 2; distancia > 0; distancia /= 2) {
        for (int i = distancia; i < largo; ++i) {
            int val = vectorshell[i];
            int j = i;
            
            while (j >= distancia && vectorshell[j - distancia] > val) {
                vectorshell[j] = vectorshell[j - distancia];
                j -= distancia;
            }
            vectorshell[j] = val;
        }
    }
}

int main() {
    vector<int> num = {1, 8, 5, 2, 7, 4, 9, 6, 3};
    
    cout << "Original Array: ";
    showVector(num);
    
    shellsort(num);
    
    cout << "Sorted Array: ";
    showVector(num);

    return 0;
}
