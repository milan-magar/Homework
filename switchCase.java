
void main(){

    Scanner scan = new Scanner(System.in);
    //System.out.print("Enter a number (1/7): ");

    /*
    switch (a) {
        case 1:
            System.out.println("Sunday");
            break;
        case 2:
            System.out.println("Monday");
            break;
        case 3:
            System.out.println("Tuesday");
            break;
        case 4:
            System.out.println("Wednesday");
            break;
        case 5:
            System.out.println("Thursday");
            break;
        case 6:
            System.out.println("Friday");
            break;
        case 7:
            System.out.println("Saturday");
            break;
        default:
            System.out.println("Invalid");
            break;
    }

    String dayName;
    dayName = switch (a) {
        case 1 -> "Sunday";
        case 2 -> "Monday";
        case 3 -> "Tuesday";
        case 4 -> "Wednesday";
        case 5 -> "Thursday";
        case 6 -> "Friday";
        default -> "Invalid Choice";
    };

    System.out.println("The day is "+ dayName);
     */
    System.out.print("Enter first number: ");
    int a = scan.nextInt();
    System.out.print("Enter second number: ");
    int b = scan.nextInt();

    System.out.println("Select a choice from Menu: ");
    System.out.println("***********************************************");
    System.out.println("1: Addition");
    System.out.println("2: Subtraction");
    System.out.println("3: Multiplication");
    System.out.println("4: Division");
    System.out.println("***********************************************");
    System.out.print("Enter your choice: ");
    int choice = scan.nextInt();

    switch (choice) {
        case 1 -> {int sum = a+b;
                    System.out.println("Sum: "+ sum);
                    }
        case 2 -> {int difference = a-b;
                    System.out.println("Difference is: "+difference);
                    }
        case 3 -> {int product = a*b;
            System.out.println("Product is: "+product);
        }
        case 4 -> {int quotient = 1, remainder = 1;
                float answer;
            if (b==0){
                System.out.println("Undefined");
            } else {
                quotient = a/b;
                remainder = a%b;
                answer = (float)a/b;
                System.out.println("Quotient: "+quotient);
                System.out.println("Remainder: "+remainder);
                System.out.printf("Simple Answer is %.3f",answer);
            }

        }
        default -> System.out.println("Invalid Choice");
    }


}