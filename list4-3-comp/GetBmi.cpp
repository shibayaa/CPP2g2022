#include"getBmi.h"
double getBmi(double height, double weight)
{
    double bmi;
    height /= 100;
    bmi = weight / height / height;
    return bmi;
}