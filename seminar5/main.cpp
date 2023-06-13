#include <iostream>
#include <vector>

using namespace std;

int main() {

}


class Customer {
};

class CustomerRepository {
    CustomerRepository();

    virtual void create(Customer customer) = 0;

    virtual vector<Customer> findAll() const = 0;

    virtual void update(Customer customer) = 0;

    virtual void remove(Customer customer) = 0;

    virtual ~CustomerRepository() = 0;

};

template<class T>
class CrudRepository {
    CrudRepository();

    virtual void create(const T &obj) = 0;

    virtual vector<T> findAll() const = 0;

    virtual void update(int id, const T &obj) = 0;

    virtual void remove(const T &obj) = 0;

    virtual ~CrudRepository() = 0;
};

template<class T>
class InMemoryRepository : public CrudRepository<T> {
private:
    vector<T> list;
public:
    InMemoryRepository() {}

    void create(const T &obj) override{
        list.push_back(obj);
    }

    vector<T> findAll() const override{
        return list;
    }

    void update(int id, const T &obj) override{
        auto it = std::find_if(list.begin(), list.end(), [&](const T &obj) {
            return obj.getId() == id;
        });

        *it = obj;

    }

    void remove(const T &obj) override{
        auto it = std::find(list.begin(), list.end(), obj);
        if (it != list.end())
            list.erase(it);
    }

    ~InMemoryRepository() = default;
};