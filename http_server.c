#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>


int main() {
  //declare the file object to hold data
  FILE *html_data;
  html_data = fopen("index.html", "r");
  
  //hold response data
  char response_data[1024];
  fgets(response_data, 1024, html_data);
  
  
  //
  char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
  //concat the response header and body
  
  strcat(http_header, response_data);
  
  //create a scoket
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0)
  
  //DEFINE THE ADDRESS
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8001);
  server_address.sind_addr.s_addr = INADDR_ANY;
  
  bind(server_socket, ( struct sockaddr *) &server_address, sizeof(server_address));
  
  listen(server_socket, 5)
  
  int client_socket;
  while(1) {
    client_socket = accept(server_socket, NULL, NULL);
    send(client_socket, http_header, sizeof(http_header), 0);
    close(client_socket);
  }
  
  
  return 0;
}
