#include<stdio.h>
int main()
{
  int time,smallest,i;
  int bt[10],at[10],rt[10],sum_bt,n;
  
  int sum_turnaround=0,sum_wait=0;
  int rtmin, atmin, count;
  printf("Enter no of processes : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter arrival time for process P%d : ",i+1);
    scanf("%d",&at[i]);
    printf("Enter burst time for process P%d : ",i+1);
    scanf("%d",&bt[i]);
    rt[i]=bt[i];
    sum_bt+=bt[i];
  }
  printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
  for(time=0;time<sum_bt;)
  {
  	rtmin = 9999;
    for(i=0;i<n;i++)
    {
      if(at[i]<=time && rt[i]<rtmin && rt[i]>0){
      	rtmin = rt[i];
      	atmin = at[i];
	  }
    }
    if(rtmin == 9999){
		time++;
      	continue;
	}else{
		for(i=0;i<n;i++){
			if(rt[i] == rtmin && at[i] == atmin){
				rt[i]--;
				time++;
				if(rt[i] == 0){
					sum_wait+=time-at[i]-bt[i];
    				sum_turnaround+=time-at[i];
					printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
				}
			}
		}
	}
  }
	printf("\n average waiting time = %f",sum_wait*1.0/n);
  	printf("\n average turnaround time = %f\n",sum_turnaround*1.0/n);
  return 0;
}
