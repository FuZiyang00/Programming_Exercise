#include <iostream>
#include <string>
#include <vector>
#include <numeric>

class Product {
public:
  std::string name;
  double price;
};

void print(const std::vector<Product> &products) {
  for (const Product &product : products) {
    std::cout << product.name << ":\t$" << product.price << std::endl;
  }
}

int main() {
  // Define a list of products.
  const std::vector<Product> products = {{"Smartphone", 799.99},
                                         {"Laptop", 1299.99},
                                         {"Tablet", 349.99},
                                         {"Headphones", 99.99},
                                         {"Smartwatch", 249.99}};

  std::cout << "List of products:" << std::endl;
  print(products);

  // Compute total cost.
  double total = std::accumulate(products.begin(), products.end(), 0.0,
      [] (double sum, const Product&products) { // Product&products: specifying the type of products 
        return sum+=products.price;
      }
    );
  // Display the total cost
  std::cout << "The total cost is: " << total << std::endl;
  return 0;
}