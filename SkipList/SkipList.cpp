#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <random>
#include <memory>
#include <climits>

const int MAX_LEVEL = 16;
const double P = 0.5;

/**
 * SkipList implementation with probabilistic level assignment.
 * Provides O(log n) average time for search, insert, and delete operations.
 */
class SkipListNode {
public:
    int key;
    std::vector<std::shared_ptr<SkipListNode>> forward;

    SkipListNode(int key, int level) : key(key), forward(level + 1, nullptr) {}
};

class SkipList {
private:
    std::shared_ptr<SkipListNode> header;
    int level;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;

    int randomLevel() {
        int level = 0;
        while (dis(gen) < P && level < MAX_LEVEL) {
            level++;
        }
        return level;
    }

public:
    SkipList() : header(std::make_shared<SkipListNode>(INT_MIN, MAX_LEVEL)),
                 level(0), gen(std::random_device{}()), dis(0.0, 1.0) {}

    /**
     * Search for key in SkipList. O(log n) average time.
     */
    std::shared_ptr<SkipListNode> search(int key) {
        auto current = header;
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->key < key) {
                current = current->forward[i];
            }
        }

        current = current->forward[0];
        if (current && current->key == key) {
            return current;
        }
        return nullptr;
    }

    /**
     * Insert key into SkipList. O(log n) average time.
     */
    void insert(int key) {
        std::vector<std::shared_ptr<SkipListNode>> update(MAX_LEVEL + 1, nullptr);
        auto current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (!current || current->key != key) {
            int newLevel = randomLevel();

            if (newLevel > level) {
                for (int i = level + 1; i <= newLevel; i++) {
                    update[i] = header;
                }
                level = newLevel;
            }

            auto newNode = std::make_shared<SkipListNode>(key, newLevel);

            for (int i = 0; i <= newLevel; i++) {
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }
        }
    }

    /**
     * Delete key from SkipList. O(log n) average time.
     */
    void deleteKey(int key) {
        std::vector<std::shared_ptr<SkipListNode>> update(MAX_LEVEL + 1, nullptr);
        auto current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current && current->key == key) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->forward[i] != current) {
                    break;
                }
                update[i]->forward[i] = current->forward[i];
            }

            while (level > 0 && !header->forward[level]) {
                level--;
            }
        }
    }

    /**
     * Display SkipList structure.
     */
    void display() {
        std::cout << "SkipList structure:" << std::endl;
        for (int level = this->level; level >= 0; level--) {
            auto current = header->forward[level];
            std::cout << "Level " << level << ": ";
            while (current) {
                std::cout << current->key << " -> ";
                current = current->forward[level];
            }
            std::cout << "None" << std::endl;
        }
    }
};

/**
 * Demonstrates SkipList operations with probabilistic balancing.
 * Inserts 10 elements, searches for values, and displays structure.
 */
int main() {
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // Create SkipList instance
    SkipList skipList;
    
    // Insert elements
    std::vector<int> elements = {3, 6, 7, 9, 12, 19, 17, 26, 21, 25};
    for (int elem : elements) {
        skipList.insert(elem);
    }
    
    // Calculate memory usage (approximate)
    size_t memoryUsed = sizeof(SkipList) + (sizeof(SkipListNode) + sizeof(std::shared_ptr<SkipListNode>) * 17) * 10;

    // Display structure
    skipList.display();
    
    // Search operations
    std::vector<int> searchKeys = {19, 15, 21};
    std::cout << "\nSearch results:" << std::endl;
    for (int key : searchKeys) {
        auto result = skipList.search(key);
        std::cout << "Search for " << key << ": " << (result ? "Found" : "Not found") << std::endl;
    }
    
    // Delete operation
    skipList.deleteKey(17);
    std::cout << "\nAfter deleting 17:" << std::endl;
    skipList.display();
    
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    
    // Performance statistics
    std::cout << "\n--- Performance Statistics ---" << std::endl;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Execution time: " << duration.count() / 1000.0 << " ms" << std::endl;
    std::cout << "Memory usage: " << memoryUsed << " bytes" << std::endl;
    std::cout << "\nTime Complexity (Average):" << std::endl;
    std::cout << "  - Search: O(log n)" << std::endl;
    std::cout << "  - Insert: O(log n)" << std::endl;
    std::cout << "  - Delete: O(log n)" << std::endl;
    std::cout << "  - Space: O(n)" << std::endl;

    return 0;
}