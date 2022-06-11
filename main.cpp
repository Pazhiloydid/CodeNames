#include <iostream>
#include <boost/asio.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;

    boost::asio::ip::tcp::iostream stream("google.com", "http");
    stream << "GET /ip HTTP/1.1\r\nHost: google.com\r\nConnection: closer\n\r\n";
    std::cout << stream.rdbuf();
    return 0;
}
