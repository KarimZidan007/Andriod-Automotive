public class pattern {

    public static void main(String args[]) {
        if (args.length != 1) {

            System.out.println("Invalid Please Enter the row_base number of the pattern");

        } else {
            int base = Integer.parseInt(args[0]);
            System.out.println("You have Entered Base Number :" + base);
            int Starts_numb;
            int flag = 0;
            int row = 0;
            Starts_numb = (row * 2) + 2;
            for (int x = 0; row < base; x++) {

                if (x <= row) {
                    System.out.print("*");
                    Starts_numb--;
                }
                if ((row < x) && (x < ((base * 2) + 1 - row))) {

                    System.out.print(" ");
                }

                if (((base * 2) + 1) - row <= x) {
                    if (flag == 0 && Starts_numb != 0) {
                        System.out.print("*");
                        Starts_numb--;
                        flag = 1;
                    } else {
                        System.out.print(" ");
                        if (Starts_numb != 0) {
                            flag = 0;
                        } else {
                            flag = 1;
                        }
                    }
                }

                if (Starts_numb == 0) {
                    System.out.println("");
                    ++row;
                    flag = 0;
                    Starts_numb = (row * 2) + 2;
                    x = -1;
                }
            }

        }

    }

};

/*
   

  

    


*/
