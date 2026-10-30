class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> qu;
        qu.push(0);
        visited.insert(0);
        while(!qu.empty()){
            int curr=qu.front();
            qu.pop();
            for(auto neighbour : rooms[curr]){
                if(visited.count(neighbour)==0){
                    // neighbour is not visited 
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
        return (rooms.size() == visited.size());
    }
};