FROM ubuntu:latest
RUN apt-get update && \
    apt-get install  -y g++ && \
    g++ -o client client.cpp
WORKDIR /app
COPY client.cpp /app/client.cpp
RUN mkdir build && cd build && cmake .. && make
EXPOSE 8080
CMD ["./client"]
