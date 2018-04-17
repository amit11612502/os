#include<stdio.h>
struct processes
{
    char process_name;
    int arrTime,brustTime,ct,waitTime,tt,pri,brustTime1;
}pro[10],pro1[10];
int main()
{
	struct processes temp;
    int i,time=0,t1,t2,bu_t=0,largest,limit,count=0,k,pf2=0,limit2,n,Position,j,flag=0,y;
    float wait_time=0,turnaround_time= 0,average_waiting_time,average_turnaround_time;
    printf("\nEnter Number of Processes:\t");
    scanf("%d",&limit);
    n=limit;
    for(i=0;i<limit;i++)
    { 
    	printf("\nEnter Process name:-");
    	fflush(stdin);
        scanf("%c",&pro[i].process_name);
        printf("\nEnter Details For processor %c:\n",pro[i].process_name);
        printf("Enter Arrival Time for each process:-");
        scanf("%d",&pro[i].arrTime);
        printf("Enter Burst Time for each process:-");
        scanf("%d",&pro[i].brustTime);
        pro[i].brustTime1=pro[i].brustTime;
        printf("Enter Priority:\t");
        scanf("%d",&pro[i].pri);
    }
    printf("\nEnter Time Quantum for Fixed priority queue:-");
    scanf("%d",&t1);
    printf("\nEnter Time Quantum for Round Robin queue:-");
    scanf("%d",&t2);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(i=0;i<limit;i++)
    {
        Position=i;
        for(j=i+1;j<limit;j++)
        {
            if(pro[j].arrTime<pro[Position].arrTime)
                Position=j;
        }
        temp=pro[i];
        pro[i]=pro[Position];
        pro[Position]=temp;
    }
    time=pro[0].arrTime;
    for(i=0;limit!=0;i++)
    {
    	while(count!=t1)
    	{
    		count++;
    		if(pro[i].arrTime<=time)
    		{
    			for(j=i+1;j<limit;j++)
    			{
    				if(pro[j].arrTime==time&&pro[j].pri<pro[i].pri)
    				{
    					pro1[pf2]=pro[i];
						pf2++;
    					for(k=i;k<limit-1;k++)
    						pro[k]=pro[k+1];
    					limit--;
						count=0;
    					i=j-1;
    					j--;
					}
				}
			}
			time++;
			pro[i].brustTime--;
			if(pro[i].brustTime==0)
			{
				pro[i].tt=time-pro[i].arrTime;
				pro[i].waitTime=pro[i].tt-pro[i].brustTime1;
				printf("%c\t|\t%d\t|\t%d\n",pro[i].process_name,pro[i].tt,pro[i].waitTime);
				wait_time+=time-pro[i].arrTime-pro[i].brustTime1; 
    			turnaround_time+=time-pro[i].arrTime;
    			for(k=i;k<limit-1;k++)
    				pro[k]=pro[k+1];i--;
    			limit--;
				count=t1;break;
			}
		}
		count=0;
		if(pro[i].brustTime!=0)
		{
			pro1[pf2]=pro[i];
			pf2++;
			for(k=i;k<limit-1;k++)
    			pro[k]=pro[k+1];
    		limit--;
		}
			if(i==limit-1)
				i=-1;
	}
	
	limit2=pf2;
	for(count=0;limit2!=0;) 
	{ 
		if(pro1[count].brustTime<=t2&&pro1[count].brustTime>0) 
    	{ 
    		time+=pro1[count].brustTime; 
    		pro1[count].brustTime=0; 
    		flag=1; 
    	} 
    	else if(pro1[count].brustTime>t2) 
    	{ 
    		pro1[count].brustTime-=t2; 
    		time+=t2; 
    	} 
    	if(pro1[count].brustTime==0&&flag==1) 
    	{ 
    		limit2--; 
    		pro1[count].tt=time-pro1[count].arrTime;
			pro1[count].waitTime=pro1[count].tt-pro1[count].brustTime1; 
			printf("%c\t|\t%d\t|\t%d\n",pro1[count].process_name,pro1[count].tt,pro1[count].waitTime); 
    		turnaround_time+=time-pro1[count].arrTime; 
    		wait_time+=time-pro1[count].arrTime-pro1[count].brustTime1;
    		for(k=count;k<limit2;k++)
    			pro1[k]=pro1[k+1];count--;
    		flag=0; 
    	} 

    	if(count==limit2-1) 
      		count=0; 
    	else 
    		count++; 
    }
    printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
    printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);   
}
