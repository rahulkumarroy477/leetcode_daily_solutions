class Solution {
public:
    typedef pair<long long,int> P;
    
    int mostBooked(int n, vector<vector<int>>& meetings) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(begin(meetings),end(meetings));
        
//         vector<long long> lastEndingTime(n,0);
        vector<int> roomUsedCount(n,0);
        
//         for(auto meeting:meetings){
//             int start = meeting[0];
//             int end   = meeting[1];
//             int duration = end - start;
            
//             int earlyEndRoom = 0;
//             long long earlyEndTime = LLONG_MAX;
//             bool isRoomFree = false;
//             for(int room = 0;room<n;room++){
//                 if(lastEndingTime[room]<=start){        // got free room
//                     roomUsedCount[room]++;
//                     lastEndingTime[room] = end;
//                     isRoomFree = true;
//                     break;
//                 }
//                 // room nhi mila
                
//                 if(earlyEndTime>lastEndingTime[room]){
//                     earlyEndTime = lastEndingTime[room];
//                     earlyEndRoom = room;
//                 }
//             }
            
//             if(!isRoomFree){
//                 roomUsedCount[earlyEndRoom]++;
//                 lastEndingTime[earlyEndRoom] += duration;
//             }
//         }
        
//         int resultRoom = -1;
//         int freq = 0;
        
//         for(int room = 0;room<n;room++){
//             if(roomUsedCount[room]>freq){
//                 resultRoom = room;
//                 freq = roomUsedCount[room];
//             }
//         }
        
//         return resultRoom;
        
        priority_queue<P,vector<P>,greater<P>> usedRooms;
        
        priority_queue<int,vector<int>,greater<int>> availableRooms;
        
        // initially all rooms are free
        for(int room = 0;room<n;room++) availableRooms.push(room);
        
        for(auto meet:meetings){
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;
            
            while(!usedRooms.empty() && usedRooms.top().first<=start){
                int room = usedRooms.top().second;
                usedRooms.pop();
                
                availableRooms.push(room);
            }
            if(!availableRooms.empty()){
                int room = availableRooms.top();
                availableRooms.pop();
                roomUsedCount[room]++;
                usedRooms.push({end,room});
            }
            else{
                //  no room available pick earliest
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                
                usedRooms.push({endTime+duration,room});
                roomUsedCount[room]++;
                
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