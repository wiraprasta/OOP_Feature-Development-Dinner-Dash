#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

// Status Pesanan
enum class OrderStatus {
    NotTaken,  // Pesanan belum diambil
    InKitchen, // Pesanan sedang diproses di dapur
    Served     // Pesanan telah disajikan
};

// Kelas Order
class Order {
public:
    Order() : status(OrderStatus::NotTaken) {}

    void setStatus(OrderStatus newStatus) {
        status = newStatus;
    }

    OrderStatus getStatus() const {
        return status;
    }

    std::string getItem() const {
        return "Makanan";
    }

private:
    OrderStatus status;
};

// Kelas CustomerEmotion
class CustomerEmotion {
public:
    CustomerEmotion() : emotionValue(5) {}

    void updateEmotion() {
        // Berkurang setiap detik
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = now - lastUpdateTime;

        if (elapsed.count() >= 1.0) { // Setiap detik
            if (emotionValue > 1) {
                emotionValue--;
            }
            lastUpdateTime = now;
        }
    }

    void setEmotionToMax() {
        emotionValue = 5;
    }

    int getEmotionValue() const {
        return emotionValue;
    }

private:
    int emotionValue;
    std::chrono::steady_clock::time_point lastUpdateTime = std::chrono::steady_clock::now();
};

// Kelas Table
class Table {
public:
    Table(int number, OrderStatus initialStatus) : tableNumber(number) {
        order.setStatus(initialStatus);
    }

    void setOrderStatus(OrderStatus status) {
        order.setStatus(status);
        notifyWaiter();
    }

    void updateCustomerEmotion() {
        emotion.updateEmotion();
    }

    void serveOrder() {
        if (order.getStatus() == OrderStatus::Served) {
            emotion.setEmotionToMax();
            std::cout << "Pesanan telah diantarkan ke meja " << tableNumber << ". Emosi pelanggan diatur ke 5." << std::endl;
        }
    }

    void displayStatus() const {
        std::cout << "Meja: " << tableNumber << std::endl;
        std::cout << "Emosi Pelanggan: " << emotion.getEmotionValue() << std::endl;
        std::cout << "Pesanan: " << order.getItem()
                  << " - Status: " << orderStatusToString(order.getStatus()) << std::endl;
        std::cout << std::endl;
    }

private:
    void notifyWaiter() const {
        if (order.getStatus() == OrderStatus::InKitchen) {
            std::cout << "Notifikasi: Pesanan di meja " << tableNumber << " siap untuk diantar." << std::endl;
        }
    }

    std::string orderStatusToString(OrderStatus status) const {
        switch (status) {
            case OrderStatus::NotTaken: return "Belum Diambil";
            case OrderStatus::InKitchen: return "Di Dapur";
            case OrderStatus::Served: return "Telah Disajikan";
            default: return "Tidak Diketahui";
        }
    }

    Order order;
    CustomerEmotion emotion;
    int tableNumber;
};

// Fungsi Utama
int main() {
    // Membuat 4 meja dengan status pesanan yang berbeda
    std::vector<Table> tables = {
        Table(1, OrderStatus::NotTaken),
        Table(2, OrderStatus::InKitchen),
        Table(3, OrderStatus::Served),
        Table(4, OrderStatus::NotTaken)
    };

    // Menampilkan status awal
    for (auto& table : tables) {
        table.displayStatus();
    }

    // Simulasi proses waktu
    for (int i = 0; i < 60; ++i) {  // Simulasi selama 60 detik
        std::this_thread::sleep_for(std::chrono::seconds(1));
        for (auto& table : tables) {
            table.updateCustomerEmotion();
            if (i == 10) table.setOrderStatus(OrderStatus::InKitchen); // Mengubah status pesanan
            if (i == 20) table.setOrderStatus(OrderStatus::Served); // Mengubah status pesanan
            table.serveOrder(); // Mengatur emosi pelanggan jika pesanan diantarkan
            table.displayStatus();
        }
    }

    return 0;
}
