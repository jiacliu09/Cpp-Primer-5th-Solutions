#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;
#include <string>
using std::string;
#include <memory>
using std::shared_ptr; using std::make_shared;

struct destination;
struct connection;

connection connect(destination *);

void disconnect(connection);

void end_connection(connection *p){ disconnect(*p);}

void f(destination &d /*其它参数*/){
    connection c = connect(&d);
    shared_ptr<connection>p(&c, [](connection *p){disconnect(*p);});
    //使用连接
    //当f退出时（即使是由于异常），connection会被正确关闭
}

int main() {
}