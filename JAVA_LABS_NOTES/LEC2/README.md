# Object Oriented Programming

What is Object Prgramming ?
- **Programming paradigm that revolves around the concept of objects and classes (resolve real life into objects).**

- **Objects are instances of classes.**

What is a Class ?
- **A blueprint or template that defines the properties and behavior of an object.**
- **A class is essentially a design or a template that defines the characteristics of an object.**
- **A class is a collection of data members (variables) and member functions (methods) that together define the behavior of an object.** 
- **A class is essentially a blueprint or a template that defines the properties and behavior of an object**

What is Object?
- **An object is an instance of a class.**
- **An object is a real-world entity that has its own set of attributes (data) and behaviors (methods).** 


## What is Java syntax of class

<access -modifier>* class <name>
{
    <attribute declaration>*
    <method declaration>*
    <construcor Decleartion>*    
} 

## Example 

<access -modifier>* class <name>
{
private int  x ;
public void display(){};
} 


- **access modifier** : public, private, protected, default

## OOP CONCEPTS
### 1. Inheritance
- **Inheritance is a mechanism in which one class can inherit the properties and behavior of another class
- **The class that is being inherited is called the parent or superclass and the class that is doing the inheriting is called the child or subclass.** 
- **Inheritance is a way of creating a new class based on an existing class**
### 2. Abstraction
- **Abstraction is the concept of showing only the necessary information to the outside world while hiding the implementation**

### 3.Polymorphism  
- **Polymorphism is the ability of an object to take on multiple forms**

- **Polymorphism is the ability of an object to behave differently in different situations**
### 4. Encapsulation

- **Encapsulation is the concept of bundling data and methods that operate on that data within a single unit** 

- **Data Hiding because i want to validate the input data before access the attributes**

## WHAT IS THE DIFFERENCE BETWEEN Encapsulation and Abstraction

- **Encapsulation is about hiding the internal details of an object from the outside world**

- **Abstraction is about showing only the necessary information to the outside world while hiding the implementation**

-**NOTE :: CHECK CODILITY**


## Naming Conventions of setter and getters

Setter:public void  : Set(Attributename) (datatype of attribute)
Getter: public (datatype of attribute) Get(Attributename) : Get(Attributename)()

## COMPILER IS A LEXICAL ANALYZER

## Constructor 

- constructor is used to initalize **instance member variables**

- Object are always with heap 

Class (ObjName); -> heap 

Class (ObjName) = New (Constructor());

--------------------------------------------------------------------
SerattedDisc disc1; // reference not an obj
disc1 = new SerratedDisc(); -> after allocating call the constructor 

EX

String myName= new String("Ahmed")
--------------------------------------------------------------------

## Instance and Static Members 

## Instance Member 
1. its a describtion of the object , that i could differ between Objects by those Members Values. 
2. it Allocate when i create Obj 
3. Number of it ? Number of Objects if it is an attribute 
one time if it is method 
4. method are allocated only one time so how the method knows which object who call it ? **THIS REFRENCE is implicitly**  (it is a reference to the current instance of the class )
5. i can not access it except with object

**NOTE on setters size=size without this it called shadowing and it is not allowed because of undefined behaviour compiler may took the local size on both sides**
------------------------------------------------------------------------

## Static Member (Class Member)

1. its a describtion of the class 
2. it Allocate when i create the class through class loader 
3. Number of it ? one time
4. i can access it  with class name
5. it is shared between all objects of the class
6. it is used to store data that is common to all objects of the class

------------------------------------------------------------------------
## decompiler (search for it today) -> reverse obj , bytecode to sourcecode again
Obfuscator -> it scrumble or merge code like encryption to make reverse engineer hard as possible
- also make code less space complex as possible
------------------------------------------------------------------------

## inhertance 

- it is to extend functionallity of an exicting class 

- inheritance represents is - a relationship between the Child and its Parent

- What is Generalization ( Buttom to up) -> think about what is commmon between classes first (to make Parent class) 

- What is Specialization (Up to bottom) -> think about every class specialization
------------------------------------------------------------------------
Think about is-a between child and parent 
and hirarchy between Child clasess themselfes
------------------------------------------------------------------------

## to has an inhertiance you have to be common in most of description (generalization) and differ in (Specialization only)


## when i make object of child it has to be create a parent obj first using default constructor by default then build the child obj on it 


## if i want to make child constructor call a paramaterized constructor  we were making it this way on C++ , here i make it the following way :
```c++
{
    class Child
    {
        public Child():Parent(5,10) 
        {
            //for example
        }
    };
}


```java
class Child extends Parent{
    public Child(5,5,5);
    {
        super(5,10); ->constructor redirection

        System.out.println("default Child");

    }
}
```


so if i set Super() in Child Constructor 

Child c = new Child(5,5,5);

// how it called default constructor ?
//implicitly call it as first statment in child constructor 
 // super has to be the first statment 

return super.sum() // (valid) super as reference of current instance of parent 
------------------------------------------------------------------------

## Types of Inheritance
1. Single Inheritance
2. Multiple Inheritance
3. Multilevel Inheritance
4. Hierarchical Inheritance
5. Hybrid Inheritance
6. Multilevel Inheritance
7. Multiple Inheritance


## polymophism 

1. method overloading -> it is the appearnce of methods with same name and different in param list in same class or another inherited class  (different signature)

2. method overriding -> it is the appearnce of methods with same name and same param list  (same signature)

-**specialization happen here on overriding every class implement it is own implementation**
-**applicable on every method and also with constructor overloading
------------------------------------------------------------------------
**EX**
if i made inheritance and overriding for sum at this case 

i want to add x to sum of two inherted classes attributes 
if i remove super here it will call the sum on same context class untill stack over flow
public int sum(int x)
{
    return x +super.sum();
}

**Constructor could call another constuctor on the same class using this**

i could make chain constructor redirection 

if i have three classes 

class C redirect to classB redirect to Class A

------------------------------------------------------------------------
3. refrence from parent ref to obj from child

Parent p = new Child(); //parent method and attributes only


-------------------------------------------------------------------------
## INTERVIEW

Parent p = new Child();
p.setNo1(1);
p.setNo2(2);
p.sum();

// on two levels 
1. compilation will succfully

2. runtime -> dynamic binding or late binding 

so all methods are virtual by default because of dynamic binding 
(virtual does not included as a keyword but all methods are virtual by default)
```java
Parent p = new Child();
p.setNo1(1);
p.setNo2(2);
p.sum();
```
if i dont have my own implementation of setNo1 , setNo2 i will take the parent implementation 

if i have my own implementation of setNo1 , setNo2 i will take the child implementation

p.sum if it is do not implemented on parent and implemented on child 
it will take the child implementation 

## if i have abstrace method on a class , the class has to be abstract on it 

```java
public abstract class (class name)
{
    abstract method ()
    {

    }
}
```
abstract class does  not have an object 

on JAVA :abstract class may has zero or more abstract methods and or /or zero or more concrete methods

child reference can not be equal to parent objs 

