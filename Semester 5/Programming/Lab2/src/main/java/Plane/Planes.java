package Plane;

import java.util.Collections;
import java.util.List;

/**
 * Created by chastis
 */
public class Planes {
    private List<Plane> list;

    public Planes(List<Plane> planes) {
        list = planes;
    }


    public void sort() {
        Collections.sort(list);
    }

    @Override
    public String toString() {
        String string = "";
        for (Plane pl : list) {
            string += pl;
        }
        return string;
    }

    public List<Plane> getList(){
        return list;
    }

}
