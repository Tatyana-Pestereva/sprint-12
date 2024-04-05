#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class BookReadingStimul {
public:    
    BookReadingStimul()
        : num_pages_(1000000, 0)
        , count_readers_(1000, 0)
    {}
    
    double GetPercentFewerPages(int user) {
        if (num_pages_[user] == 0) {
            return 0;
        }
        if (count_readers_[1] == 1) {
            return 1;
        }
        return (count_readers_[1] - count_readers_[num_pages_[user]]) * 1.0 / (count_readers_[1] - 1);
    }

    void SavePageReading(int user, int page) {
        int last_page = num_pages_[user];
        for (int i = last_page + 1; i <= page; i++) {
            count_readers_[i]++;
        }
        num_pages_[user] = page;
    }


private:
    vector<int> num_pages_;         // номер страницы, до которой дочитал пользователь
    vector<int> count_readers_;     // кол-во читателей, дочитавших до данной страницы
};



int main() {
    BookReadingStimul reading;

    int count = 0;
    int user = 0;
    
    string command;

    cin >> count;

    for (int i = 0; i < count; i++) {
        cin >> command;
        cin >> user;

        if (command == "CHEER"s) {
            cout << setprecision(6) << reading.GetPercentFewerPages(user) << endl; 
        } else if (command == "READ"s) {
            int page = 0;
            cin >> page;
            
            reading.SavePageReading(user, page);
        }
    }

}