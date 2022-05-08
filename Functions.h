// Compiler INCLUDE GUARDS: checks if a pre-compiler far named 'FUNCTIONS_H ' is declared
// and proceeds if not: this prevents multiple re-declarations of functions.
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// STUB OF FUNCTIONS DECLARED AFTER 'main()'
int addNumbers(int num1, int num2);

/**
 * Define a anonymous struct and wrap it into an alias named 'Student'
 * typedef <struct> <new-name>
 */
typedef struct {
    int age;
    char *name;
} Student;

// We can also use a named struct
typedef struct Animal{
    int age;
    char *name;
} Animal;

/**
 * Define a struct named 'Studente'
 */
struct Studente{
    int age;
    char *name;
};

void StudentPrint(Student student);

#endif // FUNCTIONS_H
