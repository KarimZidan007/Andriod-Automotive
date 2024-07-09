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


