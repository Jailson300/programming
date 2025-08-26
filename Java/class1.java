class student{
    String name;
    int RollNum;
    String Course;

    student() {
      name = "";
      RollNum = 0;
      Course = "";
    }

    student (String n, int r, String c){
        name = n;
        RollNum = r;
        Course = c;
    }

    void display(){
        System.out.println("/n");
        System.out.println("Name :" + name);
        System.out.println("Roll no: "+ RollNum);
        System.out.println("Course: " + Course);
    }
}

public class class1 {
    public static void main (String args []){
      student s = new student("Boinao",2107,"Bca");
      s.display();
    }
}