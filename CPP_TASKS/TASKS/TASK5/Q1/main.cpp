#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours{0}, minutes{0}, seconds{0}
    {
    }
    Time(int H, int M, int S) : hours{H}, minutes{M}, seconds{S}
    {
    }
    void Time_Display(void) const
    {
        std::cout << hours % 12 << ":" << minutes % 60 << ":" << seconds % 60 << std::endl;
    }
    void ADD(const Time &Obj1, const Time &Obj2)
    {
        this->hours = Obj1.hours + Obj2.hours;
        this->minutes = Obj1.minutes + Obj2.minutes;
        this->seconds = Obj1.seconds + Obj2.seconds;
    }
};

int main()
{

    Time Obj_ONE;
    const Time Obj_TWO(4, 30, 30);
    const Time Obj_THREE(2, 20, 20);
    Obj_ONE.ADD(Obj_TWO, Obj_THREE);
    Obj_ONE.Time_Display();

    return 0;
}