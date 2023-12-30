#include <stdio.h>
struct time
{
    int hour; 
    int minute; 
    int second; 
};
struct time add(struct time t1, struct time t2)
{
    struct time t3; 
    int carry = 0; 
    t3.second = t1.second + t2.second; 
    if (t3.second >= 60) 
    {
        t3.second -= 60; 
        carry = 1; 
    }
    t3.minute = t1.minute + t2.minute + carry; 
    carry =1;
    if (t3.minute >= 60) 
    {
        t3.minute -= 60; 
        carry = 1; 
    }
    t3.hour = t1.hour + t2.hour + carry; 
    return t3; 
}
int main()
{
    struct time t1, t2, t3; 
    printf("Enter the first time (hour, minute and second): ");
    scanf("%d %d %d", &t1.hour, &t1.minute, &t1.second); 
    printf("Enter the second time (hour, minute and second): ");
    scanf("%d %d %d", &t2.hour, &t2.minute, &t2.second); 
    t3 = add(t1, t2); 
    printf("The sum of the two time is: %02d:%02d:%02d\n", t3.hour, t3.minute, t3.second); 
    return 0; 
}
