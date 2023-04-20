import java.util.Hashtable;
import java.util.Enumeration;

public class HashTable {
    public static void main(String[] args) {

        /* *************************** Hashtable Class ********************************

        The Hashtable class implements a hash table, which maps keys to values.
        Any non-null object can be used as key or as values. However, the Hashtable
        class has since been considered obsolete and its use is generally discouraged.
        This is because it was designed prior to the introduction of the Collections
        framework and does not implement the map interface which makes it difficult to
        use in conjunction with other parts of the framework. In addition, the Hashtable
        class is synchronized which can result in slower performance compared to other
        implementation of the map interface. In general, it’s recommended to use the Map
        interface or one of its implementations (such as HashMap or ConcurrentHashMap)
        instead of the Hashtable class.

            - GeekForGeeks
                                                                         */
        // Define Hashtable
        Hashtable<String, Integer> hashtable = new Hashtable<>();

        // Add elements to the hash table
        hashtable.put("Apple", 556);
        hashtable.put("Orange", 952);
        hashtable.put("Grape", 552);
        hashtable.put("Mango", 289);

        // Getting values from the hashtable
        String key = "N/A";
        int value = hashtable.get("Grape");
        System.out.println("The value of " + key);
    }
}
