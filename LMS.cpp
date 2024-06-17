#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Book{
    string title;
    string author;
    int ISBN;
    bool available = true;
};

vector<Book> library;

void addBook(){
    Book newBook;
    cout << "Enter the title of the book: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter the author of the book: ";
    getline(cin, newBook.author);
    cout << "Enter the ISBN of the book: ";
    cin >> newBook.ISBN;
    library.push_back(newBook);
}

void displayBooks(){
    if(library.empty()){
        cout << "No books in the library." << endl;
        return;
    }
    for(auto& book : library){
        cout << "\nTitle: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "ISBN: " << book.ISBN << endl;
        cout << "Available: " << (book.available ? "Yes" : "No") << endl;
    }
}

void searchByTitle(){
    string currentTitle;
    cout << "Enter book title you want to search: ";
    cin.ignore();
    getline(cin, currentTitle);
    bool found = false;
    for(auto& book : library){
        if(currentTitle == book.title){
            cout << "Book found!" << endl;
            cout << "Book Title: " << book.title << "\nAuthor: " << book.author << "\nISBN: " << book.ISBN << endl;
            found = true;
        }
    }
    if (!found){
        cout << "Book not found!" << endl;
    }
}

void searchByAuthor(){
    string currentAuthor;
    cout << "Enter book author you want to search: ";
    cin.ignore();
    getline(cin, currentAuthor);
    bool found = false;
    for(auto& book : library){
        if(currentAuthor == book.author){
            cout << "\nBook found!" << endl;
            cout << "Book Title: " << book.title << "\nAuthor: " << book.author << "\nISBN: " << book.ISBN << endl;
            found = true;
        }
    }
    if (!found){
        cout << "Book not found!" << endl;
    }
}

void searchByISBN(){
    int currentISBN;
    cout << "Enter book ISBN you want to search: ";
    cin >> currentISBN;
    bool found = false;
    for(auto& book : library){
        if(currentISBN == book.ISBN){
            cout << "Book found!" << endl;
            cout << "Book Title: " << book.title << "\nAuthor: " << book.author << "\nISBN: " << book.ISBN << endl;
            found = true;
        }
    }
    if (!found){
        cout << "Book not found!" << endl;
    }
}

void searchBy(){
    int ch;
    cout<< "-----------------------" << endl;
    cout << "Search book by: \n1)Title\n2)Author\n3)ISBN\n4)Exit Search Operation" << endl;
    cout<< "-----------------------";
    do{
        cout << "\nEnter the constraint by which you want to search the book: ";
        cin >> ch;
        switch(ch){
            case 1:
                searchByTitle();
                break;
            case 2:
                searchByAuthor();
                break;
            case 3:
                searchByISBN();
                break;
            case 4:
                cout << "Exiting search.." << endl;
                break;
            default:
                cout << "Invalid Choice. Enter number between (1-4): ";
        }
    }while(ch != 4);
}

void checkOutBook(){
    string title;
    cout << "Enter the title of the book you want to borrow: ";
    cin.ignore();
    getline(cin, title);
    
    for(auto& book : library){
        if(book.title == title){
            if(book.available){
                book.available = false;
                cout << "You have borrowed '" << book.title << "'." << endl;
                return;
            } else {
                cout << "Book already borrowed." << endl;
                return;
            }
        }
    }
    cout << "Book not found." << endl;
}

void returnBook(){
    int days;
    string title;
    cout << "Enter the title of the book you want to return: ";
    cin.ignore();
    getline(cin, title);
    cout<<"Enter the number of days: ";
    cin>>days;
    int overDue=days-15;
    if(days<15){
        cout << "Book returned successfully";
    }
    
    else  if(days>=15 && days<=30)
    {
        cout << "\nPer Day Fine Amount is : Rs 2";
        cout << "\nYou are late by " << overDue << " day/days";
        cout << "\nTotal Fine Amount is : "<<overDue*2 << endl;
    }
    else
    {
        cout<<"\nMembership will be cancelled.";
    }
}

int main(){
    int choice;
    cout << "----LIBRARY MANAGEMENT SYSTEM----\n";
    cout << "1. Add Book\n2. Display Books\n3. Search Book\n4. Borrow Book\n5. Return Book\n6. Exit" << endl;
    cout << "---------------------------------";
    do{
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                addBook();
                break;
            case 2:   
                displayBooks();
                break;
            case 3:
                searchBy();
                break;
            case 4:
                checkOutBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Enter a valid number (1-6): ";
        }
    }while(choice != 6);    
    return 0;
}