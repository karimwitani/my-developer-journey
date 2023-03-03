# Computer Science

- [Computer Science](#computer-science)
  - [Networking](#networking)
    - [*What is DHCP ?*](#what-is-dhcp-)
  - [Basic Concepts](#basic-concepts)
    - [*What is kerberos?*](#what-is-kerberos)
    - [what is the difference between the heap memory and the call stack?](#what-is-the-difference-between-the-heap-memory-and-the-call-stack)
    - [*What is NAT?*](#what-is-nat)
    - [*What is IDPS?*](#what-is-idps)
    - [*What is a firewall?*](#what-is-a-firewall)
    - [*What is NTLM?*](#what-is-ntlm)
    - [*What is SSL?*](#what-is-ssl)
      - [*What is SSL termination?*](#what-is-ssl-termination)
    - [*What is the difference betwen in and outbound http traffic?*](#what-is-the-difference-betwen-in-and-outbound-http-traffic)
    - [*What is Outbound Source Network Address Translation?*](#what-is-outbound-source-network-address-translation)
    - [*What is Destination Network Address Translation (DNAT)?*](#what-is-destination-network-address-translation-dnat)
    - [*What is VPN forced tunneling?*](#what-is-vpn-forced-tunneling)
    - [*What is the OSI model?*](#what-is-the-osi-model)
    - [What is thread safety?](#what-is-thread-safety)
    - [How do SSL signatures secure HTTPS traffic?](#how-do-ssl-signatures-secure-https-traffic)
    - [What is SMB 3.0](#what-is-smb-30)

## Networking

### *What is DHCP ?*

## Basic Concepts

### *What is kerberos?*

### what is the difference between the heap memory and the call stack?

### *What is NAT?*

### *What is IDPS?*

### *What is a firewall?*

- what is the address space?
- what is forced tunneling?
- what is a route table?

### *What is NTLM?*

### *What is SSL?*

#### *What is SSL termination?*

### *What is the difference betwen in and outbound http traffic?*

### *What is Outbound Source Network Address Translation?*

### *What is Destination Network Address Translation (DNAT)?*

### *What is VPN forced tunneling?*

### *What is the OSI model?*

### What is thread safety?

### How do SSL signatures secure HTTPS traffic?

When a client (browser) first requests a website using https, the web server include in the data that it sends to the
user two things:

1- The website's SSL certificate, which contains a public key of the web server.
2- A digital signature. It's a hash of the of the SSL certificate, generated using the private key of teh certificate
authority (CA)

The user/browser uses the CA's public key to decrypt the signature and verify its authenticity.

Once trust is established the user will use the web server's public key (contained in the SSL certificate) to encrypt
all data that it transmists back to the server. This way the data cannot be read by any third party if it's intercepted
as its being routed back to the web server

### What is SMB 3.0

Server Message Block 3.0 (SMB 3.0) is a network protocol used for file sharing. It is designed for relliability and security:

It improves upon previous versions with a few features:

- End to End encryption
- Failover and resilience: It can switch between redundant servers in case of failure without interuppting access to the
  shared files
- Performance: Larger max buffer sizes, improvoed caching and reced latency
- Scalibility: Allows for more simoultaneous reads on the same files
- Directory leasing: Caching of directory metadata on the client side allows for faster access

