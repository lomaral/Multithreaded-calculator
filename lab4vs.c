#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define OPERATION_NUM 5
pthread_mutex_t mutex;

//intializing a struct for the parts of the calculator
typedef struct {
    double firstNum;
    double secondNum;
    double result;
} Calc

//thread to take care of adding numbers
void *add(void *param){
    Calc *adding = param;
    pthread_mutex_lock(&mutex);
    adding->result= adding->firstNum + adding->secondNum;
    pthread_mutex_unlock(&mutex);
}

//thread to take care of subtracting numbers
void *subtract(void *param){
    Calc *subtracting = param;
    pthread_mutex_lock(&mutex);
    subtracting->result= subtracting->firstNum - subtracting->secondNum;
    pthread_mutex_unlock(&mutex);
}


//thread to care of multiplying numbers
void *multiplication(void *param){
    Calc *multi = param;
    pthread_mutex_lock(&mutex);
    multi->result= multi->firstNum * multi->secondNum;
    pthread_mutex_unlock(&mutex);
}

//thread to care of dividing numbers
void *divide(void *param){
    Calc *div = param;
    pthread_mutex_lock(&mutex);
    div->result= div->firstNum / div->secondNum;
    pthread_mutex_unlock(&mutex);
}

//thread to take care of exponenents
void *exp(void *param){
    Calc *carrot = param;
    pthread_mutex_lock(&mutex);
    carrot->result= pow(carrot->firstNum, carrot->secondNum);
    pthread_mutex_unlock(&mutex);
}

int main()
{
    //initalizes threads and mutex
    pthread_t tid[OPERATION_NUM];
    pthread_mutex_init(&mutex, NULL);

    //getting the numbers for the calculator
    Calc c1;
    char operation[5];
    printf("Enter a number: \n");
    scanf("%lf", &c1.firstNum );
    printf("Enter a second number: \n");
    scanf("%lf", &c1.secondNum );
    printf("Enter an operation (+, /, *, -, ^): \n");
    scanf("%s",operation);

    //sees which thread to create for which operation
    if(strcmp(operation, "+")==0)
    {
        pthread_create(&tid, NULL, add, &c1);
    }
    else if(strcmp(operation, "-")==0)
    {
        pthread_create(&tid, NULL, subtract, &c1);
    }
    else if(strcmp(operation, "*")==0)
    {
        pthread_create(&tid, NULL, multiplication, &c1);
    }
    else if(strcmp(operation, "/")==0)
    {
        pthread_create(&tid, NULL, divide, &c1);
    }
    else if(strcmp(operation, "^")==0)
    {
        pthread_create(&tid, NULL, exp, &c1);
    }
    
    //join each thread
    pthread_join(tid[i], NULL);


    printf("sum = %d\n", sum);

    return 0;
}

