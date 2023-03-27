#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    int j, k=0;
    double e;
    char st[80], ch; 
    // Read and save an integer, double, and String to your variables.
    scanf("%d", &j);
    j = j + i;
    scanf("%lf", &e);
    e = e + d;
    while(s[k] != '\0'){
        st[k] = s[k];
        k++; 
    }
    fflush(stdin);
    while((st[k++] = getchar()) != '\n');
    k--;
    st[k] = '\0';
    // Print the sum of both integer variables on a new line.
    printf("%d\n", j);
    // Print the sum of the double variables on a new line.
    printf("%lf\n", e);
    // Concatenate and print the String variables on a new line
  
    printf("%s", st);

    // The 's' variable above should be printed first.

    return 0;
}