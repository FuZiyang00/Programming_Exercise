#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Book {
public:
  std::string title;
  std::string author;
  std::string genre;
  unsigned int publication_year;
};

void print(const std::vector<Book> &books) {
  for (const Book &book : books) {
    std::cout << "  Title: " << book.title << " | Author: " << book.author
              << " | Genre: " << book.genre
              << " | Year: " << book.publication_year << std::endl;
  }
}

// Comparison function
bool compareByPrice(const Book& a, const Book& b) {
    return a.publication_year < b.publication_year;
}

// Functor class for sorting by author name 
class SortByAuthor{
  public:
    bool operator () (const Book& a, const Book& b) {return a.author<b.author;}
};




int main() {
  // Define a list of books.
  std::vector<Book> books = {
      {"Go set a watchman", "Harper Lee", "Fiction", 2015},
      {"Animal farm", "George Orwell", "Satire", 1945},
      {"To kill a mockingbird", "Harper Lee", "Fiction", 1960},
      {"1984", "George Orwell", "Science fiction", 1949},
      {"Pride and prejudice", "Jane Austen", "Romance", 1813},
      {"Sense and sensibility", "Jane Austen", "Romance", 1811}};

  std::cout << "Original list of books:" << std::endl;
  print(books);

  // Sort in ascending order by year. use function pointer
  bool (*ascending_sorter) (const Book& , const Book& ) = compareByPrice; // pointer to compareByPrice function
  std::sort(books.begin(), books.end(), ascending_sorter);
  std::cout << std::endl
            << "Books sorted in ascending order by year:" << std::endl;
  print(books);


  // Sort in descending order by year. use lambda
  std::sort(books.begin(), books.end(), 
            [] (const Book& a, const Book& b) { 
        return a.publication_year > b.publication_year;
      }
    );
  std::cout << std::endl
            << "Books sorted in descending order by year:" << std::endl;
  print(books);


  // Sort in ascending order by author name. use functor
  SortByAuthor sort{};
  std::sort(books.begin(), books.end(), sort);
  std::cout << std::endl
            << "Books sorted by author:" << std::endl;
  print(books);

  // Filter books by author. lambdas
  std::vector<Book> filtered_books; 
  std::string author_name = "George Orwell";
  std::copy_if(books.begin(), books.end(), std::back_inserter(filtered_books),
                 [author_name](const Book &books) { return books.author == author_name;});
  
  if (filtered_books.empty()) {
    std::cout << std::endl
              << "No books by " << author_name << " found." << std::endl;
  } else {
    std::cout << std::endl
              << "Books by " << author_name << ":" << std::endl;
    print(filtered_books);
  }
  

  return 0;
}