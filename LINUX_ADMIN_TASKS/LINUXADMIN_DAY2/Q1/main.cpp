#include <iostream>


int Binary_Search (int * Arr , int element,int length)
{

int Start=0;
int End=length-1;
int Middle;

while(Start<=End)
{
 Middle=(Start+(End-Start)/2);
if(element>Arr[Middle])
{
	Start=Middle++;
    std::cout<<Start;
}
else if(element<Arr[Middle])
{
	End=Middle--;
    std::cout<<End;
}
else if(element==Arr[Middle])
{
	break;
}


}
return Middle;
}


int main()
{
 int Arr[5]{6,7,8,9,10};
unsigned int index=0;
index=Binary_Search(Arr,10,5);


return 0;
}
