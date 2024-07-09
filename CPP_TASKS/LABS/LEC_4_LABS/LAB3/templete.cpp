
#include <iostream>
#include <string>


template <typename Key, typename Value> 
class KeyValuePair
{
private:
Key Key_At;
Value Value_At;
public:
    KeyValuePair():Key_At{0},Value_At{0}
    {


    }


    KeyValuePair(Key init_key , Value init_value)
    {

        Key_At=init_key;
        Value_At=init_value;
    } 

    Key Get_Key(void)
    {
        return Key_At;
    }

    Value Get_Value(void)
    {
        return Value_At;
    }

    void Set_Key(Key init_key)
    {

        Key_At=init_key;

    }

    void Set_Value(Value init_value)
    {

        Value_At=init_value;
    }
    
    ~KeyValuePair()
    {


    }
};

int main()

{
KeyValuePair<std::string,int> Pair_T("apple",5);
std::string x =static_cast<std::string>(Pair_T.Get_Key());
std::cout<<x<<std::endl;
 return 0;   
}
