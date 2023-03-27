#include<stdlib.h>
#include <stdio.h>
  
int main()
{
    FILE* file;
  
    // opening the file in read-only mode
    file = fopen("myFile.txt", "r");
  
    printf("File opening successful!");
  
    // EXIT_SUCCESS
    exit(0);
}