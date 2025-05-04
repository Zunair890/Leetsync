class MyHashSet {
private:
    std::vector<int> elements; // Vector to store all elements
    
public:
    MyHashSet() {
        // Constructor doesn't need to do anything
    }
    
    void add(int key) {
        // Check if key already exists
        if (!contains(key)) {
            elements.push_back(key); // Add to end of vector
        }
    }
    
    void remove(int key) {
        // Find the key in vector
        auto it = std::find(elements.begin(), elements.end(), key);
        if (it != elements.end()) {
            elements.erase(it); // Remove the element
        }
    }
    
    bool contains(int key) {
        // Check if key exists in vector
        return std::find(elements.begin(), elements.end(), key) != elements.end();
    }
};