package package_one.subpackage_one;
public class oneton{
    int n;
    public oneton(int n){
        this.n = n;
    }
    public void start(){
        System.out.println("starting oneton class writer");
        for(int i = 1; i <= n; ++i){
            System.out.println(i);
        }
        System.out.println("finished oneton class writer");
    }
}