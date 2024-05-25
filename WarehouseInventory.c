#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
char arr1[MAX][MAX];
char arr2[MAX][MAX];
char a;
int size1=-1;
int size2=-1;
int sized1=-1,sized2=-1;
int front1=-1;
int rear1=-1;
int front2=-1,rear2=-1;
int c1=0,c2=0;
int d1=0,d2=0;
int frontd1=-1;
int reard1=-1;
int frontd2=-1;
int reard2=-1;
int choice;
char date1[MAX][MAX];
char date2[MAX][MAX];

void enqueue_date1(char *b){
  if (frontd1==-1&& reard1==-1)
  {
    strcpy(date1[++sized1], b);
    frontd1=sized1;
    reard1=sized1;
  }
  else{
        strcpy(date1[++sized1], b);
        reard1=sized1;

    }
   
}
void enqueue_date2(char *b){
  if (frontd2==-1&& reard2==-1)
  {
    strcpy(date2[++sized2], b);
    frontd2=sized2;
    reard2=sized2;
  }
  else{
        strcpy(date2[++sized2], b);
        reard2=sized2;

    }
   
}
void enqueue1(char *b){
    if(rear1==MAX-1){
      printf("Warehouse is full for TV");
    }
    if(front1==-1&& rear1==-1){
        strcpy(arr1[++size1], b);
        front1=size1;
        rear1=size1;
    }
    else{
        strcpy(arr1[++size1], b);
        rear1=size1;

    }
    

}
void enqueue2(char *b){
    if(rear2==MAX-1){
      printf("Warehouse is full for FRIDGE");
    }
    else if(front2==-1&& rear2==-1){
        strcpy(arr2[++size2], b);
        front2=size2;
        rear2=size2;
    }
    else{
        strcpy(arr2[++size2], b);
        rear2=size2;

    }
    

}
void display1(char a[MAX][MAX],char b[MAX][MAX],int f,int r){
    
    for (int i = f; i <= r; i++) {
        printf("%s , %s \n", a[i],b[i]);
    }
}
void add(int ch){
  int chh=ch;
  char *str1,*str2,*str11,*str22;
  str1 = malloc(sizeof(char));
  str2 = malloc(sizeof(char));
  str11 = malloc(sizeof(char));
  str22 = malloc(sizeof(char));

  if(chh==1){
    printf("Enter name of the TV: ");
    scanf("%s", str1);
    rear1++;
    printf("Enter date: ");
    scanf("%s", str2);
    reard1++;
    enqueue1(str1);
    enqueue_date1(str2);
    display1(arr1,date1,front1,rear1);
    

  }
  else if(chh==2){
         printf("Enter name of the FRIDGE: ");
         scanf("%s", str11);
         printf("Enter date: ");
         scanf("%s", str22);
         rear2++;
         reard2++;
         enqueue2(str11);
         
         enqueue_date2(str22);
         
         display1(arr2,date2,front2,rear2);

  }
  else{
    printf("Wrong choice");
  }
}
void dequeue_buy(int choice) { 
  
  if (choice==1)
  {
    if (front1 == -1 || front1 > rear1) {  
        printf("No products \n");  
    }  
    else{
        //char element = arr1[front1];  
        printf("Brought %s \n",arr1[front1]);
        front1++;
    }
  }
  else if (choice==2)
  {
    if (front2 == -1 || front2 > rear2) {  
        printf("No Produts \n");  
    }  
    else{
        //char element = arr2[front2];  
        printf("Brought  %s \n",arr2[front2]);
        front2++;
    }
  }
  
   
    
}  
int main(){
    front1++;
    rear1++;
    enqueue1("LG-OLED");
    rear1++;
    enqueue1("LG-OLED");
    front2++;
    rear2++;
    enqueue2("SAMSUNG-FRIDGE");
    rear2++;
    enqueue2("SAMSUNG-FRIDGE");
    rear2++;

    frontd1++;
    reard1++;

    enqueue2("SAMSUNG-FRIDGE");
    //display(arr,c);
    reard1++;
    enqueue_date1("2023-01-12");
    reard1++;
    enqueue_date1("2023-01-20");
    frontd2++;
    reard2++;
    enqueue_date2("2023-01-20");
    reard2++;
    enqueue_date2("2023-02-19");
    reard2++;
    enqueue_date2("2023-02-26");
    int n,num,ch;
    char name,day;
    while(1){
      printf("1. Display Products\n2. Add Products\n3. Buy Products\n4.Exit\n");
      printf("Enter choice: ");
      scanf("%d",&n);
      switch(n){
      case 1:
      printf("ALL AVAILABLE TELEVISIONS: \n");
      display1(arr1,date1,front1,rear1);
      printf("ALL AVAILABLE FRIDGES: \n");
      display1(arr2,date2,front2,rear2);
      break;
      case 2:
      printf("Enter 1 for TV and 2 for FRIDGE: ");
      scanf("%d",&ch);
      add(ch);
      break;
      case 3:
      printf("What would you like to buy ?? \n");
      display1(arr1,date1,front1,rear1);
      display1(arr2,date2,front2,rear2);
      printf("For TV 1 and 2 for fridge");
      scanf("%d",&choice);
      dequeue_buy(choice);
      break;
      case 4:
      printf("THANK YOU !!!");
      exit(0);
      default:
      break;
      }
    } 
}






























/*#include <stdio.h>
#include <string.h>

int main() {
  char dates[] = {"2020-10-11", "2023-10-11"};

  int result = strcmp(dates[0], dates[1]);

  if (result < 0) {
    printf("The first date is less than the second date.\n");
  } else if (result > 0) {
    printf("The first date is greater than the second date.\n");
  } else {
    printf("The two dates are equal.\n");
  }

  return 0;
}*/
/*void display1(){
  for(int i=0;i<c;i++){
    printf("%s , %s \n", arr[i],date[i]);
  }
}*/


