#pragma once
#ifndef PROJECTREDO_BUNDLE_H
#define PROJECTREDO_BUNDLE_H

#include <string>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

#include "Task.h"

class Bundle {
private:
    static std::unordered_map<std::string, Bundle *> BundleBucket;
    std::string name;
    std::vector<Task> tasks;

public:
    /**
     * Simple bare-bones constructor, rest of configuration of a bundle is done in Init function.
     * @param name Name of this bundle. Can be used to access it later if needed. As well as prefix logs.
     */
    explicit Bundle(std::string name, std::vector<Task> taskList = {});

    ~Bundle();

    void tick();

    static Bundle *Get(const std::string &name);
};


#endif //PROJECTREDO_BUNDLE_H
