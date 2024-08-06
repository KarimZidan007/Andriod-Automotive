#Pair ->data structure

 
template<typename T , typename T2>
struct Pair{
T first;
T2 Second;
}
it is how pairs look like 
2. i could make Pair and his members are Pairs also or struct

```c++
std::pair<struct,int> p ={{1,2},5};

```

#struct 

1. same as class except the access specifiers by default in struct are public and on class are private
2. aggregate initialization Employee Ahmed{"huawei',2020,28} does not supported if i used constructors or class features because there is no default constructor take 3 -> if i made a copy constructor with 3 by my self it will work  
3. i can not use . operator because it is not struct any more

#enum

1. normal enum -> unscoped
2. enum class -> scoped enum
```c++
enum class e {


first, 
sec,
third
} 

e var1=second

if(var1==1) -> it will generate compile error

if(var1==e::second) -> it will compile 
```
- if i want to save enum value on integer i have to static_cast 

```c++

int myInt{(static_cast<int>(ocean)} -> valid

```
    
##array 

it is a templete class that already implemented before 

```c++
std::array<int,4> Array_One;
```

## String 

```c++
std::string myvar = "NAME";
myvar="Karem" -> Valid 

//in c it was by strcpy or forloop

myvar+="Karem" -> valid 

```
## function overloading

Function overloading in C++ allows you to define multiple functions with the same name but different parameter lists. The correct function is chosen by the compiler based on the number and type of arguments passed. Here is a simple example to demonstrate function overloading:
```c++
#include <iostream>

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Function to add two doubles
double add(double a, double b) {
    return a + b;
}

// Function to concatenate two strings
std::string add(const std::string& a, const std::string& b) {
    return a + b;
}

int main() {
    // Using the function to add two integers
    int sum1 = add(5, 10);
    std::cout << "Sum of 5 and 10 is: " << sum1 << std::endl;

    // Using the function to add three integers
    int sum2 = add(5, 10, 15);
    std::cout << "Sum of 5, 10, and 15 is: " << sum2 << std::endl;

    // Using the function to add two doubles
    double sum3 = add(5.5, 10.5);
    std::cout << "Sum of 5.5 and 10.5 is: " << sum3 << std::endl;

    // Using the function to concatenate two strings
    std::string result = add(std::string("Hello, "), std::string("World!"));
    std::cout << "Concatenation of 'Hello, ' and 'World!' is: " << result << std::endl;

    return 0;
}

```
## template 
if i have template template<typename T , typename T> 
and when Instantiation i pass int and string -> compiler error because of different passed data type with the instantiation

## how to delete default constructor or make compiler does not implement it 
class myClass
{
myClass()=delete;
}

## so on with templete
1.  
```c++

#include <iostream>
#include <string>


template <typename T, typename U> 
auto sum(const T  var1,const U  var2) {
    return var1 + var2;
}

// function templete Specialization
template <> 
auto sum<std::string,std::string>(const std::string a, const std::string b) =delete;

int main()

{


sum<int,int>(2,5);

 return 0;   
}
```
2. this one will not work 

```c++


#include <iostream>
#include <string>


template <typename T, typename U> 
auto sum(const T  var1,const U  var2) {
    return var1 + var2;
}

// function templete Specialization
template <> 
auto sum<std::string,std::string>(const std::string a, const std::string b) =delete;

int main()

{


sum<std::string, std::string>(2,5);

 return 0;   
}

```

## name Mangling

during function overloading compiler has a process called name Mangling to resolve the same function into assembly wise 
also on meta-programming

## Debug symbols
