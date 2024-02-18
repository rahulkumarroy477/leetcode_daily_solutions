class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        sort(begin(meetings),end(meetings));
        
        vector<long long> lastEndingTime(n,0);
        vector<int> roomUsedCount(n,0);
        
        for(auto meeting:meetings){
            int start = meeting[0];
            int end   = meeting[1];
            int duration = end - start;
            
            int earlyEndRoom = 0;
            long long earlyEndTime = LLONG_MAX;
            bool isRoomFree = false;
            for(int room = 0;room<n;room++){
                if(lastEndingTime[room]<=start){        // got free room
                    roomUsedCount[room]++;
                    lastEndingTime[room] = end;
                    isRoomFree = true;
                    break;
                }
                // room nhi mila
                
                if(earlyEndTime>lastEndingTime[room]){
                    earlyEndTime = lastEndingTime[room];
                    earlyEndRoom = room;
                }
            }
            
            if(!isRoomFree){
                roomUsedCount[earlyEndRoom]++;
                lastEndingTime[earlyEndRoom] += duration;
            }
        }
        
        int resultRoom = -1;
        int freq = 0;
        
        for(int room = 0;room<n;room++){
            if(roomUsedCount[room]>freq){
                resultRoom = room;
                freq = roomUsedCount[room];
            }
        }
        
        return resultRoom;
    }
};