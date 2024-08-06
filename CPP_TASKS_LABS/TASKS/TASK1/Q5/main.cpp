#include <iostream>
#include <string>

// Define the structure for Name
struct Name {
    std::string firstName;
    std::string middleName;
    std::string lastName;
};

// Define the structure for Date of Birth
struct DateOfBirth {
    int day;
    int month;
    int year;
};

// Define the structure for Address
struct Address {
    std::string street;
    std::string city;
    std::string country;
};

// Define the structure for Contacts
struct Contacts {
    std::string telephoneNumber;
    std::string mobileNumber;
    std::string emailAddress;
};

// Define the structure for Salary
struct Salary {
    double basic;
    double additional;
    double reductions;
    double taxes;
};

// Define the main structure for Employee
struct Employee {
    Name name;
    DateOfBirth dateOfBirth;
    Address address;
    Contacts contacts;
    std::string job;
    Salary salary;
};

int main() {
    // Example of creating an Employee object
    Employee employee;

    // Populating the Employee object with example data
    employee.name.firstName = "John";
    employee.name.middleName = "H.";
    employee.name.lastName = "Doe";
    
    employee.dateOfBirth.day = 15;
    employee.dateOfBirth.month = 6;
    employee.dateOfBirth.year = 1990;
    
    employee.address.street = "123 Main St";
    employee.address.city = "Anytown";
    employee.address.country = "Anycountry";
    
    employee.contacts.telephoneNumber = "123-456-7890";
    employee.contacts.mobileNumber = "098-765-4321";
    employee.contacts.emailAddress = "john.doe@example.com";
    
    employee.job = "Software Engineer";
    
    employee.salary.basic = 50000.0;
    employee.salary.additional = 5000.0;
    employee.salary.reductions = 2000.0;
    employee.salary.taxes = 8000.0;

    // Print the Employee information
    std::cout << "Employee Information:" << std::endl;
    std::cout << "Name: " << employee.name.firstName << " " << employee.name.middleName << " " << employee.name.lastName << std::endl;
    std::cout << "Date of Birth: " << employee.dateOfBirth.day << "/" << employee.dateOfBirth.month << "/" << employee.dateOfBirth.year << std::endl;
    std::cout << "Address: " << employee.address.street << ", " << employee.address.city << ", " << employee.address.country << std::endl;
    std::cout << "Contacts: " << employee.contacts.telephoneNumber << ", " << employee.contacts.mobileNumber << ", " << employee.contacts.emailAddress << std::endl;
    std::cout << "Job: " << employee.job << std::endl;
    std::cout << "Salary: Basic - " << employee.salary.basic << ", Additional - " << employee.salary.additional << ", Reductions - " << employee.salary.reductions << ", Taxes - " << employee.salary.taxes << std::endl;

    return 0;
}

