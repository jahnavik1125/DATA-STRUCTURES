#include<stdio.h>
#include<stdlib.h>

struct employee {
        int id;
        char name[50];
        float salary;
        };

int main()
{
  int i,n;
  float sum=0;

  printf("enter the no.of employees\n");
  scanf("%d",&n);
  struct employee *emp=(struct employee*)malloc(n*sizeof(struct employee));
  {
  if(emp==NULL)
      printf("memory allocation failed\n");
     }
  for (i=0;i<n;i++) {
  printf("\nEnter details of employee %d\n:",i+1);

  printf("ID:\n");
  scanf("%d",&emp[i].id);

  printf("Name: ");
  scanf("%s",emp[i].name);

  printf("Salary: ");
  scanf("%f",&emp[i].salary);

   sum+= emp[i].salary;
 }

 printf("The total salary per month is %f\n",sum);
 printf("Annual salary is: %f\n",sum*12);
 free(emp);
 return 0;
 }


