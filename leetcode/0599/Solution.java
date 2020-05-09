import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> map = new HashMap<>((int)(list1.length / 0.75 + 1));
        for(int i = 0; i < list1.length; i ++){
            map.put(list1[i], i);
        }
        List<String> result = new ArrayList<>();
        int min = list1.length + list2.length;
        for(int i = 0; i < list2.length; i++){
            Integer index = map.get(list2[i]);
            if(index != null){
                if (index + i == min){
                    result.add(list2[i]);
                }else if(index + i < min){
                    min = index + i;
                    result.clear();
                    result.add(list2[i]);
                }
            }
        }
        String[] array = new String[result.size()];
        int i = 0;
        for(String str: result){
            array[i] = str;
            i++;
        }
        return array;
    }
}
