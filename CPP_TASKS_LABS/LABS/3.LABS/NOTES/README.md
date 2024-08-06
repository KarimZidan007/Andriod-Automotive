#CPP LECTURE 3


#namespaces

What is that -> Scoped Region in memory i could write on it variables , functions , objects 

```c++
    
namespace Karem
{

void f()
{
cout<<"Karem";

}

}
main()
{

Karem::f();
//access the namespace that contain f function
}

```
what if i create name space without a name  ?

- it would be like a normal global function to the global but it is use case like static function on C i can not access it outside the file 

## unamed 
1. Unnamed Namespace: In C++, you can use an unnamed namespace to restrict the visibility of variables and functions to the translation unit (source file). For example:

```c++
namespace {
    int x; // x is only visible within this translation unit
    void foo() {
        // ...
    }
}

```
## type Alias 

```c++
using int = uint32; -> modern way
```

## alias for namespace

```c++
namespace NEWNAME = OLD NAMESPACE NAME
```
- to reduce the name or take a specific name space recursived into a new name


## initialization 
1. copy init -> int x=5; 
2. direct init -> int  x(5) 
3. int list (uniform)init ->int z{7,2} -> will stop implicit conversions - this example will generate error 
4. aggregate or value -> used with structs {1,2}

## uninitializated var int x {};
## cpp insights and compiler explorer into assembly instruction
 
## unranged for

```c++
int arr {1,2,3,4,5};
for(int val : arr) //arr =init-list
{
std::cout<<val;
}

```
## Dynamic Allocation
comparision between new and malloc
![comp](comp.png)

1. new  (it is an operator not a function)

```c++
int *p = new int {5};
## to initialize it 

int * arr = new[5]{values}
##double ptr

int ** dptr= new int*[size]{values}

##obj allocated it into heap 

MyClass * hossam =new MyClass();

## if i used malloc it will not call the constructor of the obj 

```
2. delete
there is keywork called nullptr
int *ptr =nullptr;
delete ptr; 

if i tried to delete ptr one more time it will generate error
##static cast
int x=*static_cast<int*>(*void)

#Linkage and scope 
1. nolinkage like local variable (linker does not include to allocate)
2. internal linkage (static private variable which can not be used outside file)
3. external linkage anything simply does not internal linkage


## auto 
    i could use it with unranged for loop
    auto detect the datatype
 ican not use it with reference and const 

##decltype
decltype(x) y{456}; -> same as int y{456};

```c++
cout<< typeid(y).name; -> i stands for integer
```


##pair

data structures

1. first
2. second
it contain two elements

```c++

std::pair x {1,2.2};

std::pair<int,double>x {1,2.2};

both are same
```

## structured binding 

auto [x,y,z] { values };

i could fill variables by struct values or direct values
```c++
{
int arr[]{1,2,3,4};

auto [x,y,z,g] {arr}


}

