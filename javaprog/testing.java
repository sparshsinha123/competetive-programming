import package_one.*;
import package_one.subpackage_one.*;
import package_two.classtwo;
public class testing{
    testing(){
        System.out.println("This is testing class");
    }
    public static void main(String[] args) {
        System.out.println("We are testing the import of packages");
        classone c1 = new classone();
        c1.functionone();
        classtwo c2 = new classtwo();
        c2.functiontwo();
        subpackageclass c = new subpackageclass();
        c.disp();
        oneton x = new oneton(10);
        x.start();
    }
}