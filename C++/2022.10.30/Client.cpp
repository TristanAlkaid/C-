#include <iostream>

using namespace std;

class Client
{
public:
    Client()
    {
        ServerNum++;
    }
    ~Client()
    {
        ServerNum--;
    }
    static void changeServerName(char n);
    static void show();

private:
    static char ServerName;
    static int ServerNum;
};

char Client::ServerName = 'A';
int Client::ServerNum = 0;

void Client::changeServerName(char n)
{
    ServerName = n;
}

void Client::show()
{
    cout << "server name:" << ServerName << endl;
    cout << "num of clients:" << ServerNum << endl;
}

int main()
{
    Client::show();
    Client c1;
    Client::show();
    Client::changeServerName('B');
    Client::show();
    return 0;
}