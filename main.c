#include "main.h"
#include <limits.h>

int main(void)
{
    /* Declare all variables at the start of the function */
    char str[] = "This is a long string for testing purposes to see how well the _printf handles it.";

    _printf("Let's print a simple sentence.\n");
    _printf("%c", 'S');
    _printf("A char inside a sentence: %c. Did it work?\n", 'F');
    _printf("Let's see if the cast is correctly done: %c. Did it work?\n", 48);
    _printf("%s", "This sentence is retrieved from va_args!\n");
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
    _printf("%%");
    _printf("Should print a single percent sign: %%\n");
    _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
    _printf("css%ccs%scscscs", 'T', "Test");
    _printf(str);
    _printf("man gcc:\n%s", str);

    return 0;
}
