package ClassAndObject;

public class Student {

    private Integer rollNumber;
    private String name;
    private String faculty;

    public Student () {

    }

    public Student (String name, Integer rollNumber, String faculty) {
        this.name = name;
        this.rollNumber = rollNumber;
        this.faculty = faculty;
    }

    @Override
    public String toString() {
        return "Student details \n" +
                "Name: "+this.name + "\n"+
                "Roll Number: "+this.rollNumber + "\n"+
                "Faculty: "+this.faculty+"\n";
    }
}
