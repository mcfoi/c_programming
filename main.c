#include <stdio.h>
#include <stdlib.h>

#include "functions.h"


int main()
{
    // ONLINE C LESSONS
    // https://www.youtube.com/c/KrisJordan/search?query=C

    // CASTING
    printf("Casting a double to int: %d \n", (int)3.14);

    // ###################################################################
    // POINTERS
    // In C the operator '*' when used as prefix of far name is called "ADDRESS OF" Operator

    // MEMORY IN C – THE STACK, THE HEAP, AND STATIC
    // https://craftofcoding.wordpress.com/2015/12/07/memory-in-c-the-stack-the-heap-and-static/
    // Video on 'malloc'
    // https://www.youtube.com/watch?v=3Fegr6Jm4Ec

    // VIDEO : https://www.youtube.com/watch?v=eJ_Wt34dDXU
    int eleven = 11; // Set an int var
    int *pointerToEleven = &eleven; // Store memory address of var into a pointer
    int memAddressOfEleven = &eleven; // Store memory address of var into an int var
    printf("'pointerToEleven' address: %X \n", pointerToEleven); // Print memory address of pointer
    printf("'pointerToEleven' value: %d \n", *pointerToEleven); // Dereference pointer by reading the memory address it refers to
    printf("'eleven' value: %d \n", eleven); // Print the int var value

    int *rebuiltPointerFRomMemAddress = memAddressOfEleven; // Create a new pointer pointing to the memory address of 'eleven' var
    printf("'rebuiltPointerFRomMemAddress' var as decimal: %d \n", *rebuiltPointerFRomMemAddress); // Read the value at the memory address pointed by the pointer: WORKS!!

    // POINTERS : more playing
    printf("ten = 10;\n");
    int ten = 10;
    printf("'ten' var as decimal: %d \n", ten);
    // Getting the value of the memory address containing the variable 'ten: put an '&' before the var name
    // &ten returns the memory address
    printf("pointer address of 'ten' var as HEX: %p \n", &ten);
    printf("pointer address of 'ten' var as INT: %d \n", &ten);
    // Storing memory address of variable in a pointer variable
    // => create a pointer var using the '*' prefix
    // Note: we are using 'int'
    int *pTen = &ten;
    // Print pointer as decimal : this is calling 'dereferencing' the pinter as we get the value stored in the memory address, not the pointer to the value
    printf("'ten' var as dereferenced value from pointer: %d \n", *pTen);
    // Print pointer as pointer
    printf("'ten' var as pointer hex memory address: %p \n", pTen);
    // If we do not use '*' we just store in the var the value of the memory address
    int tenMemAdd = &ten;
    printf("'tenMemAdd' var as value: %d \n", tenMemAdd);
    // Rebuild a pointer knowing its memory address
    int *rebuiltTenPointer = tenMemAdd;
    // Inspect the value at the memory address stored in the pointer
    printf("'ten' var as dereferenced value from pointer 'rebuiltTenPointer': %d \n", *rebuiltTenPointer);
    // TEST: REBUILD POINTER FROM MEMORY ADDRESS
    // Rebuild a pointer knowing its memory address
    int *rebuiltUnknownPointer = ++tenMemAdd;
    printf("Memory address of rebuiltUnknownPointer as HEX: %p \n", rebuiltUnknownPointer);
    printf("Memory address of rebuiltUnknownPointer as INT: %d \n", rebuiltUnknownPointer);
    // Inspect the value at the memory address stored in the pointer
    printf("Content of random memory address as dereferenced value from pointer 'rebuiltUnknownPointer': %d \n", *rebuiltUnknownPointer);
    // TEST ON FLOAT
    float onethird = 1 / 3.0;
    printf("'onethird' var as float: %f \n", onethird);
    float *pOnethird = &onethird;
    printf("Memory address of pointer *pOnethird as HEX %p:\n", *pOnethird);
    printf("Value stored in Memory address of pointer *pOnethird: %f\n", *pOnethird);
    printf("Memory address as HEX (lower) value of pointer pOnethird %x:\n", pOnethird);
    printf("Memory address as HEX (capital) value of pointer pOnethird %X:\n", pOnethird);
    // ###################################################################

    // USER INPUT
    /*
    char name[100];
    int age;
    double height;
    printf("Enter name (max 100 char): ");
    fgets(name, 100, stdin);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter height: ");
    scanf("%lf", &height);
    printf("You are %s and you are %d years ols, %f mt tall\n", name, age, height);
    */

    // ARRAYS
    int intNumbers[] = {3, 5, 7};
    printf("Array: int intNumbers[] = {3, 5, 7} \n");
    printf("First element of array : %d \n", intNumbers[0]);
    intNumbers[0] = 30;
    printf("First element of array : %d \n", intNumbers[0]);

    int arrayOfArraysOfInt[2][3] = {{1,2,3},{4,5,6}};
    printf("Array of arrays: int intNumbers[] = {{1,2,3},{4,5,6}} \n");
    printf("First element of second array : %d \n", arrayOfArraysOfInt[1][0]);

    // FUNCTIONS
    /*
    int addNumbers(int num1, int num2){
        return num1 + num2;
    }
    */
    // Can use the function defined AFTER 'main()' because we declared its stub BEFORE 'main()'
    int addedNumbers = addNumbers(5, 56);
    printf("Added numbers: %d \n", addedNumbers);

    // Declare a data structure 'x' and name it 'Student' : we MUST avoid using 'struct'
    Student stu1;
    stu1.age = 48;
    stu1.name = "Marco";
    printf("\nStudent stu1: %s, %d \n", stu1.name, stu1.age);

    // Create a struct of type 'Studente' : requires using 'struct'
    struct Studente stu_1;
    stu_1.age = 50;
    stu_1.name = "MarcoIlVecchio";
    printf("Studente stu_1: %s, %d \n", stu_1.name, stu_1.age);

    // Zero initialization of struct
    // https://youtu.be/qqtmtuedaBM?t=543
    struct Studente stu_2 = {0}; // From C99
    printf("Studente stu_2: %s, %d \n", stu_2.name, stu_2.age);
    // Inline intialization
    struct Studente stu_3 = {14, "Davide"};
    printf("Studente stu_3: %s, %d \n", stu_3.name, stu_3.age);

    printf("\n");

    StudentPrint(stu1);

    // MALLOC : allocate memory in HEAP SPACE for single data structure
    size_t size = 10; // 'size_t' is a standard type defined in stdlib.h and each unit is 1 byte
    char *str = malloc(size); // 'malloc' is definded in stdlib.h and accepts a size defined using the type 'size_t'
    // We MUST check for the returned pointer to handle OUT OF MENORY issues
    if (str == NULL){
        fprintf(stderr, "Out of Memory");
        exit(EXIT_FAILURE);
    }
    // Add data in array, char by char, leaving last element empty fro string terminator \0
    for (size_t i = 0; i < size - 1; i++){
        str[i] = 'a' + i;
        printf("Char in 'str': %c\n", str[i]);
    }
    // Add string termination char
    str[size - 1] = '\0';
    printf("Stringa 'str': %s\n", str); // This REQUIRES the array of chars to be \0 terminated!!!
    // Release memory
    free(str);
    // Set pointer to null to prevent reusing
    str = NULL;

    return 0;
}
