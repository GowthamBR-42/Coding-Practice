#include <stdio.h>
int main()
{
    int priority[50],time[50],n=0,choice,i,j,key,gap,temp;
    printf("\n--- HOSPITAL PATIENT MANAGEMENT ---\n");
    printf("1. Add Patient\n");
    printf("2. Display Patients\n");
    printf("3. Sort by Emergency Priority (Insertion Sort)\n");
    printf("4. Sort by Waiting Time (Shell Sort)\n");
    printf("5. Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(n==50)
                {
                    printf("Patient list is full\n");
                    break;
                }
                printf("Enter Emergency Priority (1-High, 2-Medium, 3-Low): ");
                scanf("%d",&priority[n]);
                printf("Enter Waiting Time in minutes: ");
                scanf("%d",&time[n]);
                if(priority[n]<1 || priority[n]>3 || time[n]<0)
                {
                    printf("Invalid patient details\n");
                    break;
                }
                n++;
                printf("Patient added successfully\n");
                break;
            case 2:
                if(n==0)
                {
                    printf("No patient records available\n");
                    break;
                }
                printf("\nPriority\tWaiting Time\n");
                for(i=0;i<n;i++)
                    printf("%d\t\t%d minutes\n",priority[i],time[i]);
                break;
            case 3:
                for(i=1;i<n;i++)
                {
                    key=priority[i];
                    temp=time[i];
                    j=i-1;
                    while(j>=0 && priority[j]>key)
                    {
                        priority[j+1]=priority[j];
                        time[j+1]=time[j];
                        j--;
                    }
                    priority[j+1]=key;
                    time[j+1]=temp;
                }
                printf("Patients sorted by emergency priority\n");
                break;
            case 4:
                for(gap=n/2;gap>0;gap/=2)
                {
                    for(i=gap;i<n;i++)
                    {
                        key=time[i];
                        temp=priority[i];
                        for(j=i;j>=gap && time[j-gap]>key;j-=gap)
                        {
                            time[j]=time[j-gap];
                            priority[j]=priority[j-gap];
                        }
                        time[j]=key;
                        priority[j]=temp;
                    }
                }
                printf("Patients sorted by waiting time\n");
                break;
            case 5:
                printf("Exiting Hospital Management System\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=5);
    return 0;
}
