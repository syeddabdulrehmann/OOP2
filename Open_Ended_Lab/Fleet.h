#ifndef FLEET_H
#define FLEET_H
#include <vector>
#include <memory>

template <typename T>
class Fleet {
private:
    std::vector<std::shared_ptr<T>> items;

public:
    // Adds a vehicle to the fleet
    void add(std::shared_ptr<T> item) {
        items.push_back(item);
    }

    // Returns all vehicles
    std::vector<std::shared_ptr<T>> getAll() const {
        return items;
    }

    // Returns only available vehicles
    std::vector<std::shared_ptr<T>> getAvailable() const {
        std::vector<std::shared_ptr<T>> result;
        for (const auto& item : items) {
            if (item->isAvailable()) {
                result.push_back(item);
            }
        }
        return result;
    }

    // Returns count of available vehicles
    int availableCount() const {
        int count = 0;
        for (const auto& item : items) {
            if (item->isAvailable()) count++;
        }
        return count;
    }

    // Returns count of rented vehicles
    int rentedCount() const {
        return static_cast<int>(items.size()) - availableCount();
    }
};

#endif
