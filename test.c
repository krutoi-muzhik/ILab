#include <stdio.h>
#include <math.h>

double InputTest ();

int main () {
    double a = InputTest ();
    printf ("%lf", a);
    return 0;
}





















double InputTest () {

    char inputek[100];


    int i = 0;
    int t = 0;
    int k = 0;
    int l = 0;
    double a = 0;
    int BreakorNot = 1;


    while (BreakorNot) {
        
        gets (inputek);
        //scanf ("%s", &inputek);
        //printf("111111111111111111111\n");
        //printf("%s\n", &inputek[0]);
        //printf("111111111111111111111\n");

        for (i = 0; inputek[i] != '\0'; i++) {

            printf ("1\n");

            if (inputek[i] == '-') {
                k++;
                if (i != 0) {

                    if (inputek[i - 1] == ' ') {
                        l++;
                    }

                    if (inputek[i - 1] == '.') {
                        t = 2;
                    }
                }

                if (i == 0) {
                    l++;
                }
            }

            if (inputek[i] == ',') {
                inputek[i] = '.';
                t++;

                if (i != 0) {
                    if (inputek[i - 1] == ' ') {
                        l++;
                    }
                }

                if (i == 0) {
                    l++;
                }
            }

            else if (inputek[i] == '.') {
                t++;
                if (i != 0) {
                    if (inputek[i - 1] == ' ') {
                        l++;
                    }
                }

                if (i == 0) {
                    l++;
                }
            }

            if ((inputek[i] != '0') && (inputek[i] != '1') && (inputek[i] != '2') && (inputek[i] != '3') && (inputek[i] != '4') && (inputek[i] != '5') && (inputek[i] != '6') && (inputek[i] != '7') && (inputek[i] != '8') && (inputek[i] != '9') && (inputek[i] != ' ') && (inputek[i] != '.') && (inputek[i] != '-')) {
                t = 2;
            }

            if ((i != 0) && (inputek[i] == ' ') && ((inputek[i - 1] == '.') || (inputek[i - 1] == '-'))) {
                if (l > 0) {
                    l++;
                }
            }

            //else {
            //  l = 0;
            //}
        }


        if ((t > 1) || (k > 1) || (l > 1)) {
            printf ("check your input data and try again:\n");
            k = 0;
            t = 0;
            l = 0;
        }


        else {

            double b = 0;

            printf ("%s\n", inputek);

            int scanfed = sscanf (inputek, "%lf %lf", &a, &b);
            printf ("%lf\n%lf\n", a, b);

            if ( scanfed == 1) {
                BreakorNot = 0;
            } 

            else {
                printf ("check your input data and try again:\n");
                b = NAN;
                t = 0;
                l = 0;
                k = 0;
            }
        }
    }

    return a;
}