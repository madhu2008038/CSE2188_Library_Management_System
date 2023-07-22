#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Book {
public:
    string title;
    string author;
    string genre;
    bool available;

    Book(string title, string author, string genre)
        : title(title), author(author), genre(genre), available(true) {}
};


void addBook(vector<Book>& library) {
    string title, author, genre;
    cout << "Enter Book Title: ";

    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter Genre: ";
    getline(cin, genre);

    library.push_back(Book(title, author, genre));
    cout << "Book added successfully!\n";
}


void displayBooks(const vector<Book>& library) {
    cout << "Available Books:\n";
    for (const Book& book : library) {
        if (book.available) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", Genre: " << book.genre << "\n";
        }
    }
}


void saveLibraryData(const vector<Book>& library) {
    ofstream outFile("library_data.txt");
    if (outFile.is_open()) {
        for (const Book& book : library) {
            outFile << book.title << "\n" << book.author << "\n" << book.genre << "\n";
        }
        outFile.close();
        cout << "Library data saved successfully!\n";
    } else {
        cout << "Error: Unable to save library data.\n";
    }
}


void loadLibraryData(vector<Book>& library) {
    ifstream inFile("library_data.txt");
    if (inFile.is_open()) {
        string title, author, genre;
        while (getline(inFile, title) && getline(inFile, author) && getline(inFile, genre)) {
            library.push_back(Book(title, author, genre));
        }
        inFile.close();
        cout << "Library data loaded successfully!\n";
    } else {
        cout << "No existing library data found.\n";
    }
}


void searchBook(const vector<Book>& library) {
    string searchName;
    cout << "Enter the book or writer's name to search: ";
    getline(cin.ignore(), searchName);

    bool found = false;
    cout << "Search Results:\n";
    for (const Book& book : library) {
        if (book.title.find(searchName) != string::npos || book.author.find(searchName) != string::npos) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", Genre: " << book.genre << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No books found with the given name or writer's name.\n";
    }
}


void clearLibraryData(vector<Book>& library) {
    library.clear();
    ofstream outFile("library_data.txt", ios::trunc);
    if (outFile.is_open()) {
        outFile.close();
        cout << "All previous saved data cleared successfully!\n";
    } else {
        cout << "Error: Unable to clear previous saved data.\n";
    }
}

int main() {
    vector<Book> library;


    loadLibraryData(library);

    while (true) {
        cout << "Library Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Available Books\n";
        cout << "3. Save Library Data\n";
        cout << "4. Search Book by Name or Writer's Name\n";
        cout << "5. Clear All Previous Saved Data\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addBook(library);
            break;
        case 2:
            displayBooks(library);
            break;
        case 3:

            saveLibraryData(library);
            break;
        case 4:

            searchBook(library);
            break;
        case 5:

            clearLibraryData(library);
            break;
        case 6:

            saveLibraryData(library);
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
