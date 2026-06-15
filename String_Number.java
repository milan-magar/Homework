void main() {

    Scanner scanner = new Scanner(System.in);

    /*
    //Program to compare two strings
    String string1, string2;
    System.out.print("Enter first String: ");
    string1 = scanner.nextLine().toLowerCase();
    System.out.print("Enter second String: ");
    string2 = scanner.nextLine().toLowerCase();

    if(string1.equals(string2)){
        System.out.println("The two strings are equal:");
    }
    else{
        System.out.println("The two strings are not equal:");
    }

    */

    /*
    //Program to find the largest number among three.
    int a, b, c;
    System.out.print("Enter a: ");
    a = scanner.nextInt();
    System.out.print("Enter b: ");
    b = scanner.nextInt();
    System.out.print("Enter c: ");
    c = scanner.nextInt();

    //int largest = (a>b)?((a>c)?a:c):((b>c)?b:c);
    int largest = (Math.max(a,b)==a)?((Math.max(a,c)==a)?a:c):((Math.max(b,c)==b)?b:c);
    System.out.printf("The largest number is %d", largest);

    */

    //Program to find the smallest number among three
    int a, b, c;
    System.out.print("Enter a: ");
    a = scanner.nextInt();
    System.out.print("Enter b: ");
    b = scanner.nextInt();
    System.out.print("Enter c: ");
    c = scanner.nextInt();

    //int smallest = (a<b)?((a<c)?a:c):((b<c)?b:c);
    int smallest = (Math.min(a,b)==a)?((Math.min(a,c)==a)?a:c):((Math.min(b,c)==b)?b:c);
    System.out.printf("The smallest number is %d", smallest);
}
