class Solution {
public:
    bool isAnagram(string s, string t) {
        bool state=true;
        std::sort(s.begin() ,s.end());
        std::sort(t.begin(),t.end());

        if(s.length()==t.length())
        {
            for(auto i=0 ; i <s.length() ; i++)
            {
                if(s[i]==t[i])
                {

                }
                else
                {
                    state=false;
                    break;
                }
            }

        }
        else

        {
                    state=false;

        }



      return state;  
    }

};
