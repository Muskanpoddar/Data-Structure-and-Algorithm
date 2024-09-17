
#include <iostream>
#include <list>
#include <utility>
#include <algorithm>

template<typename KeyType, typename ValueType>
struct KeyValuePair {
    KeyType key;
    ValueType value;

    KeyValuePair(KeyType k, ValueType v) : key(k), value(v) {}
};

template<typename KeyType, typename ValueType>
class SimpleMap {
public:
    void insert(const KeyType& key, const ValueType& value) {
        auto it = std::find_if(data.begin(), data.end(),
            [&key](const KeyValuePair<KeyType, ValueType>& pair) { return pair.key == key; });

        if (it != data.end()) {
            it->value = value;
        } else {
            data.emplace_back(key, value);
        }
    }

    bool find(const KeyType& key, ValueType& value) const {
        auto it = std::find_if(data.begin(), data.end(),
            [&key](const KeyValuePair<KeyType, ValueType>& pair) { return pair.key == key; });

        if (it != data.end()) {
            value = it->value;
            return true;
        }
        return false;
    }

    bool remove(const KeyType& key) {
        auto it = std::find_if(data.begin(), data.end(),
            [&key](const KeyValuePair<KeyType, ValueType>& pair) { return pair.key == key; });

        if (it != data.end()) {
            data.erase(it);
            return true;
        }
        return false;
    }

    void display() const {
        for (const auto& pair : data) {
            std::cout << "Key: " << pair.key << ", Value: " << pair.value << std::endl;
        }
    }

private:
    std::list<KeyValuePair<KeyType, ValueType>> data;
};

int main() {
    SimpleMap<std::string, int> map;

    map.insert("apple", 1);
    map.insert("banana", 2);
    map.insert("orange", 3);

    std::cout << "Map contents:" << std::endl;
    map.display();

    int value;
    if (map.find("banana", value)) {
        std::cout << "Found value for 'banana': " << value << std::endl;
    } else {
        std::cout << "Key 'banana' not found." << std::endl;
    }

    if (map.remove("orange")) {
        std::cout << "'orange' removed successfully." << std::endl;
    } else {
        std::cout << "'orange' not found in map." << std::endl;
    }

    std::cout << "Map contents after removal:" << std::endl;
    map.display();

    return 0;
}