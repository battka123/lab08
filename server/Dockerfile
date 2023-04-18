FROM ubuntu:latest
RUN apt-get update && \
    apt-get install  -y g++ && \
    g++ -o server server.cpp
WORKDIR /app
COPY server.cpp /app/server.cpp
RUN mkdir build && cd build && cmake .. && make
EXPOSE 8080
CMD ["./server"]
