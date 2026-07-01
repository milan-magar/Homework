package ClassAndObject;
import java.util.Scanner;

public class StudentMain {
    static void main () {

        Scanner scan = new Scanner(System.in);

        Student std = new Student("Milan", 11, "BCA");

        System.out.println(std.toString());

        Student std2 = new Student("Ram", 15, "Bsc. CSIT");

        System.out.println(std2.toString());
    }
}
