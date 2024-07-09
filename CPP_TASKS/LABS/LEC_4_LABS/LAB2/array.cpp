#include <iostream>
#include <array>

  

template<typename T,typename T2>
class Pair
{
private:
T First;
T2 Second;
public:

Pair():First{0},Second{0}
{

}

Pair(T var1 , T2 var2)
{
    First=var1;
    Second=var2;
}
T getFirst()
{
    return First;
}
T2 getSecond()
{
    return Second;
}
void SetFirst(T var)
{
    First=var;
}
void SetSecond(T2 var)
{
    Second=var;
}
void SetPairs(T var1 , T2 var2)
{
        First=var1;
        Second=var2;
}


void SwapPairs(void)
{
T temp = First;
First=T(Second);
Second=T2(temp);
}





void Print(void)
{

    std::cout<<"First element is :"<<First<<"Second element is :"<<Second<<std::endl;   
}

~Pair()
{

}
};
int main()
{

Pair<int,float>Pair_T{1,2.2};
Pair_T.Print();
Pair_T.SetFirst(1);
Pair_T.SetSecond(2);
Pair_T.Print();
std::cout<<"First is "<<Pair_T.getFirst()<<std::endl;

std::cout<<"Second is "<<Pair_T.getSecond()<<std::endl;
Pair_T.SwapPairs();
Pair_T.Print();




return 0;
}
