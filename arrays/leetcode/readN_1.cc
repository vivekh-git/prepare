#include <bits/stdc++.h>
using namespace std;

int read4(char *buf);

// works in leetcode
int read(char *buf, int n) {
       char internal_buffer[4]; int buffersize = 0; //  make these static for repeat calls
       int internal_buffer_ptr = 0; // make these static for repeat calls
       
       int count_of_bytes_read = 0; // if count_of_bytes reaches n, - we can return
       while (count_of_bytes_read < n) {
           // if there is somethign in internal buffer - first use that.
           if (internal_buffer_ptr != buffersize) {
               buf[count_of_bytes_read++] = internal_buffer[internal_buffer_ptr++];
           }
           else {
               // internal buffer empty
               int sub = read4(internal_buffer);
               if (sub == 0)
                   return count_of_bytes_read;
               buffersize = sub;
               internal_buffer_ptr = 0;
           }
       }
       return count_of_bytes_read;
}