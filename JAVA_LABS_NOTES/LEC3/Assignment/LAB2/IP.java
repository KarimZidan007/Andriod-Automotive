import java.util.StringTokenizer;


public class IP 

{   

        private static void method1(String St1)

        {
             int i=0;
             int Prev_Index=-1;
            while(i != St1.lastIndexOf('.'))
            {
              i=St1.indexOf('.',i+1);

              System.out.println(St1.substring(Prev_Index+1,i));
              Prev_Index=i;
            
            }
        
           
            System.out.println(St1.substring(St1.lastIndexOf('.')+1));
            

          
        }
    public static void main(String[] args)
    {
        if(args.length== 0)
        {
            System.out.println("Invalid Args");

        }
        else
        {
            String St1 = args[0];
            method2(St1);
        }

    }


    

    private static void method2(String St)

    {
        String[] ReadyST = St.split("[.]");

        for(String i : ReadyST)
        {
           System.out.println(i);

        }


    }


    private static void method3(String St)

    {
        StringTokenizer St3 = new StringTokenizer(St,".");
        while(St3.hasMoreTokens())
        {
            System.out.println(St3.nextToken());

        }


    }


}
