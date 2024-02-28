#include <stdio.h>

void getinput_with_fgets() {
    char firstname[5];
    printf("Enter your first name");
    fgets(firstname, 5, stdin);
    printf("%s\n", firstname);
}

int main(int argc, char **argv) {
    // #define PI 3.14
    // const double pettycash = 0.2;
    // double grandtotal;

    // printf("%f\n", PI);
    // return 0;

    // char ageString[10];
    // int age;
    // int bonus;
    // gets(ageString);

    getinput_with_fgets();
}