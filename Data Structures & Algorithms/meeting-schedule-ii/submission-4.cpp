/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
         return a.start < b.start;
        });

        vector<int> days;
        days.push_back(intervals[0].end);

        for(int i=1;i<intervals.size();i++){
            int isb=0;
            for(int j=0;j<days.size();j++){
                if(days[j]<=intervals[i].start){
                    days[j]=intervals[i].end;
                    isb=1;
                    break;
                }
            }
            if(!isb){
                days.push_back(intervals[i].end);
            } 
        }

        return days.size();
    }
};
