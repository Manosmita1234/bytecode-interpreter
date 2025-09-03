#include <stdio.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int sp = -1;


enum opcode {
    OP_PUSH,
    OP_ADD,
    OP_SUBTRACTION,
    OP_MULTIPLY,
    OP_DIVISION,
    OP_PRINT,
    OP_DUPLICATE,
    OP_SWAP
};

void push(int value){
   if(sp < STACK_SIZE-1){
    stack[++sp] = value;
   }
   else{
    printf("stack overflow\n");
   }
}

int pop(){
    if(sp>=0){
        return stack[sp--];
        }
        else{
            printf("stack underflow\n");
        }
        
}


int main(){
    int program[]={
        OP_PUSH,5,
        OP_PUSH,10,
        OP_SWAP,OP_SUBTRACTION,
        OP_PRINT
    };

    int pc = 0;
    while(pc < sizeof(program)/sizeof(int)){
        int instruction = program[pc++];
        
        switch(instruction){
            case OP_PUSH: {
                int value = program[pc++];
                push(value);
                break;
            }

            case OP_ADD:{
                int b = pop();
                int a = pop();
                push(a+b);
                break;
            }

            case OP_PRINT:{
                int value = pop();
                printf("%d\n", value);
                break;
            }

            case OP_SUBTRACTION : {
                int b = pop();
                int a = pop();
                push(a-b);
                break;
            }

            case OP_MULTIPLY : {
                int b = pop();
                int a = pop();
                push(a*b);
                break;
            }

            case OP_DIVISION : {
                int b = pop();
                int a = pop();
                push(a/b);
                break;
            }

            case OP_DUPLICATE : {
                if(sp>=0){
                    int value = stack[sp];
                    push(value);
                }
                else{
                    printf("stack is empty");
                }
            }

            case OP_SWAP : {
                int topValue = stack[sp];
                int bottomValue = stack[sp-1];
                stack[sp-1] = topValue;
                stack[sp] = bottomValue;
                break;
            }
        }
    }
}


