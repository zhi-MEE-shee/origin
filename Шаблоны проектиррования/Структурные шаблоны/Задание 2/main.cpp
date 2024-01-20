#include <map>
#include <string>
#include <iostream>

class VeryHeavyDatabase {
public:
    std::string GetData(const std::string& key) const noexcept {
        return "value";
    }
};

class CacheProxyDB : VeryHeavyDatabase {
public:
    explicit CacheProxyDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}
    std::string GetData(const std::string& key) noexcept {
        if (cache_.find(key) == cache_.end()) {
            std::cout << "Get from real object\n";
            cache_[key] = real_db_->GetData(key);
        }
        else {
            std::cout << "Get from cache\n";
        }
        return cache_.at(key);
    }

private:
    std::map<std::string, std::string> cache_;
    VeryHeavyDatabase* real_db_;
};


//class CacheProxyDB : VeryHeavyDatabase {
//public:
//    explicit CacheProxyDB(std::unique_ptr<VeryHeavyDatabase> ptr) : real_db_(std::move(real_object)) {}
//    std::string GetData(const std::string& key) noexcept {
//        if (cache_.find(key) == cache_.end()) {
//            std::cout << "Get from real object\n";
//            cache_[key] = real_db_->GetData(key);
//        }
//        else {
//            std::cout << "Get from cache\n";
//        }
//        return cache_.at(key);
//    }
//
//private:
//    std::map<std::string, std::string> cache_;
//    std::unique_ptr<VeryHeavyDatabase> real_db_;
//};
//
//VeryHeavyDatabase* initCachedDatabase() {
//    auto* originalDbPtr = std::make_unique<VeryHeavyDatabase>();
//    return std::make_unique<CacheProxyDb>(std::move(originalDbPtr))
//}


class TestDB : VeryHeavyDatabase {
public:
    explicit TestDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}
    std::string GetData(const std::string& key) noexcept {
        return "test_data\n";
    }
private:
    VeryHeavyDatabase* real_db_;
};

class OneShotDB : VeryHeavyDatabase {
public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots) : real_db_(real_object), shots_(shots) {}
    std::string GetData(const std::string& key) noexcept {
        if (shots_ != 0) {
            --shots_;
           return real_db_->GetData(key);
        }
        else {
            std::cout << "error\n";
        }
        return {};
    }

private:
    size_t shots_;
    VeryHeavyDatabase* real_db_;
};


int main() {
    auto real_db = VeryHeavyDatabase();
    auto limit_db = OneShotDB(std::addressof(real_db), 2);
    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;

    return 0;
}