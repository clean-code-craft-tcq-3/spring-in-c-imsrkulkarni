#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int i;
    float sum=0.0,maximum,minimum;
    
    if(setlength>0)
    {
        /* maximum in the given number set */
        maximum=numberset[0];
        for(i=1;i<setlength;i++)
        {
            if(numberset[i]>maximum)
            {
                maximum=numberset[i];
            }
         }
         /* minimum in the given number set */
        minimum=numberset[0];
        for(i=1;i<setlength;i++)
        {
            if(numberset[i]<minimum)
            {
                minimum=numberset[i];
            }
        }
        s.min=minimum;
        s.max=maximum;
    
        /* Finding Average of the given number set */
        for(i=0;i<setlength;i++)
        {
            sum+=numberset[i];
         }
        s.average=sum/setlength;
    }
    else
    {
        s.min=NaN;
        s.max=NaN;
        s.average=NaN;
    }    
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

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    int maximum= computedStats.max;
    if(maxThreshold < maximum)
    {
        (*alerters[0])();
        (*alerters[1])();
    }
}  
