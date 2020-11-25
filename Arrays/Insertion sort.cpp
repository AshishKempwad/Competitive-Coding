void insertionSort(std::vector<int> &list)
{
    // Iterate through the list
    for (unsigned int i = 1; i < list.size(); i++) {
        int elem = list[i];
        int j    = i - 1;

        // Compare elem with the elements before it, and swap if necessary. 
        // Swapping is done by repeatedly moving the elements one unit back.
        while (j >= 0 and list[j] > elem) {
            list[j + 1] = list[j]; 
            j--;
        }
        list[j + 1] = elem;
    }
}
