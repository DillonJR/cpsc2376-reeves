# Board Game Café Lending System Design

## 1. Program Specification

This program is a lightweight inventory and lending tracker for a board game café. 
It allows users to view available games, check out games to customers, and log their return. 
It tracks game titles, available copies, who borrowed them, and due dates.

Entities include games, customers, and lending records.

## 2. Nouns and Verbs

### Nouns
- Game
- Customer
- LendingRecord
- Title
- Copies
- Due date

### Verbs
- Add game
- Check out
- Return
- List games
- List borrowed games

## 3. Class Design

```cpp
class Game {
public:
    Game(std::string title, int totalCopies);
    std::string getTitle() const;
    int getAvailableCopies() const;
    void borrowCopy();
    void returnCopy();

private:
    std::string title;
    int totalCopies;
    int borrowedCopies;
};


class Customer {
public:
    Customer(std::string name);
    std::string getName() const;

private:
    std::string name;
};


class LendingRecord {
public:
    LendingRecord(Customer customer, Game& game, std::string dueDate);
    std::string getDueDate() const;
    std::string getGameTitle() const;
    std::string getCustomerName() const;

private:
    Customer customer;
    Game* game;
    std::string dueDate;
};

class GameLendingSystem {
public:
    void addGame(const std::string& title, int copies);
    void listGames() const;
    void checkOutGame(const std::string& gameTitle, const std::string& customerName, const std::string& dueDate);
    void returnGame(const std::string& gameTitle, const std::string& customerName);
    void listBorrowedGames() const;

private:
    std::vector<Game> games;
    std::vector<Customer> customers;
    std::vector<LendingRecord> lendingRecords;
};

classDiagram
    class Game {
        - string title
        - int totalCopies
        - int borrowedCopies
        + Game(string, int)
        + string getTitle()
        + int getAvailableCopies()
        + void borrowCopy()
        + void returnCopy()
    }

    class Customer {
        - string name
        + Customer(string)
        + string getName()
    }

    class LendingRecord {
        - Customer customer
        - Game* game
        - string dueDate
        + LendingRecord(Customer, Game&, string)
        + string getDueDate()
        + string getGameTitle()
        + string getCustomerName()
    }

    class GameLendingSystem {
        - vector~Game~ games
        - vector~Customer~ customers
        - vector~LendingRecord~ lendingRecords
        + void addGame(string, int)
        + void listGames()
        + void checkOutGame(string, string, string)
        + void returnGame(string, string)
        + void listBorrowedGames()
    }

    GameLendingSystem --> Game
    GameLendingSystem --> Customer
    GameLendingSystem --> LendingRecord
    LendingRecord --> Customer
    LendingRecord --> Game
