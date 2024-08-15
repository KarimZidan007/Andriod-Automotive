public class Calc
{
    public static void main(String[] args)
    {
        if(args.length != 3)
        {
            System.out.println("Invalid Args");

        }
        else
        {
               
            int operand1= Integer.parseInt(args[0]);
            int operand2= Integer.parseInt(args[2]);
            switch(args[1])
            {
                case "+":  System.out.println("Sum of " + operand1 + " + " + operand2 + " = " + (operand1 + operand2)); break;
                case "-": System.out.println("Substitution of " + operand1 + " - "+ operand2 + " = " + (operand1-operand2)); break;
                case "x": System.out.println("Multiplication of " + operand1 + " x " + operand2 + " = " + (operand1*operand2)); break;
                case "/": System.out.println("Division of " + operand1 + " / " + operand2 + " = " + ((float)operand1/operand2)); break;
                default:break;

            }
        }
    }

}
