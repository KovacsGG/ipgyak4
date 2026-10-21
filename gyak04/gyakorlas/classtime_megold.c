/*
Fejleszd tovább a múlt heti programot, hogy ne a felhasználótól kérje az aktuális időt, hanem a rendszertől!
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    time_t now = time(NULL);
    struct tm * now_date = localtime(&now);
    printf("Time: %i:%02i\n", now_date->tm_hour, now_date->tm_min);

    struct tm start_date = *now_date;
    start_date.tm_hour = 8;
    start_date.tm_min = 30;
    start_date.tm_sec = 0;
    time_t start = mktime(&start_date);
    
    printf("Class is shorter by: ");
    int d;
    scanf("%i", &d);

    time_t actualDuration = now - start;
    int supposedDuration = (3 * 45 - d) * 60;
    int delta = (actualDuration - supposedDuration) / 60; // Ennyivel rövidebb a kövi

    printf("Next class is %i minutes %s!\n",
        abs(delta), delta < 0 ? "longer" : "shorter");

}