#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<linux/ip.h>
#include<linux/icmp.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include"pcap.h"

int main(void)
{
  /* Allocate a buffer large enough to hold IP and ICMP header */

  char * packet = (char*)malloc(sizeof(struct iphdr) + sizeof(struct icmphdr));



  /* Declare pointers to appropriately offset IP and ICMP headers */

  struct iphdr* ip = (struct iphdr*)packet;

  struct icmphdr* icmp = (struct icmphdr*)(packet + sizeof(struct iphdr));
 
  

  /* Populate the headers with data */

  ip->ihl = 5;
  ip->version = 4;
  ip->tos = 16;
  ip->tot_len=sizeof(struct icmphdr)+ sizeof(struct iphdr);
  ip->id = 1;
  ip->frag_off = 1;
  ip->ttl = 5;
  ip->protocol = 1;
  ip->check = in_checksum((unsigned short*) ip, sizeof(struct iphdr));
  ip->saddr = inet_addr("192.168.10.10");
  ip->daddr = inet_addr("192.168.10.255");


  icmp->checksum = in_checksum((unsigned short*) ip, sizeof(struct icmphdr));
  icmp->type = 8;

  

  

  /* Write the buffer to file using write_pcap() */

  write_pcap("packet", packet, sizeof(struct iphdr)+ sizeof(struct icmphdr));

  /* Free dynamic memory */

  free(packet);
  
  return EXIT_SUCCESS;
}
