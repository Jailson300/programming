class Person {
    String name = "Boinao";
    int age = 23;
    void Display() {
        System.out.println("");
        System.out.println("Name : " + name);
        System.out.println("Age : " + age);
    }   
}

class Student extends Person{
    int RollNo= 2107;
    int marks = 87;
    void Display(){
        super.Display();
        System.out.println("Roll no :  " + RollNo);
        System.out.println("Mark :  " + marks);
    }
}

public class sinInheritance {
    public static void main(String[] args) {
        Student s =  new Student();
        s.Display();
    }
}
