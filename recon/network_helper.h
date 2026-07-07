#define ETHER_ADDR_LEN 6
#define ETHER_HDR_LEN 14

// Dump raw mem in hex byte and printable split format
void dump(const unsigned char *data_buffer, const unsigned int length) {
  unsigned char byte;
  unsigned int i, j;
  for(i=0; i < length; i++) {
    byte = data_buffer[i];
      printf("%02x ", data_buffer[i]); //display byte in hex
    if(((i%16)==15) || (i==length)) {
      for(j=0; j < 15-(i%16); j++)
        printf("  ");
      printf("| ");
      for(j=(i-(i%16)); j <= i; j++) { // display printable bytes from line
        byte = data_buffer[j];
        if((byte > 31) && (byte < 127)) //outside printable char range
          printf("%c", byte);
        else
          printf(".");
      }
    printf(("\n"); //end dump. Each line should be 16 bytes
    }
  }
}


struct ether_hdr {
  unsigned char ether_dest_addr[ETHER_ADDR_LEN]; //dest MAC addr
  usigned char ether_src_addr[ETHER_ADDR_LEN]; // src mac
  unsigned short ether_type; //type of ethernet packet
}

struct ip_hdr {
  unsigned char ip_version_and_header_length;
  unsigned char ip_tos;
  unsigned short ip_len;
  unsigned short ip_id; 
  unsigned short ip_frag_offset;  //fragment offset and flags
  unsigned char ip_ttl;
  unsigned char ip_type; //protocol type
  unsigned short ip_checksum;
  unsigned int ip_src_addr;
  unsigned int ip_dest_addr;
}

struct tcp_hdr {
  unsigned short tcp_src_port;
  unsigned short tcp_dest_port;
  unsigned int tcp_seq; //TCP sequence num
  unsigned int tcp_ack; //TCP Ack num
  unsigned char reserved:4; // 4 bits from the 6 buts of reserved space
  unsigned char tcp_offset;
  unsigned char tcp_flags;
#define TCP_FIN 0x01
#define TCP_SYN 0x02
#define TCP_RST 0x04
#define TCP_PUSH 0x08
#define TCP_ACK 0x10
#define TCP_URG 0x20
  unsigned short tcp_window;
  unsigned short tcp_checksum;
  unsigned short tcp_urgent; //tcp urgent pointer
}
