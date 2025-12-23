#include <iostream>
#include <algorithm> // для max
using namespace std;

int main() {
    double nums[3];
    for( int i = 0; i<3; i++ ){
        cin >> nums[i];
    }
    
    double max = nums[0];
    double min = nums[0];

    for( int i = 0; i<3; i++){
        if (nums[i] > max) {
            max = nums[i];
        }
        if(nums[i] < min) {
        min = nums[i];
        }

    }
    double s = max - min;
    cout << "Разница: " << s << endl;

    return 0;

}
