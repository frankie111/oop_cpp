#include <iostream>
#include <vector>
#include <algorithm>
#include "CRUD_Repository.h"
#include "Client.h"

#define NULL_Client Client(0, "", false);

class ClientInMemoryRepository : public CrudRepository<Client> {
private:
    std::vector<Client> clients;

    static ClientInMemoryRepository *instance;

    ClientInMemoryRepository() = default;

public:
    static ClientInMemoryRepository &getInstance() {
        if (instance == nullptr)
            instance = new ClientInMemoryRepository();

        return *instance;
    }

    Client findOne(int id) {
        for (Client c: clients) {
            if (c.get_id() == id)
                return c;
        }
        return NULL_Client;
    }

    std::vector<Client> findAll() {
        return clients;
    }

    Client save(Client _client) {
        for (Client c: clients) {
            if (c.get_id() == _client.get_id()) {
                c.set_name(_client.get_name());
                c.set_company(_client.get_company());
                return c;
            }
        }
        clients.push_back(_client);
        return NULL_Client;
    }

    Client del(int id) {
        std::vector<Client>::iterator result =
                clients.erase(
                        std::remove_if(clients.begin(), clients.end(), [id](Client c) { return c.get_id() == id; }),
                        clients.end());
        return *result;
    }

    Client update(Client _client) {
        for (Client c: clients) {
            if (c.get_id() == _client.get_id()) {
                c.set_name(_client.get_name());
                c.set_company(_client.get_company());
                return c;
            }
        }
        return NULL_Client;
    }

    ~ClientInMemoryRepository() override {
        delete instance;
    }
};

ClientInMemoryRepository *ClientInMemoryRepository::instance = nullptr;

int main() {
    ClientInMemoryRepository repo = ClientInMemoryRepository::getInstance();

    repo.save(Client(1, "Hans", false));
    repo.save(Client(3, "Mueller und Co.", true));
    repo.save(Client(5, "Andreas", false));
    repo.save(Client(7, "Landhauserhof", true));
}