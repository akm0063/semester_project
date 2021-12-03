#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Swimmer {
	private:
		string name, stroke;
	public:
        Swimmer() {
            name = "no name";
            stroke = "no stroke";
        }
        Swimmer(string nameIn, string strokeIn) {
            name = nameIn;
            stroke = strokeIn;
        }
        void setName(string newName) {
            name = newName;
        }
        void setStroke(int newStroke) {
            stroke = newStroke;
        }
        string getName() {
            return name;
        }
        string getStroke() {
            return stroke;
        }
};
    
void addSwimmer(int &numSwimmers, vector<Swimmer> &swimmers) {      //add new swimmer to array
    string name;
    string stroke;
    
    cout << "\nEnter the new swimmers's name: ";
    cin >> name;
    cout << "Enter the new swimmer's stroke: ";
    cin >> stroke;
    Swimmer newSwimmer(name, stroke);
    swimmers.push_back(newSwimmer);
    cout << "\n" << name << " has been added to the roster.\n";
    numSwimmers++;
}

void updateSwimmer(int &numSwimmers, vector<Swimmer> &swimmers) {     // change swimmer in array
    string oldName, name;
    string stroke;
    
    if (numSwimmers > 0) {
        cout << "\nEnter the swimmers's name you want to update: " << endl;
        cin >> oldName;
        cout << "Enter the swimmers's new name: " << endl;
        cin >> name;
        cout << "Enter the swimmers's new stroke: " << endl;
        cin >> stroke;
        
        for (int i = 0; i < numSwimmers; i++) {
            if (swimmers[i].getName() == oldName) {
                swimmers.erase(swimmers.begin() + i);
                numSwimmers--;
            }
        }

        Swimmer newSwimmer(name, stroke);
        swimmers.push_back(newSwimmer);
        cout << name << " has been added updated.\n";
        numSwimmers++;
    }
    else {
        cout << "\nThe team roster is empty.\n";
    }
}

void printSwimmer(int numSwimmers, vector<Swimmer> swimmers) {      //print out swimmer from array
    string name;
    
    if (numSwimmers > 0) {
        cout << "\nEnter the name of the swimmer you want to view: " << endl;
        cin >> name;
        
        for (int i = 0; i < numSwimmers; i++) {
            if (swimmers[i].getName() == name) {
                cout << swimmers[i].getName() << " " << swimmers[i].getStroke() << endl;
            }
        }
    }
    else {
        cout << "\nThe team roster is empty.\n";
    }
}
        
void printTeam(int numSwimmers, vector<Swimmer> swimmers) {     //print out all swimmers from array

    if (numSwimmers > 0) {
        cout << "\nThe team roster is: " << endl;

        for (int i = 0; i < numSwimmers; i++) {
            cout << swimmers[i].getName() << " " << swimmers[i].getStroke() << endl; 
        }
    }
    else {
        cout << "\nThe team roster is empty.\n";
    }
}

void removeSwimmer(int &numSwimmers, vector<Swimmer> &swimmers) {      //remove swimmer from array
    string name;
    
    if (numSwimmers > 0) {
        cout << "\nEnter the swimmers's name you want to remove: " << endl;
        cin >> name;
        
        for (int i = 0; i < numSwimmers; i++) {
            if (swimmers[i].getName() == name) {
                swimmers.erase(swimmers.begin() + i);
                cout << name << " has been removed from the roster.\n";
                numSwimmers--;
            }
        }
    }
    else {
        cout << "\nThe team roster is empty.\n";
    }
}

void sortByStroke(int numSwimmers, vector<Swimmer> swimmers) {      //a sort function that sorts the array by stroke and prints the sorted array

    if (numSwimmers > 0) {
    
        for (int i = 1; i < numSwimmers; i++) {
            for (int j = 0; j < numSwimmers-1; j++) {
                if (swimmers[j].getStroke() > (swimmers[j+1].getStroke())) {
                    
                    Swimmer temp = swimmers[j];
                    swimmers[j] = swimmers[j+1];
                    swimmers[j+1] = temp;
                }
            }
        }
        
        cout << "\nThe sorted roster by stroke is: " << endl;

        for (int i = 0; i < numSwimmers; i++) {
            cout << swimmers[i].getName() << " " << swimmers[i].getStroke() << endl; 
        }
    }
    else {
        cout << "\nThe team roster is empty.\n";
    }
}

void inputFile(int &numSwimmers, vector<Swimmer> &swimmers) {
    ifstream input;
    string filename, line, name, stroke;

    cout << "\nEnter team file name: " << endl;
    cin >> filename;  
    
    input.open(filename);

    if (input.good()) {
    
        while (getline(input, name, ',')) {
            getline(input, stroke, '\n');
        
            Swimmer newSwimmer(name, stroke);
            swimmers.push_back(newSwimmer);
            numSwimmers++;
        }

        cout << "\nThe roster has been imported." << endl;
    }
    else {
        cout << "\nFile does not exist." << endl;
    }
    input.close();
}


int main() {

    int choice = 0;
    int numSwimmers = 0;
    vector<Swimmer> swimmers;
    
    while (choice != 9) {

        cout << "\nEnter the number for what you would like to do:\n"
        << "1: Add a new swimmer\n"
        << "2: Update a swimmer\n"
        << "3: Remove a swimmer\n" 
        << "4: View a swimmer\n"
        << "5: View current roster\n"
        << "6: View team size\n"
        << "7: View sorted roster by stroke\n" 
        << "8: Import team roster from file\n"
        << "9: Exit\n" << endl;
        cin >> choice;
        
        switch(choice) {
            case 1:
            // add a new swimmer
            addSwimmer(numSwimmers, swimmers);
            break;

            case 2:
            // update a swimmer
            updateSwimmer(numSwimmers, swimmers);
            break;

            case 3:
            // remove a swimmer
            removeSwimmer(numSwimmers, swimmers);
            break;

            case 4:
            // view a swimmer
            printSwimmer(numSwimmers, swimmers);
            break;

            case 5:
            // view current roster
            printTeam(numSwimmers, swimmers);
            break;

            case 6:
            // view team size
            cout << "\nThere are currently " << numSwimmers << " swimmers on the team." << endl;
            break;

            case 7:
            // view sorted roster by stroke
            sortByStroke(numSwimmers, swimmers);
            break;

            case 8:
            // import team roster from file
            inputFile(numSwimmers, swimmers);
            break;

            case 9:
            // exit
            break;

            default:
            cout << "Enter a valid number (1-9).\n";
            break;
        }
    }
    
    return 0;
}