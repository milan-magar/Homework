void main(){
    double Headphone = 399.99;
    double Printer = 599.99;
    double Laptop = 999.99;
    boolean promoAcceptance = false;
    double price;

    Scanner p = new Scanner(System.in);
    System.out.print("Enter Product Name: ");
    String productName = p.nextLine();
    System.out.print("Enter Quantity: ");
    int quantity = p.nextInt();
    System.out.print("Do you have any promo code (y/n): ");
    char promo = p.next().charAt(0);
    p.nextLine();
    if (promo == 'y'){
        System.out.print("Enter promo code: ");
        String promoCode = p.nextLine();
        if (promoCode.equals( "CODE124")){
            System.out.println("Success!!");
            promoAcceptance = true;
        }else{
            System.out.println("Invalid Promo Code!!! ");
            promoAcceptance = false;
        }
    }


    if(promoAcceptance){
        if (productName.equals("Headphone") || productName.equals("headphone")){
            price = (Headphone - (0.15) * Headphone) * quantity;
        } else if (productName.equals("Printer") || productName.equals("printer")) {
            price = (Printer - (0.1) * Printer) * quantity;
        } else if (productName.equals("Laptop") || productName.equals("laptop")) {
            price = (Laptop - (0.2) * Laptop) * quantity;
        } else{
            price = 0;
        }
    } else {
        if (productName.equals("Headphone") || productName.equals("headphone")){
            price = Headphone * quantity;
        } else if (productName.equals("Printer") || productName.equals("printer")) {
            price = Printer * quantity;
        } else if (productName.equals("Laptop") || productName.equals("laptop")) {
            price = Laptop * quantity;
        } else{
            price = 0;
        }
    }
    System.out.println("\nHere is your Receipt: ");
    System.out.println("Product Name: "+productName);
    System.out.println("Quantity: "+quantity);
    System.out.println("Price: $"+price);
}