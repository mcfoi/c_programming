#include <stdio.h> // Is using < and > as is addressing a file in standard system directories

#include "functions.h" // Is using double-quotes as is addressing a file in current directory

int addNumbers(int num1, int num2)
{
    return num1 + num2;
}

void StudentPrint(Student student){
    printf(" => %s is aged: %d\n", student.name, student.age);
}
