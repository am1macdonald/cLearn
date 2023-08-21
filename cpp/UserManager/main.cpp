#include <iostream>
#include <exception>

using namespace std;

struct User {
    string username;
    string password;
};

class Prompter {
public:
    static string getUserName() {
        string tmp{};
        cout << "Please enter a username: \n";
        cin >> tmp;
        return tmp;
    }

    static string getPassword() {
        string tmp{};
        cout << "Please enter a password: \n";
        cin >> tmp;
        return tmp;
    }

    static int loginPrompt() {
        int choice{};
        cout << "Choose an option\n";
        cout << "1 - Login\n";
        cout << "2 - Sign Up\n";
        cout << "3 - User Directory\n";
        cout << "4 - Current user\n";
        cout << "5 - Logout\n";
        cin >> choice;
        cin.clear();
        cin.ignore();
        return choice;
    }
};

struct RegistrySlot {
    User user;
    struct RegistrySlot *next{};
};

class UserRegistry {
private:
    RegistrySlot *head;
public:
    UserRegistry() {
        head = nullptr;
    }

    void add(User user) {
        User move1 = std::move(user);
        auto *node = new RegistrySlot();
        struct RegistrySlot *last = head;
        if (head == nullptr) {
            head = new RegistrySlot;
            head->user = move1;
        } else {
            while (last->next != nullptr) {
                last = last->next;
            }
            node->user = move1;
            node->next = nullptr;
            last->next = node;
        }
        cout << "new user: " << head->user.username << endl;
        displayUsers();
   };

    void displayUsers() {
        cout << "Registered Users: \n";
        struct RegistrySlot *last = head;
        while (last != nullptr) {
            cout << last->user.username << endl;
            last = last->next;
        }
    }

    User *getUser(const string& str) {
        struct RegistrySlot *last = head;
        while (last != nullptr) {
            if (last->user.username == str) {
                return &last->user;
            }
            last = last->next;
        }
        throw invalid_argument("User not found");
    };

    void registerUser() {
        User user{};
        user.username = Prompter::getUserName();
        user.password = Prompter::getPassword();
        this->add(user);
        cout << "You have registered successfully!\n" << endl;
    }

    User *signIn() {
        string username = Prompter::getUserName();
        string password = Prompter::getPassword();
        User *user;
        try {
            user = getUser(username);
        } catch (const invalid_argument &msg) {
            cout << msg.what() << endl;
            return nullptr;
        }
        if (user->password == password) {
            cout << "You have signed in successfully!\n" << endl;
            return user;
        } else {
            cout << "Incorrect password\n";
            return nullptr;
        }
    }


};

int main() {
    UserRegistry registry;
    User *currentUser{};
    int choice;
    while (true) {
        do {
            choice = Prompter::loginPrompt();
        } while (choice == 0);
        switch (choice) {
            case 1:
                if (currentUser) {
                    cout << "Already logged in as " << currentUser->username << endl;
                    break;
                } else {
                    cout << "Logging in\n";
                    currentUser = registry.signIn();
                }
                break;
            case 2:
                registry.registerUser();
                break;
            case 3:
                registry.displayUsers();
                break;
            case 4:
                if (currentUser) {
                    cout << "current user: " << currentUser->username << endl;
                } else {
                    cout << "No current user\n";
                }
                break;
            case 5:
                if (currentUser) {
                    cout << "Logging out " << currentUser->username << endl;
                } else {
                    cout << "No current user\n";
                }
                currentUser = nullptr;
                break;
            default:
                cout << "unknown error\n";
        }
    }
}
