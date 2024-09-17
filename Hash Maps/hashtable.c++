#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <functional>

template<typename KeyType, typename ValueType>
class HashTable {
public:
    HashTable(size_t size = 101) : table(size) {}

    void insert(const KeyType& key, const ValueType& value) {
        size_t index = hashFunction(key) % table.size();
        auto& bucket = table[index];
        for (auto& pair : bucket) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        bucket.emplace_back(key, value);
    }

    bool find(const KeyType& key, ValueType& value) const {
        size_t index = hashFunction(key) % table.size();
        const auto& bucket = table[index];
        for (const auto& pair : bucket) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    bool remove(const KeyType& key) {
        size_t index = hashFunction(key) % table.size();
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return true;
            }
        }
        return false;
    }

    void display() const {
        for (const auto& bucket : table) {
            for (const auto& pair : bucket) {
                std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
            }
        }
    }

private:
    std::vector<std::list<std::pair<KeyType, ValueType>>> table;

    std::hash<KeyType> hashFunction;
};

int main() {
    HashTable<std::string, int> hashTable;

    hashTable.insert("apple", 1);
    hashTable.insert("banana", 2);
    hashTable.insert("orange", 3);

    std::cout << "Hash Table contents:" << std::endl;
    hashTable.display();

    int value;
    if (hashTable.find("banana", value)) {
        std::cout << "Found value for 'banana': " << value << std::endl;
    } else {
        std::cout << "Key 'banana' not found." << std::endl;
    }

    if (hashTable.remove("orange")) {
        std::cout << "'orange' removed successfully." << std::endl;
    } else {
        std::cout << "'orange' not found in hash table." << std::endl;
    }

    std::cout << "Hash Table contents after removal:" << std::endl;
    hashTable.display();

    return 0;
}
