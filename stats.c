#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int i,j;
    float temp=0.0,temp1=0.0,sum=0.0;
    /* Sorting the given number set */
    for(i=0;i<setlength-1;i++)
    {
        for(j=i+1;j<setlength;j++)
        {
            if(numberset[i]>numberset[j])
            {
                temp=numberset[i];
                temp1=numberset[j];
                numberset[j]=temp;
                numberset[i]=temp1;
            }
         }
    }
    s.min=numberset[0];
    s.max=numberset[setlength-1];
    
    /* Finding Average of the given number set */
    for(i=0;i<setlength;i++)
    {
        sum+=numberset[i];
    }
    s.average=sum/setlength;
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
void emailAlerter()
{
    emailAlertCallCount++;
}
void ledAlerter()
{
    ledAlertCallCount++;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);
{
    int maximum= computedStats.max;
    if(maxThreshold < maximum)
    {
        (*alerters[0])();
        (*alerters[1])();
    }
}  
