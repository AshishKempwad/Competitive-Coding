class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int,int>mp;

    RandomizedSet() {
    
    }

    /*1)Check if element is already present. If it is present then we cannot insert. Return false
      2)Insert the element into vector.
      3)Insert that element into map, where the index would be current vector.size()-1
      4)Then return true;
      */
    bool insert(int val) {
        if(mp.find(val) != mp.end()){
            return false;
        }
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    /*1)Check if the element is present. If it is not present then we cannot remove it, hence return false
    2)Get the index of the element we wish to remove
    3)Inorder to remove it in O(1) time we need to send that lement to the last.
    4)We swap the element to be removed to last index and the element 
    present at last index to the index where the element to be removed was present.
    5)Then using vector.pop_back(), we remove that element from the vector.
    6)And using mp.erase we remove the element from the map*/
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }

        int idx = mp[val];
        int lastElement = v.back();
        v.back() = val;

        v[idx] = lastElement;
        mp[lastElement] =idx;
        mp.erase(val);
        v.pop_back();

        return true;
    }
    

    int getRandom() {
        int n = v.size();
        int randomIndex = rand() % n; //It return (0,1,2...n-1) randomly
        return v[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
