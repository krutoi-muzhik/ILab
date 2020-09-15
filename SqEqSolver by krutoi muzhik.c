
#include <stdio.h>
#include <math.h>
#include "TXLib.h"

//-----------------------------------------------------------------------------


int SolveLin (double a, double b, double* x);

int SolveSq (double a, double b, double c, double* x, double* x1, double* x2);

bool IsZero (double* m);

void SqEqSolver2020Test ();


//-----------------------------------------------------------------------------


const long double MicroNum = 1e-6;


//-----------------------------------------------------------------------------





int main () {



    //SqEqSolver2020Test ();
    //return 0;



    printf ("welcome to SqEqSolver2020 by krutoi_muzhik \n");
    printf ("enter ur a, b, c variables \n");


   printf ("                       a = ");
    double a = 0;
    while (scanf ("%lf", &a) != 1) {
        printf ("input error, please enter real numbers \n                       a = ");
        fflush (stdin);
    }

    double b = 0;
    printf ("                       b = ");
    while (scanf ("%lf", &b) != 1) {
        printf ("input error, please enter real numbers \n                       b = ");
        fflush (stdin);
    }

    double c = 0;
    printf ("                       c = ");
    while (scanf ("%lf", &c) != 1) {
        printf ("input error, please enter real numbers \n                       c = ");
        fflush (stdin);
    }

    double x = 0;
    double x1 = 0;
    double x2 = 0;
    int n = 10;
    double m = 0;


    if (a != 0) {

        n = SolveSq (a, b, c, & x, & x1, & x2);
    }


    if (a == 0) {

        n = SolveLin (b, c, & x);
    }


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


        if (IsZero (&x)){

            x = 0;
        }

        printf ("1 root \n");
        printf ("x = %lf", x);
    }


    if (n == 2) {


        if (IsZero (&x1)) {

            x1 = 0;
        }


        if (IsZero (&x2)) {

            x2 = 0;
        }

        printf ("2 roots \n");
        printf ("x1 = %lf \n", x1);
        printf ("x2 = %lf", x2);
    }
}


//-----------------------------------------------------------------------------


bool IsZero (double* m) {

    return (fabs (*m) < MicroNum);
}


//-----------------------------------------------------------------------------


int SolveLin (double a, double b, double* x) {



    if (IsZero (&a)) {

        if (IsZero (&b)) {

            return -2;
        }


        else {

            return -1;
        }
    }


    if (!IsZero (&a)) {

        *x = ((-b) / a);
        return 1;
    }
}


//-----------------------------------------------------------------------------


int SolveSq (double a, double b, double c, double* x, double* x1, double* x2) {



    double d = ((b * b) - (4 * a * c));


    if (IsZero (&d)) {

        *x = ((-b) / a);
        return 1;
    }


    else {


        if (d < 0) {

            return 0;
        }


        if (d > 0) {

            *x1 = (-b + sqrt (d)) / (2 * a);
            *x2 = (-b - sqrt (d)) / (2 * a);
            return 2;
        }
    }
}

void SqEqSolver2020Test() {

    printf ("Tester mode ON: \n");

    double x = 0;
    int n = 0;
    double x1 = 0;
    double x2 = 0;

    n = SolveLin (0, 0, &x);


    if (n == -2) {

        $g; printf ("Test 0 0 0 OK \n");
    }


    else {

        $r; printf (" Test 0 0 0 BAD: \n SOlveLin(0, 0, ...): n = -2 expected, but n = %lf got", n);
    }


    n = SolveSq (1, 2, 3, &x, &x1, &x2);


    if (n == 0) {

        $g; printf ("Test 1 2 3 OK \n");
    }


    else {

        $r; printf ("Test 1 2 3 BAD: \n SolveSq(1, 2, 3, ...): n = 0 expected, but n = %lf got", n);
    }
}







