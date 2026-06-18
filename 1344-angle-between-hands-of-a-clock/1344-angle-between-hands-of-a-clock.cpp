class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mins = minutes, hrmins = 60.0, hrs = hour;
        double fracthrs = minutes/hrmins;
        double hrdeg = 360/12;
        double mindeg = 360/60;
        double hrstick = (hrdeg*hrs)+(hrdeg*fracthrs);
        double minstick = (mindeg*mins);
        double totdeg = abs(minstick-hrstick);
        if(totdeg > 180) totdeg = 360-totdeg;
        return totdeg;
    }
};