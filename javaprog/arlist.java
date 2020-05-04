import java.util.ArrayList;
import java.util.Collections;
public class arlist{
    public static void main(String[] args) {
        ArrayList<Integer> alist = new ArrayList<Integer>();
        alist.add(5);
        alist.add(6);
        System.out.println(alist);
        ArrayList<String> slist = new ArrayList<String> ();
        slist.add("Steve jobs is apple founder");
        slist.add("I am going to intern at Alphonso");
        slist.add(1 , "I am sparsh sinha");
        System.out.println(slist);
 
        slist.set(1 , "I am Sanchit sinha's brother");
        slist.remove("I am going to intern at Alhonso");
        slist.remove(0);
        System.out.println(slist);
        int i = 0;
        for(String str : slist){
            System.out.println("index = " + i + " value = " + str);
            i++;
        }
        System.out.println("another way");
        for(i = 0; i < (int) slist.size(); i++){
            System.out.println(slist.get(i));
        }
        Collections.sort(slist);
        System.out.println(slist);
    }
}