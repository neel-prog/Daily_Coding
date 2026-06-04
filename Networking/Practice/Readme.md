Cisco Packet Tracer Network Simulation using DHCP and Static Routing
Overview

This project demonstrates the implementation of a basic network topology in Cisco Packet Tracer using DHCP (Dynamic Host Configuration Protocol) and Static Routing. The network consists of multiple LANs connected through routers, allowing devices on different networks to communicate with each other.

Objectives
Configure IP addressing for multiple networks.
Implement DHCP to automatically assign IP addresses to hosts.
Configure Static Routing using the ip route command.
Verify end-to-end connectivity between devices.
Technologies Used
Cisco Packet Tracer
DHCP
Static Routing
IPv4 Addressing
Network Topology

The network contains:

Multiple routers
Switches
PCs/End Devices
Separate LAN segments

(Insert a screenshot of your network topology here)

Features
Automatic IP address assignment using DHCP.
Inter-network communication through static routes.
Basic network troubleshooting and connectivity testing.
Verification using ping commands.
Configuration Summary
DHCP Configuration
DHCP pools were created to assign:
IP Address
Subnet Mask
Default Gateway
DNS Server (if configured)
Static Routing

Static routes were configured on routers using:

ip route <destination-network> <subnet-mask> <next-hop-ip>

Example:

ip route 192.168.2.0 255.255.255.0 10.0.0.2
Testing

Connectivity was verified by:

Obtaining IP addresses via DHCP.
Checking assigned addresses using:
ipconfig
Testing communication between different networks using:
ping <destination-ip>
Learning Outcomes
Understanding of DHCP configuration and operation.
Hands-on experience with static routing.
Knowledge of IP addressing and subnetting.
Basic network design and troubleshooting skills.
Future Improvements
Implement dynamic routing protocols such as RIP, OSPF, or EIGRP.
Add VLANs and Inter-VLAN Routing.
Configure network security features such as ACLs.
Introduce redundancy and failover mechanisms.