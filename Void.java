void main(){
  /*  Scanner scanner = new Scanner(System.in);
    System.out.print("Enter your name: ");
    String fullName = scanner.nextLine();
    System.out.println("Name: "+fullName);
*/
    Scanner s = new Scanner(System.in);
    System.out.print("Enter your first name: ");
    String firstName = s.nextLine();
    System.out.print("Enter your last name: ");
    String lastName = s.nextLine();
    System.out.print("Enter your roll no: ");
    int roll = s.nextInt();
    System.out.print("Enter your Marks: ");
    float marks = s.nextFloat();

    System.out.println("\nName: "+firstName+" "+lastName);
    System.out.println("Roll No: "+roll);
    System.out.println("Marks: "+marks);




    /*
    for(int i = 1; i<=5; i++){
        for(int j=1; j<=i; j++){
            if (j<i){
                System.out.print(j+"\t");
            }
            else{
                System.out.println(j);
            }
        }
    }
    */
}