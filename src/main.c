#include <stdio.h>
#include <math.h>
#define E 0.000001
#define E_f 0.000001f

double distance_d(double x1, double x2){
    return sqrt((x1-1)*(x1-1) + (x2-1)*(x2-1));
}

float distance_f(float x1, float x2){
    return sqrtf((x1-1)*(x1-1) + (x2-1)*(x2-1));
}

int solve_d(){
    double x1, x2, delta=0.0001, dist=1;
    int iter=0;
    while (dist > E){
        x2=(0.0001+delta)/0.0001;
        x1=2. - x2;
        dist=distance_d(x1,x2);
        printf("delta=%.20f, x1=%.20f, x2=%.20f, difference=%.20f\n",  delta, x1, x2, dist);
        delta /= 2;

        if (iter >= 100) break;
        iter++;
    }
    return iter;
}

int solve_f(){
    float x1, x2, delta=0.0001f, dist=1;
    int iter=0;
    while (dist > E_f){
        x2=(0.0001f+delta)/0.0001f;
        x1=2.f - x2;
        dist=distance_f(x1,x2);
        printf("delta=%.20f, x1=%.20f, x2=%.20f, difference=%.20f\n",  delta, x1, x2, dist);
        delta /= 2;

        if (iter >= 100) break;
        iter++;
    }
    return iter;
}

int solve_the_wrong_way_d(){
    double x1, x2, delta=0.0001, dist=1;
    int iter=0;
    while (dist > E){
        x2=(2.0001-2.+delta)/(1.0001-1.);
        x1=2. - x2;
        dist=distance_d(x1,x2);
        printf("delta=%.20f, x1=%.20f, x2=%.20f, difference=%.20f\n",  delta, x1, x2, dist);
        delta /= 2;

        if (iter >= 100) break;
        iter++;
    }
    return iter;
}

int solve_the_wrong_way_f(){
    float x1, x2, delta=0.0001f, dist=1;
    int iter=0;
    while (dist > E_f){
        x2=(2.0001f-2.f+delta)/(1.0001f-1.f);
        x1=2.f - x2;
        dist=distance_f(x1,x2);
        printf("delta=%.20f, x1=%.20f, x2=%.20f, difference=%.20f\n",  delta, x1, x2, dist);
        delta /= 2;

        if (iter >= 100) break;
        iter++;
    }
    return iter;
}

int main(){
    printf("\ndouble the right way:\n");
    printf("number of iterations=%d\n", solve_d());

    printf("\nfloat the right way:\n");
    printf("number of iterations=%d\n", solve_f());

    printf("\ndouble the wrong way:\n");
    printf("number of iterations=%d\n", solve_the_wrong_way_d());

    printf("\nfloat the wrong way:\n");
    printf("number of iterations=%d\n", solve_the_wrong_way_f());
    return 0;
}