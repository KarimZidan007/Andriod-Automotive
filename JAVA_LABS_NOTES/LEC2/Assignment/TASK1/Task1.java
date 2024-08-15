




class Parent {
    private int No1;
    private int No2;
    public Parent()
    {
    }
    public Parent(int N1 , int N2)
    {
    
	No1=N1;
	No2=N2;
	
    }
    public void SetNo1(int N1)
    {
	this.No1=N1;
    }
    public void SetNo2(int N2)
    {
	this.No2=N2;
	
    }
    public int GetNo1()
    {
	    return No1;
    }
    public int GetNo2()
    {
	return No2;
    }
    public int Sum()
    {
	    return No1+No2;
    }


}

 class Child extends Parent
{
    private int No3;
   
    public Child()
    {
    
    }
    public Child(int N1 , int N2,int N3 )
    {
        super(N1,N2);
    
        No3=N3;
	
    }
    public void SetNo3(int N3)
    {
	No3=N3;
    }

    public int GetNo3()
    {
	    return No3;
    }


    public int Sum()
    {
	    return No3+super.Sum();
    }




}

public class Task1
{
    public static void main (String args[])
    {
        Child OBJ1 = new Child(5,3,2);
         int result=OBJ1.Sum();
        System.out.println(result);    }
}
