class RandomizedSet {

    Map<Integer,Integer>map;
    List<Integer>list;
    private Random random;


    public RandomizedSet() {
        map = new HashMap<>();
        list = new ArrayList<>();
        random = new Random();
    }
    
    public boolean insert(int val) {
        if(map.containsKey(val)){
            return false; //value already exists
        }
        list.add(val);
        map.put(val,list.size() - 1);
        return true;
    }
    
    public boolean remove(int val) {
        if(!map.containsKey(val)){
            return false;
        }

        int index = map.get(val);
        int lastElement = list.get(list.size()-1);
        map.put(lastElement,index);
        list.set(index,lastElement);
        list.remove(list.size()-1);
        map.remove(val);

        return true;
    }
    
    public int getRandom() {

        int randomIndex = random.nextInt(list.size());
        return list.get(randomIndex); 
        
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
