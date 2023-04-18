#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define MAX_CLIENTS 10
#define PORT 8080

using namespace std;

int main(){

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address and port
    if(bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(sockfd, MAX_CLIENTS) < 0){
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    cout << "Server listening on port " << PORT << endl;

    while(true){
        // Accept an incoming connection
        int clientfd = accept(sockfd, NULL, NULL);

        if(clientfd < 0){
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Send data to client
        const char *message = "Hello from server!";
        send(clientfd, message, strlen(message), 0);

        close(clientfd);
    }

    close(sockfd);

    return 0;
}

