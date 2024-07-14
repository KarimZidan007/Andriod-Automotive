class ParkingSystem {
private:
int big_max_size=0;
int medium_max_size=0;
int small_max_size=0;
int big_current_size=0;
int medium_current_size=0;
int small_current_size=0;
public:
    ParkingSystem(int big, int medium, int small) {
        this->big_max_size=big;
        this->medium_max_size=medium;
        this->small_max_size=small;
        
    }
    
    bool addCar(int carType) {
        bool State=false;
        switch(carType)
        {
            case 1 : 
                    if(this->big_max_size>this->big_current_size)
                    {
                        big_current_size++;
                        State=true;
                        break;
                    }
                    else
                    {
                        State=false;
                        break;
                    }
            case 2 :
                    if(this->medium_max_size>this->medium_current_size)
                    {
                        medium_current_size++;
                        State=true;
                        break;
                    }
                    else
                    {
                        State=false;
                        break;
                    }
            case 3 :
                    if(this->small_max_size>this->small_current_size)
                    {
                        small_current_size++;
                        State=true;
                        break;
                    }
                    else
                    {
                        State=false;
                        break;
                    }
             default :  break;
        }
        return State;
    }

};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
