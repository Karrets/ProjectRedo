#include "Bundle.h"

#include <utility>

std::unordered_map<std::string, Bundle *> Bundle::BundleBucket;

Bundle::Bundle(std::string name, std::vector<Task> taskList) : tasks{std::move(taskList)} {
    this->name = std::move(name);

    BundleBucket.emplace(this->name, this);
}

Bundle::~Bundle() {
    BundleBucket.erase(name);
}

void Bundle::tick() {
    for (auto &task: tasks) {
        task.loop();
    }
}

Bundle *Bundle::Get(const std::string &name) {
    return BundleBucket[name];
}