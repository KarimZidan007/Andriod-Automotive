#include <iostream>
using namespace std;
double POP_NUM=900000;
float growth_per_year=6.5/100;
unsigned int CALC_YEARS(double POP_NUM ,float growth_per_year);

int main()
{

double years=CALC_YEARS(POP_NUM,growth_per_year);
cout<<years;
return 0;
}


unsigned int CALC_YEARS(double POP_NUM ,float growth_per_year)
{
static double years=0;
double GROWTH_N=POP_NUM*growth_per_year;
POP_NUM+=GROWTH_N;
years++;
if(POP_NUM<1000000)
{
return CALC_YEARS(POP_NUM,growth_per_year);
}
else
{
return years;
}

}
