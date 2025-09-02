
/*
Minimum number of platforms required for a railway 
Greedy Medium

Here in this i am sorting the arrival adn the departure times parallely, so i just process the arrival times, because if the arrival is less than
departure, then we need a new platform simultaneously and  if the arirval is grerater than the current departure of a train then we dont need a new platform.

Why this works?

Solution : Because wqe are sorting the arrivals nd departure times, so when suppose i trains are processed and if we need i number of platforms, and then for the i+1 th train arrival is less than the current departure, then it means that the one of the previously processed i trains are leaving, so we dont need a new platform. Becuase it is not possible that a not processed future coming train is departing art the current departure time, so that departure has to be one of the i trains. 
*/

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int platform_cnt = 1, platform_required = 1;
        int i = 1, j = 0;
        int n = arr.size();
        while(i < n and j < n){
            if(arr[i] <= dep[j]){  // New platform is needed
                platform_cnt++;
                i++;
            }else{
                j++; i++;
            }
            platform_required = max(platform_required, platform_cnt);
        }
        return platform_required;
    }
};
