/*
 ============================================================================
 Name        : Simple Database In C
 Author      : Gabriel Adelemoni
 Version     : 1.0
 Description : A simple C application demonstrating project structure with
               src, include, Makefile-based build system, and modular design.
               Uses static libraries and includes dependency management.
 License     : MIT
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  char* buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

InputBuffer* input_buffer;

void _setup() 
{
  input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;
}

void read_input() 
{
  ssize_t bytes_read =getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

  if (bytes_read <= 0) 
  {
    printf("Error reading input\n");
    exit(EXIT_FAILURE);
  }

  // Ignore trailing newlineinput_buffer->input_length = bytes_read - 1;
  input_buffer->buffer[bytes_read - 1] = 0;
}

int main()
{
  _setup();
  while (true) 
  {
    printf("db > ");
    read_input();

    if (strcmp(input_buffer->buffer, ".exit") == 0) exit(EXIT_SUCCESS);
    else printf("Unrecognized command '%s'.\n", input_buffer->buffer);
  }
}
