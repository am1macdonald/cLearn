#include <stdio.h>

/*
 * This is a comment
 */
/*
main() {
 int fahr, celsius;
 int lower, upper, step;

 lower = 0;
 upper = 300;
 step = 20;

 fahr = lower;

 while (fahr <= upper) {
     celsius = 5 * (fahr - 32) /9;
     printf("%d\t%d\n", fahr, celsius);
     fahr = fahr + 20;
 }
}
*/

//main() {
//    int fahr, celsius;
//    int lower, upper, step;
//
//    lower = 0;
//    upper = 300;
//    step = 20;
//
////    while (fahr <= upper) {
////        celsius = 5 * (fahr - 32) /9;
////        printf("%3.0f\t%6.1f\n", fahr, celsius);
////        fahr = fahr + 20;
////    }
//
//    for (fahr = upper; fahr >= lower; fahr = fahr - step) {
//        celsius = 5 * (fahr - 32) / 9;
//        printf("%d\t%d\n", fahr, celsius);
//    }
//}

#define LOWER  0 /* lower limit of table*/
#define UPPER  300 /* upper limit of table*/
#define STEP   20 /* step size */

main() {
    int fahr;
    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
        printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}
