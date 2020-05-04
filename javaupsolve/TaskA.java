import java.util.*;
public class TaskA{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n , x0 , y0;
        n  = sc.nextInt();
        x0 = sc.nextInt();
        y0 = sc.nextInt();
        ArrayList<Point> v = new ArrayList<Point> ();
        for(int i = 0; i < n; i++){
            int x , y;
            x = sc.nextInt();
            y = sc.nextInt();
            Point p = new Point(x , y);
            v.add(p);
        }

        HashMap <Point , Boolean> h = new HashMap<Point, Boolean>();
        int ans = 0;
        for(int i = 0; i < n; i++){
            Point foo = v.get(i);
            if(h.containsKey(foo)) continue;
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                Point bar = v.get(j);
                if( !h.containsKey(bar) && ((bar.y - y0) * (foo.x - x0) == (foo.y - y0) * (bar.x - x0)) ){
                    h.put(bar , true); 
                }
            }
            ++ans;
        }
        System.out.println(ans);
    }
}
class Point{
    int x;
    int y;
    Point(int x , int y){
        this.x = x;
        this.y = y;
    }
}