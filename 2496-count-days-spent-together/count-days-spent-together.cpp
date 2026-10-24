class Solution {
private:
    vector<int> dayIn={31,28,31,30,31,30,31,31,30,31,30,31};
    int daystoyear(string& data){
        int month=stoi(data.substr(0,2));
        int days=stoi(data.substr(3,2));

        int totaldays=days;
        for(int i=0;i<month-1;i++){
            totaldays+=dayIn[i];
        }
        return totaldays;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startAlice=daystoyear(arriveAlice);
        int endAlice=daystoyear(leaveAlice);
        int startbob=daystoyear(arriveBob);
        int endbob=daystoyear(leaveBob);

        int overlapStart=max(startAlice,startbob);
        int overlapend=min(endAlice,endbob);;

        if(overlapStart<=overlapend){
            return overlapend-overlapStart+1;
        }
        return 0;
    }
};