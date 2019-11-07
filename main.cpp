#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <array>
#include <string.h>


using namespace std;

int numerosprimos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int input;
int carry[(sizeof(numerosprimos)/sizeof(*numerosprimos))];

int main () {

    while (cin >> input) {
        if (input == 0){
            break;
        };

        memset(carry, 0, sizeof(int) * 25);

        for (int i=2; i <= input; ++i) {

            int temporal = i;

            for (int j=0; j<25; j++) {

                if (numerosprimos[j] > i){
                    break;
                }

                while (temporal % numerosprimos[j] == 0) {

                    temporal = temporal/numerosprimos[j];
                    ++carry[j];

                }
            }
        }

        int Maximum = 0;
        for (int k=0; k < 25; ++k) {

            if (carry[k] > 0){

                Maximum = k;

            }
        }

    //Driver
        cout << setw(3) << input << "! =";
        for (int l = 0; l <= Maximum; l++) {
            if (l > 0 and l % 15 == 0) cout << endl << "      ";
            cout << setw(3) << carry[l];
        }
        cout << endl;
    }

    return 0;
}