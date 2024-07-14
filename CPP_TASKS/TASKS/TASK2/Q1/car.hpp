
class Car
{
private:
    std::string company;
    std::string model;
    unsigned int year;

public:
    Car()
    {
    }
    Car(std::string company, std::string model, unsigned int year)
    {
        this->company = company;
        this->model = model;
        this->year = year;
    }
    void Set_company(std::string Company)
    {
        company = Company;
    }
    void Set_model(std::string Model)
    {

        model = Model;
    }
    void Set_year(unsigned int Year)
    {
        year = Year;
    }
    std::string get_company(void)
    {
        return this->company;
    }
    std::string get_model(void)
    {
        return this->model;
    }
    unsigned int get_year(void)
    {
        return this->year;
    }

    ~Car()
    {
    }
};
