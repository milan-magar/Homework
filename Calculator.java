void main(){

    Scanner scan = new Scanner(System.in);
    int num1, num2, option;
    char choice1, choice2;
    boolean resume1 = true, resume2 = true;

    do {

        //User enters two numbers
        System.out.print("Enter first number: ");
        num1 = scan.nextInt();
        System.out.print("Enter second number: ");
        num2 = scan.nextInt();

        do{

            //User chooses from the menu
            System.out.println("Choose from MENU!!!: ");
            System.out.println("*-----------------------------------*");
            System.out.println("* 1. Addition        2. Subtraction *");
            System.out.println("* 3. Multiplication  4. Division    *");
            System.out.println("*-----------------------------------*");

            System.out.print("Enter your choice: ");
            option = scan.nextInt();

            switch (option) {
                case 1 -> {int sum = num1 + num2;
                    System.out.println("Sum: "+ sum);
                }
                case 2 -> {int difference = num1 - num2;
                    System.out.println("Difference is: "+difference);
                }
                case 3 -> {int product = num1 * num2;
                    System.out.println("Product is: "+product);
                }
                case 4 -> {int quotient, remainder;
                    float answer;
                    if (num2 == 0){
                        System.out.println("Undefined");
                    } else {
                        quotient = num1 / num2;
                        remainder = num1 % num2;
                        answer = (float)num1 / num2;
                        System.out.println("Quotient: "+quotient);
                        System.out.println("Remainder: "+remainder);
                        System.out.printf("Simple Answer is %.3f\n",answer);
                    }

                }
                default -> System.out.println("Invalid Choice");
            }
            System.out.print("DO YOU WANT TO CONTINUE WITH PREVIOUS INPUTS: (y/n): ");
            choice1 = scan.next().toLowerCase().charAt(0);
            if (choice1 == 'n') {
                resume1 = false;
            }
        } while (resume1);

        System.out.print("DO YOU WANT TO CONTINUE WITH NEW INPUTS (y/n)");
        choice2 = scan.next().toLowerCase().charAt(0);
        if (choice2 == 'n') {
            resume2 = false;
        }

    } while (resume2);

}