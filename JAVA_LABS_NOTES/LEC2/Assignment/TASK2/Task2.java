




abstract class Shape
{
private int dim1;
    public Shape()
    {

    }

    public Shape(int dm)
    {

    dim1=dm;

    }


    public void Setdim1(int dm1)
    {

    dim1=dm1;
    }

    public int Getdim1()
    {

    return dim1;

    }


public abstract double CalcArea();

public static double CalcSum(Shape S1 , Shape S2 , Shape S3)
{


return S1.CalcArea()+S2.CalcArea()+S3.CalcArea();


}
}





class Circle extends Shape
{
public int dim2;

public Circle()
{

dim2=Getdim1()/2;

}

public Circle(int dm2)
{


dim2=dm2;

}


public double CalcArea()
{

return (3.14*(dim2/2)*(dim2/2));

}



}




class Rectangle extends Shape
{
public int dim2;

public Rectangle()
{



}

public Rectangle(int dm1 ,int dm2)
{
super(dm1);
dim2=dm2;

}


public double CalcArea()
{

return (super.Getdim1()*dim2);

}



}





class Triangle extends Shape
{
public int dim2;

public Triangle()
{



}

public Triangle(int dm1,int dm2)
{
super(dm1);
dim2=dm2;

}


public double CalcArea()
{

return (0.5*super.Getdim1()*dim2);

}



}
/***********************Main Class*******************/
public class Task2
{

public static void main (String args[])

{


Triangle S1 = new Triangle (5,2);

System.out.println(S1.CalcArea());      

Rectangle S2 = new Rectangle(5,2);

System.out.println(S2.CalcArea());

Circle S3 = new Circle (10); // diameter 
    
System.out.println(S3.CalcArea());

double result=Shape.CalcSum(S1,S2,S3);

System.out.println(result);
}



}
