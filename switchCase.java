void main(){

    Scanner input = new Scanner(System.in);
    System.out.print("Enter a number (1/7): ");
    int a = input.nextInt();

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
     */
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

}