//Wesley Baker and Adam Ringwell Monitor Code.
#include<stdio.h>

int x; //Define types
int y;

void function(int var){ // Function to add the variables passed into each other.
    printf("\nFunction Begins\n");
    printf("%d", var);
    
        printf(" plus %d", var);
       var = var + var; //Add the integer passed in together.
        printf(" = %d", var);
    printf("\nFunction Ends\n");
}

int main(){
    x = 5;
    y = 4;
    function(x); //Run the function with the variable x.
    function(y); //After the function(x) is done run the function(y).
    return 0;
}