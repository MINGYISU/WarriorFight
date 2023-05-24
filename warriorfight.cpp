#include <iostream>
#include <string>
#include <ctime>

class warrior{
    std::string m_name{"Ironman"};
    int m_x{0}, m_y{0}, m_HP{100};

public:

    void display() {
        // display the warrior's information
        std::cout << "\nWarrior: ";
        std::cout << "Location: (" << m_x << "," << m_y <<")";
        std::cout << "  HP: " << m_HP;
    }

    void move() {
        // warrior decides to move
        int new_x,new_y;
        std::cout << "Enter the location you want to go: ";
        std::cin >> new_x >> new_y;
        m_x = new_x;
        m_y = new_y;
        std::cout << "-You moved to (" << m_x << "," << m_y << ");";
    }

    int attack() {
        // return a random number between 1 and 10
        int att;
        srand(time(NULL));
        att = (rand() % 10) + 1;
        return att;
    }

    void healthUp() {
        //Warrior's HP is increased by 3 points
        m_HP += 3;
        //HP cannot exceed 100
        if(m_HP > 100) {
            m_HP = 100;
        }
        std::cout << "\n-Health Up: Your HP+3;";
    }

    void healthDown(int down) {
        //HP decreases
        m_HP -= down;
        std::cout << "\n\n-Monster Attacked You: Your HP-" << down << ";";
    }

    int returnX() {
        return m_x;
    }

    int returnY() {
        return m_y;
    }

    int returnHP() {
        return m_HP;
    }
};

class monster{
    int n_x{0}, n_y{0}, n_HP{100};

public:

    int attack() {
        int att;
        att=(rand()%10)+1;
        return att;
    }

    void healthDown(int down) {
        n_HP -= down;
        std::cout << "\n-You Attacked Monster: Monster's HP-" << down << ";";
    }

    void move(int a,int b) {
        //move to the warrior's location
        n_x = a;
        n_y = b;
        std::cout << "\n-Monster moved to (" << n_x << "," << n_y << ");";
    }

    void display()
    {
        //display monster's information
        std::cout << "\nMonster: ";
        std::cout << "Location: (" << n_x << "," << n_y << ")";
        std::cout << "  HP: " << n_HP;
    }

    int returnX() {
        return n_x;
    }

    int returnY() {
        return n_y;
    }

    int returnHP() {
        return n_HP;
    }
};

int main()
{
    warrior war;
    monster mon;
    while (1) {
        if (war.returnHP() <= 0 || mon.returnHP() <= 0) {
            break;
        }

        //warrior's turn
        int q;
        std::cout << "*Your turn: " << "\n1->Move or 2->Attack? ";
        std::cin >> q;
        if(q == 1) {
            war.move();
            war.display();
        } else if(q == 2) {
            mon.healthDown(war.attack());
            mon.display();
            if(mon.returnHP() <= 0) {
                break;
            }
        } else {
            std::cout << "\nYou skipped your turn!";
        }

        //monster's turn
        std::cout << "\n\n*Monster's turn: ";
        if(war.returnX() == mon.returnX() && war.returnY() == mon.returnY()) {
            war.healthDown(mon.attack());
        } else {
            mon.move(war.returnX(),war.returnY());
            mon.display();
        }

        //Warrior's health up
        war.healthUp();
        war.display();
        std::cout << std::endl << std::endl;
    }

    if(war.returnHP() <= 0) {
        std::cout<<"\tGame Over! You Lost!";
    } else if(mon.returnHP()<=0) {
        std::cout << "\n\n\tYou Win!!!";
    }
}
