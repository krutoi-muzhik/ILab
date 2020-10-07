
#include <stdio.h>
#include <math.h>

//-----------------------------------------------------------------------------

int SolveLin (double b, double c, double* x1);

int SolveSq (double a, double b, double c, double* x1, double* x2);

double DoublePow (double f, int g);

int IsZero (double m);

int IsEqual (double i, double j);

void SolverTest ();

double InputTest ();

//-----------------------------------------------------------------------------


const long double MicroKek = 1e-6;


//-----------------------------------------------------------------------------





int main () {


    //void SolverTest ();
    //return 0;



    printf ("\nwelcome to SqEqSolver2020 by krutoi_muzhik \n\n");
    printf ("enter ur a, b, c variables \n");


    printf ("enter a:\n");
 //   while (scanf ("%lf", & a) != 1) {
 //       printf ("input error, please enter real numbers \n                       a = ");
 //       fflush (stdin);
 //   }
    double a = InputTest ();
    printf ("u entered a = %lf\n\n", a);



    printf ("enter b:\n");
 //   while (scanf ("%lf", & b) != 1) {
 //       printf ("input error, please enter real numbers \n                       b = ");
 //       fflush (stdin);
 //   }
    double b = InputTest ();
    printf ("u entered b = %lf\n\n", b);


    
    printf ("enter c:\n");
//    while (scanf ("%lf", & c) != 1) {
//        printf ("input error, please enter real numbers \n                       c = ");
//        fflush (stdin);
//    }
    double c = InputTest ();
    printf ("u entered c = %lf\n\n", c);


    double x = 0;
    double x1 = 0;
    double x2 = 0;
    int n = 10;
    double m = 0;


    n = SolveSq (a, b, c, &x1, &x2);


    if (n == 0) {

        printf ("no roots error");
    }


    if (n == -1) {

        printf ("input error, check your data");
    }


    if (n == -2) {
        printf ("x = anything u can imagine");
    }


    if (n == 1){


        if (IsZero (x1)) {

            x1 = 0;
        }

        printf ("1 root \n");
        printf ("x = %lf\n", x1);
    }


    if (n == 2) {


        if (IsZero (x1)) {

            x1 = 0;
        }


        if (IsZero (x2)) {

            x2 = 0;
        }

        printf ("2 roots\n");
        printf ("x1 = %lf\n", x1);
        printf ("x2 = %lf\n", x2);
    }
}


//-----------------------------------------------------------------------------


int IsZero (double m) {

    if (fabs (m) < MicroKek) {
        return 1;
    }

    else {
        return 0;
    }
}


//-----------------------------------------------------------------------------


int IsEqual (double i, double j) {

    if (fabs (i - j) < MicroKek) {
        return 1;
    }

    else {
        return 0;
    }
}


//-----------------------------------------------------------------------------


int SolveLin (double b, double c, double* x1) {



    if (IsZero (b)) {

        if (IsZero (c)) {

            return -2;
        }


        else {

            return 0;
        }
    }


    if (!IsZero (b)) {

        *x1 = ((-c) / b);
        return 1;
    }
}



//-----------------------------------------------------------------------------


int SolveSq (double a, double b, double c, double* x1, double* x2) {


    if (!IsZero (a)) {

        double d = ((b * b) - (4 * a * c));


        if (IsZero (d)) {

            *x1 = ((-b) / (2 * a));
            return 1;
        }


        if (!IsZero (d)) {


            if (d < 0) {

                return 0;
            }


            if (d > 0) {

                *x1 = (-b + sqrtf (d)) / (2 * a);
                *x2 = (-b - sqrtf (d)) / (2 * a);
                return 2;
            }
        }
    }

    if (IsZero (a)) {
        int n = SolveLin (b, c, x1);
        return n;
    }
}


//-----------------------------------------------------------------------------

double InputTest () {

    char inputek[100];


    int i = 0;
    int t = 0;
    int k = 0;
    int l = 0;
    double a = 0;
    double b = NAN;


    while (1) {
        
        //gets (inputek);
        scanf ("%s", &inputek);
        //printf("111111111111111111111\n");
        //printf("%s\n", &inputek[0]);
        //printf("111111111111111111111\n");

        for (i = 0; inputek[i] != '\0'; i++) {

            //printf ("1\n");

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
            sscanf (inputek, "%lf%lf", &a, &b);
            //printf ("%lf\n%lf\n", a, b);

            if (isnan (b)) {
                break;
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

//-----------------------------------------------------------------------------

void SolverTest () {

    double TestA[]  = { 0.1, 0,   0.01};
    double TestB[]  = {-0.2, 0,   0.01};
    double TestC[]  = { 0.1, 0,   0.01};
    int TestN[]     = { 1,  -2,   0   };
    double TestX1[] = { 1,   NAN, NAN };
    double TestX2[] = { NAN, NAN, NAN };

    int Tests = sizeof (TestN) / sizeof (int);

    int ResN[Tests];
    double ResX1[Tests];
    double ResX2[Tests];

    for (int i = 0; i < Tests; i++) {

        ResN[i] = SolveSq (TestA[i], TestB[i], TestC[i], &ResX1[i], &ResX2[i]);
        switch (ResN[i]) {
            case 1: if (IsEqual (ResX1[i], TestX1[i])) {
                printf ("Test %d OK :-)\n", i + 1);
            }
            else {
                printf ("Test %d very BAAD:\n X1 expected %lf, got %lf\n", i + 1, TestX1[i], ResX1[i]);
            }
            break;

            case 2: if (IsEqual (ResX1[i], TestX1[i]) && IsEqual (ResX2[i], TestX2[i])) {
                printf ("Test %d OK :-)\n", i + 1);
            }
            else {
                printf ("Test %d very BAAD:\n X1 expected %lf, got %lf\n X2 expected %lf, got %lf\n", i + 1, TestX1, ResX1, TestX2, ResX2);
            }
            break;

            default: if (IsEqual (TestN[i], ResN[i])){
                printf ("Test %d OK :-)\n", i + 1);
            }
            else {
                printf ("Test %d very BAAD:\n N expected %d, got %d\n", i + 1, TestN[i], ResN[i]);
            }
            break;
        }
    }
}








