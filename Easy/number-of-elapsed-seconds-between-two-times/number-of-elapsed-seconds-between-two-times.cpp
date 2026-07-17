class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int nos=0;
        string h=startTime.substr(0,2);
        int h1=stoi(h);
        h=endTime.substr(0,2);
        int h2=stoi(h);

        nos+=(h2-h1)*60*60;

         h=startTime.substr(3,2);
        int m1=stoi(h);
         h=endTime.substr(3,2);
        int m2=stoi(h);

        nos+=(m2-m1)*60;

        h=startTime.substr(6,2);
        int s1=stoi(h);
        h=endTime.substr(6,2);
        int s2=stoi(h);

        nos+=s2-s1;

        return nos;

        
    }
};