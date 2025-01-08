#include <iostream>
#include <mysql/mysql.h>
#include <string>

using namespace std;

class sql_connection_pool
{
private:
    /* data */
    string url;
    int port;
    string dbName;
    string user;
    string password;
    int maxConnection;
    //私有化构造函数
    sql_connection_pool(/* args */);
    ~sql_connection_pool();

    
public:
    //单例子实现
    static sql_connection_pool getInstance();
    //初始化数据库连接池
    void init(string url, string User, string PassWord, string DataBaseName, int Port, int MaxConn, int close_log); 
    //获取数据库链接
    MYSQL *getConnection();
    //释放链接
    bool releaseConnection(MYSQL *conn);
    //获取链接
    int getFreeConn();
    //销毁所有链接
    void destroyPool();
};
