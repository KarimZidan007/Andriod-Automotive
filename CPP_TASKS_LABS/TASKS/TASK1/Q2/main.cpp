#include <iostream>

using namespace std;

int main()
{
unsigned int Seconds=0;
cin>>Seconds;
cout<<"H:M:S - "<<Seconds/3600<<":"<<(Seconds%3600)/60<<":"<<((Seconds%3600)%60)<<endl;

return 0;
}
