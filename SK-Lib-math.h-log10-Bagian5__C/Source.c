#pragma warning(disable:4996)
#pragma fenv_access (on)

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <fenv.h>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main(void) {
    printf("log10(1000) = %f\n", log10(1000));
    printf("log10(0.001) = %f\n", log10(0.001));
    printf("base-5 logarithm of 125 = %f\n", log10(125) / log10(5));
    // special values
    printf("log10(1) = %f\n", log10(1));
    printf("log10(+Inf) = %f\n", log10(INFINITY));
    //error handling
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("log10(0) = %f\n", log10(0));

    if (errno == ERANGE) {
        perror("    errno == ERANGE");
    }

    if (fetestexcept(FE_DIVBYZERO)) {
        puts("    FE_DIVBYZERO raised");
    }

    _getch();
    return 0;
}