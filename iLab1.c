#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, d, x, x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);


    if (a == 0)
    {


        if (b == 0)
        {
            if (c == 0)
            {
                printf("x = anything u can imagine");
            }


            else
            {
                printf("no real roots error");
            }
        }


        else
        {
            printf("1 root, ");
            x = (-c) / b;
            printf("x = %lf", x);
        }
    }


    else
    {
        d = (b*b - 4*a*c);


        if (d > 0)
        {
            printf("2 roots, ");
            x1 = (-b + sqrt(d))/(2*a);
            x1 = (-b - sqrt(d))/(2*a);
            printf("x1 = %lf", x1);
            printf(", x2 = %f", x2);
        }


        if (d == 0)
        {
            printf("1 root, ");
            x = (-b)/(2*a);
            printf("x = %lf", x);
        }


        if (d < 0)
        {
            printf("no real roots error");
        }

    }
return 0;
}

