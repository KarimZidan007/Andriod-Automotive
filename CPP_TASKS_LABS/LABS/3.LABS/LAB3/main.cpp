#include <iostream>

namespace ArrayPair
{

std::pair<int ,int> * create_array(unsigned int size)
{
    std::pair<int ,int> * x = new std::pair<int , int >[size];

return x;
}

void delete_array (std::pair<int,int> * arr)
{
    delete[] arr;
}

void Set_Pair (std::pair<int,int> * arr , unsigned int index,std::pair<int,int> val )
{

arr[index].first=val.first;
arr[index].second=val.second;

}
void get_Pair (std::pair<int,int> * arr , unsigned int index,std::pair<int,int> *val )
{

val->first=arr[index].first;
val->second=arr[index].second;

}

void Print_Array(std::pair<int,int> * arr , unsigned int size)
{
    for (int i =0 ; i < size ; i ++)
    {
        std::cout<<"index : "<<i<<" First : "<<arr[i].first<<" Second"<<arr[i].second<<std::endl;
    }
}


}

int main()
{

 std::pair<int ,int> temp {1,2};   
std::pair<int ,int> * array_of_pairs;    
array_of_pairs=ArrayPair::create_array(5);
ArrayPair::Set_Pair(array_of_pairs,0,temp);
ArrayPair::Print_Array(array_of_pairs,1);
ArrayPair::get_Pair(array_of_pairs,0,&temp);

std::cout<<temp.first<<"  "<<temp.second<<std::endl;

ArrayPair::delete_array(array_of_pairs);



return 0;
}