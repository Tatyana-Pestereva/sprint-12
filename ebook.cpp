#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

// using namespace std;
using namespace std::literals;

class EBook {

const int MAX_PAGE = 1000000;
const int MAX_READER = 1000;

public:    
    EBook()
        : num_pages_(MAX_PAGE, 0)
        , count_readers_(MAX_READER, 0)
    {}
    
    double Cheer(int user) {
        if (num_pages_[user] == 0) {
            return 0;
        }
        if (count_readers_[1] == 1) {
            return 1;
        }
        return (count_readers_[1] - count_readers_[num_pages_[user]]) * 1.0 / (count_readers_[1] - 1);
    }

    void Read(int user, int page) {
        int last_page = num_pages_[user];
        for (int i = last_page + 1; i <= page; i++) {
            count_readers_[i]++;
        }
        num_pages_[user] = page;
    }

private:
    std::vector<int> num_pages_;         // номер страницы, до которой дочитал пользователь
    std::vector<int> count_readers_;     // кол-во читателей, дочитавших до данной страницы
};

int main() {
    EBook reading;

    int count = 0;
    std::cin >> count;

    for (int i = 0; i < count; i++) {
        std::string command;
        int user = 0;

        std::cin >> command;
        std::cin >> user;

        if (command == "CHEER"s) {
            std::cout << std::setprecision(6) << reading.Cheer(user) << std::endl; 
        } else if (command == "READ"s) {
            int page = 0;
            std::cin >> page;
            
            reading.Read(user, page);
        }
    }
}