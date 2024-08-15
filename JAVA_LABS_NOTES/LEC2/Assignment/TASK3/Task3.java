


class Complex
{
public int real=0;

public int imagine=0;

    public Complex()
    {


    }

    public Complex(int real , int imagine)
    {

        this.real=real;
        this.imagine=imagine;


    }
    public int Getimagine()
    {

        return this.imagine;
    }

    public int Getreal()
    {

        return this.real;       

    }

    public Complex Sum(Complex Obj2)
    {
        Complex temp = new Complex();
        
        temp.imagine=this.imagine+Obj2.Getimagine();

        temp.real=this.real+Obj2.Getreal();
        
        return temp;

     }

    public static  Complex Substraction(Complex Obj1 ,Complex Obj2)
    {
        Complex temp = new Complex();
        
        temp.imagine=(Obj1.Getimagine()-Obj2.Getimagine());
        temp.real=(Obj1.Getreal()-Obj2.Getreal());

        return temp;
     }


}








public class Task3
{

    public static void main (String args [])
    {
        Complex Obj1 =new Complex(5,2);

        Complex Obj2 = new Complex(-2,3);

        Complex Obj3 = Obj1.Substraction(Obj1,Obj2);

        System.out.println(Obj3.Getreal());
        System.out.println(Obj3.Getimagine());

        Complex Obj4 = Obj1.Sum(Obj2);

        System.out.println(Obj4.Getreal());
        System.out.println(Obj4.Getimagine());


    }


}
