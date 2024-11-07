
package utils;

import java.util.ArrayList;

/**
 *
 * @author Kerlly Chiriboga - ODS
 */
public interface DataManagement {
    String DATABASE = "main";
    int ID = 0;
    public void create(String collection, String data);
    public void update(String collection, String oldData, String newData);
    public ArrayList<String> read(String collection);
    public void delete(String collection, String searchKey, String searchValue);
}
