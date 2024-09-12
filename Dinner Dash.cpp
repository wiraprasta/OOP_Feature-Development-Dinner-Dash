#include <iostream>
#include <vector>
#include <string>

// Enum for order statuses
enum class OrderStatus {
    NotYetTaken,
    InKitchen,
    Served
};

// Class representing an Order
class Order {
public:
    Order(int id, OrderStatus status)
        : id(id), status(status) {}

    int getId() const { return id; }
    OrderStatus getStatus() const { return status; }
    void setStatus(OrderStatus newStatus) { status = newStatus; }

    std::string statusToString() const {
        switch (status) {
            case OrderStatus::NotYetTaken: return "Not Yet Taken";
            case OrderStatus::InKitchen: return "In Kitchen";
            case OrderStatus::Served: return "Served";
            default: return "Unknown Status";
        }
    }

private:
    int id;
    OrderStatus status;
};

// Class representing a Table
class Table {
public:
    Table(int number) : number(number) {}

    void addOrder(const Order& order) {
        orders.push_back(order);
    }

    void updateOrderStatus(int orderId, OrderStatus newStatus) {
        for (auto& order : orders) {
            if (order.getId() == orderId) {
                order.setStatus(newStatus);
                break;
            }
        }
    }

    void displayOrders() const {
        std::cout << "Table " << number << " Orders:\n";
        for (const auto& order : orders) {
            std::cout << "Order ID: " << order.getId()
                      << " - Status: " << order.statusToString() << '\n';
        }
    }

private:
    int number;
    std::vector<Order> orders;
};

// Main function for demonstration
int main() {
    // Create some tables
    Table table1(1);
    Table table2(2);

    // Add orders to table 1
    table1.addOrder(Order(101, OrderStatus::NotYetTaken));
    table1.addOrder(Order(102, OrderStatus::InKitchen));

    // Add orders to table 2
    table2.addOrder(Order(201, OrderStatus::Served));
    table2.addOrder(Order(202, OrderStatus::NotYetTaken));

    // Display orders
    table1.displayOrders();
    table2.displayOrders();

    // Update order status
    table1.updateOrderStatus(101, OrderStatus::InKitchen);

    // Display updated orders
    std::cout << "\nAfter updating order status:\n";
    table1.displayOrders();

    return 0;
}
