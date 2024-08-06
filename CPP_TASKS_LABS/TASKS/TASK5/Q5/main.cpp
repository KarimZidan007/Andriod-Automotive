class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int Highest_V =0;
        int Sum=0;
        for(auto i : gain)
        {
            Sum+=i;
            Highest_V=max(Highest_V,Sum);
        }
        return Highest_V;
    }
};

//road n+1 =points 
//biker start at 0,0 
//gain[n] 
// where gain[i] is the gain in vertical  ->n> i >=0  
