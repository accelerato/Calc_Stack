#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float stack[1000];
int item = 0;

void push(int number)
{
    stack[item] = number;
    ++item;
}

void pop(void)
{
    --item;
    stack[item] = 0;
}

int main(int argc, char* argv[])
{
    int i;
    double result;

    if (argc > 1)
    {
        for(i = 1; i<argc; i++)
        {
            
            if(strcmp(argv[i],"+") == 0)
            {
                result = stack[item-2] + stack[item-1];
                pop();
                pop();
                push(result);
                printf("%f\n",result);
            }else if(strcmp(argv[i],"-") == 0)
            {
                result = stack[item-2] - stack[item-1];
                pop();
                pop();
                push(result);
                printf("%f\n",result);
            }else if(strcmp(argv[i],"*") == 0)
            {
                result = stack[item-2] * stack[item-1];
                pop();
                pop();
                push(result);
                printf("%f\n",result);
            }else if(strcmp(argv[i],"/") == 0)
            {
                result = stack[item-2] / stack[item-1];
                pop();
                pop();
                push(result);
                printf("%f\n",result);
            }else 
            {
                push(atof(argv[i]));
                printf("%f\n",stack[item-1]);
            }
        }
    }
    else printf("Error!Not enough arguments");

    return 0;
}
