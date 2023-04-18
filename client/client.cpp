#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define PORT 8080

using namespace std;

int main(){

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // sockaddr_in structure for server address
    sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0){
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        perror("Connect failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024] = {0};

    // Read data from server
    int valread = read(sockfd, buffer, 1024);

    cout << buffer << endl;

    close(sockfd);

    return 0;
}
